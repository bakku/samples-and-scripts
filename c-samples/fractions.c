#include <stdio.h>
#include <stdlib.h>

typedef struct fraction {
	int numerator;
	int denumerator;
} Fraction;

int euclidean(int a, int b)
{
	if (a == 0)
		return b;
	
	return euclidean(b % a, a);
}

/* 
	To reduce a fraction, this code uses the greatest common dividor (gcd)
	It computes the gcd of the numerator and denumerator and divides both with himself
	This way the fraction is perfectly reduced
	
	Reducing should not be called with every operation.
	That's why it's only called before printing to show the user a perfectly reduced fraction
	and before comparing, so fractions can be compared more easily
*/
void reduceFraction(Fraction *fraction)
{
	int gcd = euclidean(fraction->numerator, fraction->denumerator);
	
	fraction->numerator = fraction->numerator / gcd;
	fraction->denumerator = fraction->denumerator / gcd;
}


void readFraction(Fraction *fraction)
{
	printf("Input numerator: ");
	scanf("%d", &fraction->numerator);
	printf("Input denumerator: ");
	scanf("%d", &fraction->denumerator);
}

void printFraction(Fraction *fraction)
{
	reduceFraction(fraction);
	printf("%d\\%d\n", fraction->numerator, fraction->denumerator);
}

/*
	Sample for better understanding:
	
	1/2 + 1/4 --> (1*4 + 2*1)/2*4 --> (4 + 2)/8 --> 6/8 --> 3/4
	
	IMPORTANT: use free() to free the memory you allocated
*/
Fraction *addFractions(Fraction *first, Fraction *second)
{
	Fraction *result = (Fraction*) malloc(sizeof(Fraction));
	
	result->numerator = first->numerator * second->denumerator + first->denumerator * second->numerator;
	result->denumerator = first->denumerator * second->denumerator;

	return result;
}

/*
	Sample for better understanding:
	
	1/2 * 1/4 --> 1*1/2*4 --> 1/8
	
	IMPORTANT: use free() to free the memory you allocated
*/
Fraction *multiplyFractions(Fraction *first, Fraction *second)
{
	Fraction *result = (Fraction*) malloc(sizeof(Fraction));

	result->numerator = first->numerator * second->numerator;
	result->denumerator = first->denumerator * second->denumerator;

	return result;
}

/* 
	If two fractions are the same returns 0
	If not the same it returns 1
*/
int compareFractions(Fraction *first, Fraction *second)
{
	reduceFraction(first);
	reduceFraction(second);
	
	if(first->numerator == second->numerator && first->denumerator == second->denumerator)
		return 0;
	else
		return 1;
}
