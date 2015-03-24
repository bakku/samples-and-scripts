/*
	best case: O(1)
	worst case: O(log2(n))
	average case (success): O(log2(n))
	average case (no success): O(log2(n))
	
	--> disadvantage to seq_search: array has to be sorted
*/
int binary_search(int array[], int element, int n)
{
	int left = 0;
	int right = n-1;
	int pointOfSearch;
	
	while (left <= right)
	{
		pointOfSearch = (left + right) / 2;
		
		if (element == array[pointOfSearch])
		{
			return pointOfSearch;
		}
		
		else if (element < array[pointOfSearch])
			right = pointOfSearch - 1;
		
		else
			left = pointOfSearch + 1;
	}
	
	return -1;
}
