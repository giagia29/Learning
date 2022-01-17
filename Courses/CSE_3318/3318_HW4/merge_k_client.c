#include <stdlib.h>
#include <stdio.h>

#include "merge_k.h"   // heap.h includes list.h


void read_k_lists(int k, nodePT arrL[k], FILE* fp) {
   int i,N;
   printf("Reading %d lists in the format: list size (N) and then N integers", k);
   for (i = 0; i<k; i++) {
      fscanf(fp, "%d", &N);
      nodePT L = build_list_N(N, fp);
      arrL[i] = L; // copy memory address stored in L;
      print_list_pointer(L); // check list was read correctly
   }
}


int main()   {
   int k,i;
   char fname[501];
   printf("Enter a filename: ");
   scanf("%s", fname);
   FILE* fp = fopen(fname, "r");
   if (fp == NULL) {
	   printf("FIle failed to open. Exit.\n");
	   return 0;
   }
   //read the number of lists, k 
   fscanf(fp, "%d", &k);
   
   nodePT heap[k];
   read_k_lists(k, heap, fp);
   fclose(fp);
   
   printf("\n\nSorting each linked list: \n");
   for(i=0; i<k; i++){
      print_list_pointer(heap[i]);
      heap[i] = sort_list(heap[i]);
      printf("Sorted list:");
      print_list_pointer(heap[i]);
   }
   

   printf("\nConstructing the Heap (turns the array into a heap using bottom up) ...\n");
   make_heap(k, heap);

   printf("\nMerging ...\n");   
   nodePT sorted = merge_k(k, heap);

   printf("\n\nSorted result list is:");   
   print_list_pointer(sorted);
   destroy_list(sorted);   
  
   
   return 0;
}