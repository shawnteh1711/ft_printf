#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int sum;

	printf("hi");
	sum = add(1, 2);
	printf("sum: %d\n", sum);
	return (0);
}