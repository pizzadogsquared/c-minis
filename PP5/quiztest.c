
#include <stdio.h>


int main()
{
	int i = 200;
	int* pi = &i;

	int v[4] = {10,20,30,40};
	int* p = v;
	int* x = v + 2;

	//printf("%d", &pi);

	//printf("%p", *pi);

	printf("%d\n\n", i);

	//printf("%p", *i);

	printf("%p\n\n", &i);

	printf("%d\n\n", *pi);



	return 0;
}