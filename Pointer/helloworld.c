#include "stdio.h"

int main()
{
	int num = 10;
	int *ptr;
	
	ptr = &num;
	
	printf("%p = %d\n", &ptr, *ptr);

	return 0;
}
