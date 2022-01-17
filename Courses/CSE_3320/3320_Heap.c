#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#define ALIGN4(s) (((((s)-1) >> 2) << 2) + 4)
#define BLOCK_DATA(b) ((b) + 1)
#define BLOCK_HEADER(ptr) ((struct _block *)(ptr)-1)

static int atexit_registered = 0;
static int num_mallocs = 0;
static int num_frees = 0;
static int num_reuses = 0;
static int num_grows = 0;
static int num_splits = 0;
static int num_coalesces = 0;
static int num_blocks = 0;
static int num_requested = 0;
static int max_heap = 0;

/*
 *  \brief printStatistics
 *
 *  \param none
 *
 *  Prints the heap statistics upon process exit.  Registered
 *  via atexit()
 *
 *  \return none
 */

void printStatistics(void)
{
   printf("\nheap management statistics\n");
   printf("mallocs:\t%d\n", num_mallocs);
   printf("frees:\t\t%d\n", num_frees);
   printf("reuses:\t\t%d\n", num_reuses);
   printf("grows:\t\t%d\n", num_grows);
   printf("splits:\t\t%d\n", num_splits);
   printf("coalesces:\t%d\n", num_coalesces);
   printf("blocks:\t\t%d\n", num_blocks);
   printf("requested:\t%d\n", num_requested);
   printf("max heap:\t%d\n", max_heap);
}

struct _block
{
   size_t size;         /* Size of the allocated _block of memory in bytes */
   struct _block *prev; /* Pointer to the previous _block of allcated memory   */
   struct _block *next; /* Pointer to the next _block of allcated memory   */
   bool free;           /* Is this _block free?                     */
   char padding[3];
};

struct _block *heapList = NULL; /* Free list to track the _blocks available */

/*
 * \brief findFreeBlock
 *
 * \param last pointer to the linked list of free _blocks
 * \param size size of the _block needed in bytes 
 *
 * \return a _block that fits the request or NULL if no free _block matches
 *
 * \TODO Implement Next Fit
 * \TODO Implement Best Fit
 * \TODO Implement Worst Fit
 */
struct _block *findFreeBlock(struct _block **last, size_t size)
{
   struct _block *curr = heapList;

#if defined FIT && FIT == 0
   /* First fit */
   while (curr && !(curr->free && curr->size >= size))
   {
      *last = curr;
      curr = curr->next;
   }
#endif

#if defined BEST && BEST == 0
   /* Best fit */
   struct _block *storeptr = NULL;
   int diffsize;
   int maxsize = INT_MAX;
   while (curr)
   {
      *last = curr;
      //Checking if the current pointed block is free
      if (curr->free)
      {
         //if the block is free and greater than size requested
         if (curr->size >= size)
         {
            diffsize = curr->size - size;
            //finding a enough free block to satisfy request
            //if current free block is smaller than saved block
            //storing the current pointer to storeptr
            if (diffsize <= maxsize)
            {
               maxsize = diffsize;
               storeptr = curr;
            }
         }
      }
      curr = curr->next;
   }

   //restoring the data in curr pointer
   if (storeptr)
   {
      curr = storeptr;
   }

#endif

#if defined WORST && WORST == 0
   /* Worst fit */
   struct _block *storeptr = NULL;
   int diffsize;
   int minsize = INT_MIN;
   while (curr)
   {
      *last = curr;
      if (curr->free)
      {
         //Checking if the current pointed block is free
         if (curr->size >= size)
         {
            //finding a enough free block to satisfy request
            diffsize = curr->size - size;
            // if current free block is larger than saved block
            //storing the current pointer to storeptr
            if (diffsize > minsize)
            {
               minsize = diffsize;
               storeptr = curr;
            }
         }
      }

      curr = curr->next;
   }

   //restoring the data in curr pointer
   if (storeptr)
   {
      curr = storeptr;
   }
#endif

#if defined NEXT && NEXT == 0
   /* Next fit */
   *last = curr;

   //checking from last used block
   if (*last)
   {
      curr = *last;
      curr = curr->next;
   }
   // if not setting to beginning to end, as first fit
   while (curr && !(curr->free && curr->size >= size))
   {
      *last = curr;
      curr = curr->next;
   }

#endif

   return curr;
}

/*
 * \brief growheap
 *
 * Given a requested size of memory, use sbrk() to dynamically 
 * increase the data segment of the calling process.  Updates
 * the free list with the newly allocated memory.
 *
 * \param last tail of the free _block list
 * \param size size in bytes to request from the OS
 *
 * \return returns the newly allocated _block of NULL if failed
 */
struct _block *growHeap(struct _block *last, size_t size)
{
   /* Request more space from OS */
   struct _block *curr = (struct _block *)sbrk(0);
   struct _block *prev = (struct _block *)sbrk(sizeof(struct _block) + size);

   assert(curr == prev);

   /* OS allocation failed */
   if (curr == (struct _block *)-1)
   {
      return NULL;
   }

   /* Update heapList if not set */
   if (heapList == NULL)
   {
      heapList = curr;
   }

   /* Attach new _block to prev _block */
   if (last)
   {
      last->next = curr;
   }

   /* Update _block metadata */
   curr->size = size;
   curr->next = NULL;
   curr->free = false;
   return curr;
}

/*
 * \brief malloc
 *
 * finds a free _block of heap memory for the calling process.
 * if there is no free _block that satisfies the request then grows the 
 * heap and returns a new _block
 *
 * \param size size of the requested memory in bytes
 *
 * \return returns the requested memory allocation to the calling process 
 * or NULL if failed
 */

void *malloc(size_t size)
{

   if (atexit_registered == 0)
   {
      atexit_registered = 1;
      atexit(printStatistics);
   }

   /* Align to multiple of 4 */
   size = ALIGN4(size);

   /* Handle 0 size */
   if (size == 0)
   {
      return NULL;
   }

   //counting the number of times the user calls malloc successfully
   num_mallocs++;

   /* Look for free _block */
   struct _block *last = heapList;
   struct _block *next = findFreeBlock(&last, size);
   //counting the total amount of memory requested
   num_requested += size;

   if (next != NULL)
   {
      //finding if free block is larger than the requested size
      // if the block is free and larger then splitting the block
      if ((next->size - size) > size)
      {
         //saving old size of a block to storesize
         int storesize = next->size;
         //saving the pointer
         struct _block *old_next = next->next;
         // casting gives the total size of the block
         uint8_t *newptr = (uint8_t *)next + next->size + sizeof(struct _block);
         // the pointer points to next block
         next->next = (struct _block *)(newptr);
         next->size = size;
         int diff = storesize - size - sizeof(struct _block);
         next->next->size = diff;
         next->next->next = old_next;
         next->next->free = true;

         //count the number of splits
         //count the number of blocks after splitting
         num_splits++;
         num_blocks++;
      }
   }

   /* Could not find free _block, so grow heap */
   if (next == NULL)
   {
      next = growHeap(last, size);
      //counting the number of times for requesting a new block
      num_grows++;

      //counting the number of times for requesting a new block
      max_heap += size;

      //number of block increases as heap grows
      num_blocks++;
   }


   /* Could not find free _block or grow heap, so just return NULL */
   if (next == NULL)
   {
      return NULL;
   }
   
     else
   {
      //counting the number of times the existing block is reused
      num_reuses++;
   }

   /* Mark _block as in use */
   next->free = false;

   /* Return data address associated with _block */
   return BLOCK_DATA(next);
}

void *calloc(size_t nmemb, size_t size)
{
   //allocates the requested memory, nmemb gets allocated
   //set allocated memory to 0
   void *ptr = malloc(nmemb * size);
   memset(ptr, 0, nmemb * size);
   return ptr;
}

//takes the pointer and the new size
void *realloc(void *ptr, size_t size)
{
   void *newptr = malloc(size);
   memcpy(newptr, ptr, size);
   return newptr; //returns pointer with all the data copied over
}

/*
 * \brief free
 *
 * frees the memory _block pointed to by pointer. if the _block is adjacent
 * to another _block then coalesces (combines) them
 *
 * \param ptr the heap memory to free
 *
 * \return none
 */
void free(void *ptr)
{
   if (ptr == NULL)
   {
      return;
   }

   /* Make _block as free */
   struct _block *curr = BLOCK_HEADER(ptr);
   assert(curr->free == 0);
   curr->free = true;

   /* TODO: Coalesce free _blocks if needed */

   struct _block *store = heapList;

   while (store)
   {
      // checking if the current block is free
      if (store != NULL && store->free)
      {
         if ((store->next != NULL) && store->next->free)
         {
            //combining two adjacent blocks if they are free
            store->size = store->size + sizeof(struct _block) + store->next->size;
            store->next = store->next->next;
            //counting the number when combining of block takes place
            //decreasing the number of blocks after each combination
            num_coalesces++;
            num_blocks--;
         }
      }
      store = store->next;

#if 0

#endif
   }

   //counting the number of times the user calls free successfully
   num_frees++;
   
  
}