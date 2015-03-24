void insertion_sort(int array[], int n)
{
	int m, i, j;
	
	for (i = 1; i < n; i++)
	{
		m = array[i];
		for (j = i; j > 0; j--)
		{
			if (m > array[j-1])
				break;
				
			if (m <= array[j-1])
				array[j] = array[j-1];
				
		}
		array[j] = m;
	}
}
