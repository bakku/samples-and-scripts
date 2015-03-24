// Shows how to use threads in C
// Compares the search of an element in a huge array using threads and using no threads

/* Comparison:
 * the more elements the array contains the slower the "no-threads" function works
 * the more elements the array contains the more the "thread" function excells
 *
 * --> for little arrays the "no-thread" function is way better
 * --> if you are not sure if it will be a small or a huge array use the "thread" function
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// size of the array and the search element, you can play around here
#define MAX_SIZE 1000000
#define SEARCH_ELEMENT 34325


// struct for the thread parameter
typedef struct lookup
{
	int array[MAX_SIZE];
	int start;
	int end;
	int searchElement;
} Lookup;

// initializes the struct for one thread
void initialize_struct(Lookup *element, int begin, int finish, int sE)
{
	int i;
	srand(time(NULL));	
			
	for (i = 0; i < MAX_SIZE; i++)
	{
		element->array[i] = (rand() % MAX_SIZE) + 1;
	}
	
	element->start = begin;
	element->end = finish;
	element->searchElement = sE;
}

void quickSort( int array[], int left, int right)
{
	int temp;

	if(left < right) 
	{
		temp = partition(array, left, right);
		quickSort(array, left, temp-1);
		quickSort(array, temp+1, right);
	}	
}

int partition( int a[], int l, int r) 
{
	int pivot, i, j, t;
	pivot = a[l];
	i = l; j = r+1;
		
	while(1)
	{
		do 
			++i; 
		while(a[i] <= pivot && i <= r);
   		
   		do 
   			--j; 
   		while(a[j] > pivot);
   	
   		if(i >= j) 
   			break;
   		
   		t = a[i]; 
   		a[i] = a[j]; 
   		a[j] = t;
   }
   
   t = a[l]; 
   a[l] = a[j]; 
   a[j] = t;
   
   return j;
}

void binary_search(int array[], int element, int n)
{
	int left = 0;
	int right = n-1;
	int pointOfSearch;
	
	while (left <= right)
	{
		pointOfSearch = (left + right) / 2;
		
		if (element == array[pointOfSearch])
		{
			printf("Element found! It is array[%d]\n", pointOfSearch);
			return;
		}
		
		if (element < array[pointOfSearch])
			right = pointOfSearch - 1;
		
		if (element > array[pointOfSearch])
			left = pointOfSearch + 1;
	}
	
	printf("Element not found!\n");
}

// the function for the thread
void *look(void *arg)
{
	int i;
	int max = 0;
	// cast the argument to the fitting type
	int *elements = ((Lookup *)arg)->array;
	int begin = ((Lookup *)arg)->start;
	int finish = ((Lookup *)arg)->end;
	int search = ((Lookup *)arg)->searchElement;
	
	for (i = begin; i < finish; i++)
	{
		if (search == elements[i])
		{
			printf("Element found! It is array[%d]\n", i);
		}			
	}
}


// this function just searches in the array
void first_example()
{
	Lookup l1, l2;
	pthread_t t1, t2;
	clock_t time1, time2;
	double total_time;
	
	initialize_struct(&l1, 0, MAX_SIZE/2, SEARCH_ELEMENT);
	initialize_struct(&l2, MAX_SIZE/2, MAX_SIZE, SEARCH_ELEMENT);
	
	// creates the two threads und joins them
	time1 = clock();
	pthread_create(&t1, NULL, &look, &l1);
	pthread_create(&t2, NULL, &look, &l2);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	time2 = clock();
	
	total_time = (double) (time2 - time1) / CLOCKS_PER_SEC;
	
	printf("total time: %f\n", total_time);
}

// initializes one array, sorts it using quicksort algorithm and then searches with the binary search algorithm
void second_example()
{
	Lookup l1;
	clock_t time1, time2;
	double total_time;
	
	initialize_struct(&l1, 0, MAX_SIZE, SEARCH_ELEMENT);
	
	time1 = clock();
	quickSort(l1.array, 0, MAX_SIZE);
	binary_search(l1.array, SEARCH_ELEMENT, MAX_SIZE);
	time2 = clock();
	
	total_time = (double) (time2 - time1) / CLOCKS_PER_SEC;
	
	printf("total time: %f\n", total_time);
}


int main(void)
{	
	first_example();
	second_example();
	
	return 0;
}
