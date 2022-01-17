#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int find_max(int arr[6])
{
	int i;
	int max = arr[0];
	for (i = 1; i < 6; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int find_min(int arr[6])
{
	int i;
	int min = arr[0];
	for (i = 1; i < 6; i++)
	{
		if(arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int main()
{
    int input[6] = {10, 7, 12, 4, 9, 13};
    int max = find_max(input);
    int min = find_min(input);

    int length = max - min + 1;
    int index[length], i;
  	index[0] = min;
  	index[length - 1] = max;
  	for (i = 1; i < length - 1; i++)
  	{
  		index[i] = index[i - 1] + 1;
  	}
  	print_array(index, length);

  	int count[length];
  	for(i = 0; i < length; i++)
    {

    }



    return 0;
}
