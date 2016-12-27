/*************************************************************************
    > File Name: API_calculator.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 20时10分24秒
 ************************************************************************/
#include<stdio.h>
//函数的功能：计算两个数的和
//第一个参数：int型的加数
//第二个参数：int型的加数
//第三个参数：两个数相加的结果存放变量地址
//函数返回值：返回0表示成功，返回-1表示失败

int add(int fnum,int snum,float *result)
{
	*result = fnum + snum;
	return 0;
}
//函数的功能：计算两个数的差
//第一个参数：int型的被减数
//第二个参数：int型的减数
//第三个参数：两个数相减的结果存放变量地址
//函数返回值：返回0表示成功，返回-1表示失败
int sub(int fnum,int snum,float *result)
{
	*result = fnum - snum;
	return 0;
}
//函数的功能：计算两个数的乘积
//第一个参数：int型的乘数
//第二个参数：int型的乘数
//第三个参数：两个数相乘的结果存放变量地址
//函数返回值：返回0表示成功，返回-1表示失败
int mul(int fnum,int snum,float *result)
{
	*result = fnum * snum;
	return 0;
}
//函数的功能：计算两个数相除
//第一个参数：int型的被除数
//第二个参数：int型的除数
//第三个参数：两个数相除的结果存放变量地址
//函数返回值：返回0表示成功，返回-1表示失败
int divi(int fnum,int snum,float *result)
{
	if(snum==0)
	{
		return -1;
	}
	*result = fnum / snum;
	return 0;
}
//函数的功能：调用加减乘除的回调函数
//第一个参数：指向加减乘除函数的函数指针，可传入add，sub，mul，div；
//第二个参数：第一要运算的数
//第三个参数：第二要运算的数
//第四个参数：两个数运算结果存放变量地址
//函数返回值：返回0表示成功，返回-1表示失败
int calculator(int (*pfunc)(int ,int,float * ),int fnum,int snum,float *result)
{
	return pfunc(fnum,snum,result);
}
