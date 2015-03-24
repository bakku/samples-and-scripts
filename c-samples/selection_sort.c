/* Example of selection sort with an array containing integer numbers */
void selection_sort(int array[], int n)
{
	int m, i, j, temp;
	
	for (i = 0; i < n; i++)
	{
		m = array[i];
		
		for (j = i+1; j < n; j++)
		{
			if (array[j] < m)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				m = temp;
			}
		}
	}
}

