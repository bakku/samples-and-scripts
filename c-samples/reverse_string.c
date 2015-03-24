#include <stdio.h>
#include <stdlib.h>

/*
	probably the shortest way of coding strlen
	WITH a return value
	(shorter versions with an pointer as parameter possible)
*/
size_t strlen(char *str)
{
	size_t i = 0;
	while (*(str + ++i) != '\0');
	return i;
}

/*	reverse a string   */
char *reverse(char *str)
{
	int len = strlen(str);
	int i, j;
	// + 1 for '\0'
	char *clone = (char *) malloc(len+1);
	
	// clone starts from 0, str starts from the end
	for (i = 0, j = len-1; i < len; i++, j--)
		*(clone+i) = *(str+j);
	
	// '\0' gets manually added
	*(clone+len) = '\0';
	
	return clone;
}

/* show how it works */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("require string as argument\n");
		return -1;
	}
	
	char *copy = reverse(argv[1]);
	
	printf("%s\n", copy);
	
	// should be called because of malloc in rev
	free(copy);
	
	return 0;
}
