/*
Name: Gia Dao
Student ID: 1001747062
*/

#include <stdlib.h>
#include <stdio.h>


#include "merge_k.h" 
#include "list.h"

/*  Sorts linked list L in pace using insertion sort. 
*/
nodePT sort_list(nodePT L){
	// implement insertion sort for linked list
	nodePT head = malloc(sizeof(struct node));
	nodePT temp = NULL;
	head->next = L;
	nodePT curr = L;
	nodePT prev = head;
	while(curr != NULL)
	{
		if(curr->next != NULL && (curr->next->data < curr->data))
		{
			while(prev->next != NULL && (prev->next->data < curr->next->data))
			{
				prev = prev->next;
			}
			temp = prev->next;
			prev->next = curr->next;
			curr->next = curr->next->next;
			prev->next->next = temp;
			prev = head;
		}
		else
		{
			curr = curr->next;
		}
	}
	return head->next;
}

/* It is recommended to implement a sinkDown function in this file. 
You can declare its header at the top of this file (after include) 
write the implementation anywhere in this file. 
(You cannot modify any of the list.h or merge_k.h files) 
*/

int idxOfMinValue(int* A, int i, int left, int right, int k)
{
	int imv = i;
	if( (left < k) && (A[left] < A[imv]) )
	{
		imv = left;
	}
	if( (right < k) && (A[right] < A[imv]) )
	{
		imv = right;
	}
	return imv;
}

void min_heapify(int* A, int i, int k, nodePT heap[k])
{
	int temp;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	nodePT mid = NULL;
	int imv = idxOfMinValue(A, i, left, right, k);
	while( (imv != i) && (imv < k) )
	{
		temp = A[imv];
		A[imv] = A[i];
		A[i] = temp;
		mid = heap[imv];
		heap[imv] = heap[i];
		heap[i] = mid;
		i = imv;
		left = (2 * i) + 1;
		right = (2 * i) + 2;
		imv = idxOfMinValue(A, i, left, right, k);
	}
}


void buildMinHeap(int* A, int k, nodePT heap[k])
{
	int i;
	for(i = k / 2; i >= 0; i--)
	{
		min_heapify(A, i, k, heap);
	}

}

/* Turns the given array (named heap) into an actual Min-Heap
   using the bottom-up method to build the heap. 
   (See buidMaxHeap pseudocode in slides)
*/
void make_heap(int k, nodePT heap[k]){
	// write your code in here
	
	int i, min_heap[k];
	
	int* min_ptr;
	nodePT head = NULL;
	nodePT dm = NULL;
	
	printf("\n");
	int t = 0;
	int* ptr = &t;
	while(k > 0)
	{	
		while(heap[t] != NULL)
		{
			printf("\nELEMENT INSIDE MIN-HEAP: ");
			for(i = 0; i < k; i++)
			{	
				min_heap[i] = heap[i]->data;
				printf("%d ", min_heap[i]);
			}
			printf("\n");
			min_ptr = min_heap;
			
			printf("REARRANGE HEAP:\n\n");	
			buildMinHeap(min_ptr, k, heap);

			for(i = 0; i < k; i++)
			{
				printf("HEAP AT %d: %p\n", t + i, heap[i]);
			}


			for(i = 0; i < k; i++)
			{
				print_list_pointer(heap[i]);
			}

			nodePT mer = merge_k(k, heap);

			if(head == NULL)
			{
				head = mer;
				dm = head;
			}
			else
			{
				head->next = mer;
				head = mer;
			}
				
			nodePT temp = remove_min(ptr, heap);
			
			
			if(heap[t] == NULL)
			{
				for(i = 0; i < k - 1; i++)
				{
					heap[*ptr + i] = heap[*ptr + i + 1];
				}
				break;
			}			
		}
		k--;
	}

	print_list_pointer(dm);
	destroy_list(dm);
}



/*  heap is a Min-Heap of linked lists
	remove_min will remove AND RETURN the first node of the list at index 0.
	k (size of heap) will only change when that removal leaves that list empty.
*/
nodePT remove_min(int* k, nodePT heap[(*k)]){
	nodePT prev = heap[*k];
	heap[*k] = heap[*k]->next;
	prev->next = NULL;
   	return prev;
}


/*
   heap is a Min-Heap array of SORTED single linked lists. 
   Merging process: 
	- use the heap to identify and remove the node, np, with the smallest data out 
      of the k lists.
	- insert np at the end of result list.

   Returns: a sorted single linked list built by merging the k lists.
*/
nodePT merge_k(int k, nodePT heap[k]){
	if(k == 0)
	{
		printf("EMPTY HEAP. NO REMOVE PERFORMED\n\n");
		return NULL;
	}
	else
	{
		nodePT prev = heap[0];
		return prev;
	}
	// Replace the place holder code with the correct code
   	//return NULL;   // place holder code
}
