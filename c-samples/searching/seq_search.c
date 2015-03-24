/*
	best case: O(1)
	worst case: O(len)
	average case (success): O((len+1)/2)
	average case (no success): O(len)
*/
int seq_search(int a[], int elem, int len)
{
	int i;
	
	for (i = 0; i < len; i++)
		if (a[i] == elem)
			return i;

	return -1;
}
