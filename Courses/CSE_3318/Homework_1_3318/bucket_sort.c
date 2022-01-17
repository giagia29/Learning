#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int value;
	struct node* add_next;
};

int find_max(int arr_num[50], int total_number)
{
	int i;
     
    int max = arr_num[0];
 
    for (i = 1; i < total_number; i++)
    {
 		if (arr_num[i] > max) 
 		{
 			max = arr_num[i];
 		}
 	}
 	
 	return max;
}

void insert_node(int value, int* bucket_pointer)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));

}

int main(void)
{
	int total_number, arr_num[50], i, bucket[10];

	int* bucket_pointer[10] = { NULL };
	
	printf("Enter the total number that you want to sort: ");
	scanf("%d", &total_number);
	printf("\nEnter the elements for the array: ");
	for (i = 0; i < total_number; i++)
	{
		scanf("%d", &arr_num[i]);
	}

	int max_num = find_max(arr_num, total_number);

	int divider, bucket_count;
	divider = ceil((max + 1) / sizeof(bucket));

	while(index < total_number)
	{
		struct node* head = NULL;
		bucket_count = floor(arr_num[index] / divider);
		bucket_pointer[bucket_count] = &bucket[bucket_count];
		insert_node(arr_num[index], bucket_pointer[bucket_count]);	
	}
}