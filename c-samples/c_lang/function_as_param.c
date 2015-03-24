#include <stdio.h>
#include <stdlib.h>

void printString(char *c)
{
	printf("%s\n", c);
}

void printLengthOfString(char *c)
{
	int i = 0;
	while (*(c+i) != '\0')
		i++;
	
	printf("Length of string: %d\n", i);
}

/* 
	Test a String after the pattern [A]+BC
	and calls a function with this substring as parameter
*/
void testPattern(char *c, void (*f)(char *str) )
{
	int i = 0;
	int numberA;

	while (*(c+i) != '\0')
	{
		if (*(c+i) == 'A')
		{
			numberA = 0;
			while (*(c+i) == 'A')
			{
				i++;
				numberA++;
			}
			
			if (*(c+i) == 'B' && *(c+i+1) == 'C')
			{
				int j;
				char array[numberA+2];
				
				for (j = 0; j < (numberA); j++)
				{
					array[j] = 'A';
				}
				array[numberA] = 'B';
				array[numberA+1] = 'C';
				
				f(&array[0]);
			}
		}
		i++;
	}
}
