#include <stdlib.h>

void msort(int array[], int left, int right, int helper[])
{
	int i, j, k;
	
	if (right > left)
	{
		int mid = (right + left) / 2;
		
		msort(array, left, mid, helper);
		msort(array, mid + 1, right, helper);
		
		for (k = left; k <= mid; k++)
			helper[k] = array[k];
		
		for (k = mid; k < right; k++)
			helper[right + mid - k] = array[k + 1];
		
		i = left;
		j = right;
		
		for (k = left; k <= right; k++)
			if (helper[i] < helper[j])
				array[k] = helper[i++];
			else
				array[k] = helper[j--];
	}
}

void merge_sort(int array[], int len)
{
	int *helper = (int *) malloc(sizeof(int) * len);
	
	msort(array, 0, len-1, helper);
	
	free(helper);
}
