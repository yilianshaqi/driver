/*************************************************************************
    > File Name: memory.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 18时18分44秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	struct a
	{
		char ab;
		short ac;
		int ah;
	};
	struct b
	{
		int aj;
		short ap;
		char ay;
	};
	struct a sy={1,89,90
	};
	struct b sn={34,78,12
	};
	printf("sy.ab=%p,sy.ac=%p,sy.ah=%p\n",&sy.ab,&sy.ac,&sy.ah);
	printf("sn.aj=%p,sn.ap=%p,sn.ay=%p\n",&sn.aj,&sn.ap,&sn.ay);
}
