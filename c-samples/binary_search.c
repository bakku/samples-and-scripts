// example of binary search
// searches element in array with the length n

void binary_search(int array[], int element, int n)
{
	int left = 0;
	int right = n-1;
	int pointOfSearch;
	
	while (left <= right)
	{
		pointOfSearch = (left + right) / 2;
		
		if (element == array[pointOfSearch])
		{
			printf("Element found! It is array[%d]\n", pointOfSearch);
			return;
		}
		
		if (element < array[pointOfSearch])
			right = pointOfSearch - 1;
		
		if (element > array[pointOfSearch])
			left = pointOfSearch + 1;
	}
	
	printf("Element not found!\n");
}
