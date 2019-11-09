#include "stdio.h"

int main()
{
	int num = 10;
	int *ptr1 = &num;
	int **ptr2 = &ptr1;
	int ***ptr3 = &ptr2;

	printf("\t\t\t\t&num adress = %p\tnum value = %d\n", &num, num);
	printf("ptr1 reference = %p\t&ptr1 adress = %p\t*ptr1 value = %d\n", ptr1, &ptr1, *ptr1);
	printf("ptr2 reference = %p\t&ptr2 adress = %p\t**ptr2 value = %d\n", ptr2, &ptr2, **ptr2);
	printf("ptr3 reference = %p\t&ptr3 adress = %p\t***ptr3 value = %d\n", ptr3, &ptr3, ***ptr3);
}
