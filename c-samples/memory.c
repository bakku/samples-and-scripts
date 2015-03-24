#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long long k = 2147483648;
	char *ptr = (char *) malloc(k);
	unsigned long long i;
	for (i = 0; i < k; i++)
		*(ptr+i) = 'a';
	
	sleep(5);
	
	free(ptr);
}
