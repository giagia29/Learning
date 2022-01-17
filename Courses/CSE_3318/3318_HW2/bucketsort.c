/*
	Name: Gia Dao.
	Student ID: 1001747062.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "list.h"

void print_init(int arr[], int N)
{
	int i;
	printf("\n array:");
	for (i = 0; i < N; i++)
	{
		printf("%5d,", arr[i]);
	}
	printf("\n");
}

void SelectionSort(nodePT List)
{
	nodePT i = NULL;
	nodePT j = NULL;
	int temp;
	for (i = List; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if(i->data > j->data)
			{
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
	free(i);
	free(j);
}

void Bucketsort(int arr[], int N, int idx[])
{
	int i = 0, j = 0, new_length = 0;
	nodePT listarr[N], head[N], temp, ex;
	int length[100] = { 0 }, new_arr[100] = { 0 };

	for(i = 0; i < N; i++)
	{
		listarr[i] = NULL;
		head[i] = NULL;
	}
	
	for(i = 0; i < N; i++)
	{
		temp = new_node(arr[i]);
		if(listarr[idx[i]] == NULL)
		{
			listarr[idx[i]] = temp;
			head[idx[i]] = temp;
		}
		else
		{
			listarr[idx[i]]->next = temp;
			listarr[idx[i]] = temp;
		}
	}

	for(i = 0; i < N; i++)
	{
		SelectionSort(head[i]);
		printf("------ List at index %d :", i);
		length[i] = compute_length(head[i]);
		print_list_horiz(head[i]);
		printf("\n");
	} 

	for(i = 0; i < N; i++)
	{
		if(length[i] == 0)
		{
			continue;
		}
		else{
			ex = head[i];
			while(ex != NULL)
			{
				new_arr[j] = ex->data;
				new_length++;
				ex = ex->next;
				j++;
			}
		}
	}
	
	for(i = 0; i < N; i++)
	{
		destroy_list(head[i]);
	}
	
	print_init(new_arr, new_length);

	free(ex);
	free(temp);
}

void print_array(int arr[], int N, int bucket_counter[])
{
	int j;
	for(j = 0; j < N; j++)
	{
		printf("arr[%d] = %5d, idx = %d\n", j, arr[j], bucket_counter[j]);
	}
	printf("\n");
}

int find_max(int arr_num[], int total_number)
{
	int i;
	int max = arr_num[0];

	for(i = 1; i < total_number; i++)
	{
		if(arr_num[i] > max)
		{
			max = arr_num[i];
		}
	}
	return max;
}

int find_min(int arr_num[], int total_number)
{
	int i;
	int min = arr_num[0];

	for(i = 1; i < total_number; i++)
	{
		if(arr_num[i] < min)
		{
			min = arr_num[i];
		}
	}
	return min;
}

void run1()
{
   int i, N, index;
   char fname[100];
   FILE *fp;
   
   printf("\nEnter the filename: ");
   scanf("%s", fname);
   fp = fopen(fname, "r");
   if (fp == NULL)
   {
	   printf("File could not be opened.\n");
   }
   else
   {
	   fscanf(fp, "%d", &N);
	   int  nums1[100], bucket_counter[100];
	   float mid;
	   for(i = 0; i < N; i++)
	   {
		   fscanf(fp, "%d ", &nums1[i]);
	   }
	   int min, max, divider;
	   max = find_max(nums1, N);
	   min = find_min(nums1, N);

	   print_init(nums1, N);

	   printf("\nBucketsort: min = %d, max = %d, N = %d buckets\n", min, max, N);
	   
	   divider = max - min + 1;
	   float temp;
	   temp = (float) N;
	   
	   for (i = 0; i < N; i++)
	   {
		   mid = (float) (nums1[i] - 1) / divider;
		   mid = mid * temp;
		   bucket_counter[i] = (int) mid;
	   }
	   printf("\n");
	   print_array(nums1, N, bucket_counter);

	   Bucketsort(nums1, N, bucket_counter);
	   printf("\n");
   }
   fclose(fp);
}

int main()
{
	printf("This program will read a file name, load data for an array from there and print the sorted array.\n");
	printf("The array is sorted using bucket sort.\n");
	printf("This will be repeated as long as the user wants.\n");
	int option;
	do {
		run1();
		printf("\nDo you want to repeat? Enter 1 to repeat, or 0 to stop) ");
		scanf("%d",&option);
	} while (option == 1);

   return 0;
}