#include <stdio.h>
#include <stdlib.h>

int length(char *str)
{
	int i;

	for (i = 0; *(str+i) != '\0'; i++);

	return i;
}

/*
	checks whether str2 is a permutation of str1
	this function works case sensitive
*/
int isPermutation(char *str1, char *str2)
{
	int counter1, counter2, i, j;
	char char1;
	int strlen = length(str1);

	if (strlen != length(str2))
		return 1;
	
	for (i = 0; i < strlen; i++)
	{
		char1 = *(str1 + i);
		counter1 = 0;
		counter2 = 0;
		
		/* Count how often this character is part of the first string */
		for (j = 0; j < strlen; j++)
		{
			if (char1 == *(str1+j))
				counter1++;
		}
		
		/* Count how often this character is part of the second string */
		for (j = 0; j < strlen; j++)
		{
			if (char1 == *(str2+j))
				counter2++;
		}
		
		if (counter1 != counter2)
			return 1;
	}
	
	return 0;
}
