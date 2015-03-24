void selection_sort(int array[], int n)
{
	int m, i, j, temp;
	
	for (i = 0; i < n; i++)
	{
		m = i;
		
		for (j = i+1; j < n; j++)
		{
			if (array[j] < array[m])
			{
				m = j;
			}
		}
		temp = array[i];
		array[i] = array[m];
		array[m] = temp;
	}
}

