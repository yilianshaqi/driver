/*************************************************************************
    > File Name: strcut.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月15日 星期四 18时35分16秒
 ************************************************************************/

#include<stdio.h>
int main(){
	struct test{
		int j;
		char data[0];
	};
	struct test st;
	int array[0];
	char ss[] = "http:\\w";
	printf("ss size =%d\n",sizeof(ss));
	printf("%d\n",array[1]);
	printf("size array = %d\n",sizeof(array));
	printf("size=%d,char =%c\n",sizeof(st),st.data[1]);
	printf("j =%p,data=%p,data+1=%p\n",&st.j,st.data,st.data+1);
}
