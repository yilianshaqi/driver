/*************************************************************************
    > File Name: test_d.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月23日 星期五 15时16分39秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>



int main(int argc, char *argv[])

{


	int array[10] = {
		0};

	int *p, *q;

	p = q = array;

	p++;


	printf("p:%p\n",p);
	printf("q:%p\n",q);
	printf("%d\n", p - q);

	printf("%d\n", (char *)p - (char *)q);

	printf("%d\n", sizeof(array)/sizeof(*array));



	return 0;

}
