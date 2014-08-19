#include <stdio.h>

/* 
 * swap.c
 * Fundamental algorithm to swap the values of x and y.
 *
 */

void swap(int *x, int *y)
{
	int temp;
	temp = *x; *x = *y; *y = temp;
}

int main(int argc, const char* argv[])
{
	int a = 123;
	int b = 321;

	printf("a = %d, b = %d\n", a, b);

	swap(&a, &b);

	printf("a = %d, b = %d\n", a, b);
}
