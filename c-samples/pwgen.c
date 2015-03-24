#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char letters[] = { "abcdefghijklmnopqrstuvxyz" };

int main(int argc, char *argv[]) 
{
	if (argc < 2)
	{
		printf("error. no number as an argument given.\n");
		return -1;	
	}
	
	int N = atoi(argv[1]);
	int i;
	char *string = (char *) malloc(N + 1);
	
	srand(time(NULL));
	
	for (i = 0; i < N; i++) {
		int r = rand() % strlen(letters);
		*(string+i) = letters[r];
	}
	
	*(string+N) = '\0';
	
	printf("%s\n", string);
	
	free(string);
	
	return 0;
}
