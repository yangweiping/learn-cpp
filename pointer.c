#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int i = 1;
	int* p = &i;
	int** q = &p;

	char* ch_ptr;

	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(q));
	printf("%d\n", sizeof(ch_ptr));
	printf("-----------------------\n");

	printf("%d\n", i);
	printf("%p\n", &i);
	printf("%p\n", p);
	printf("%p\n", &p);
	printf("%p\n", q);

	printf("%d\n", *p);
	printf("%d\n", **q);



	exit(0);
}