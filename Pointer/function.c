#include "stdio.h"

void ptrDouble(int *ptr)
{
	*ptr *= 2;	
}

int main()
{
	int num = 10;
	int* ptr;
	ptr = &num;
	ptrDouble(ptr);
	printf("*ptr = %d\n", *ptr);
	ptrDouble(ptr);
	printf("*ptr = %d\n", *ptr);
	printf("num = %d\n", num);
}
