/*************************************************************************
    > File Name: roll_call.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年11月20日 星期日 16时54分42秒
 ************************************************************************/
#include"head.h"
int main(){
	char *name[NAME_SIZE]={
		"李政","段传奇","张伟强","王阳","马亮","郝晓阳","强卫华","淡东东","黄阳"};
	int ret=0;
	srand((int)time(NULL));
	while(1)
	{
		ret =rand()%NAME_SIZE;
		printf("Congratulations!\n");
		printf("Lucky is %s\n",name[ret]);
		if('q'==getchar())
		{
			break;
		}
	}
	return 0;

}

