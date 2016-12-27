/*************************************************************************
    > File Name: API_insert.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 18时55分19秒
 ************************************************************************/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include <stdio.h>
//函数的功能：对int型数组进行排序
//第一个参数：int型的数组名
//第二个参数：数组的长度
//第三个参数：数组排序的方式，mode = 0 为升序，mode ！= 0 为降序
//返回值    ：返回-1表示排序失败，返回0表示排序成功

int insert(int *array,int max,int mode)
{
	if(NULL == array)
	{
		return -1;
	}
	int i,j,temp;
	if(max>1 && mode==0)
	{
		for(i=1;i<max;i++)
		{
			temp =array[i];		
			j=i-1;
			while(j>=0 && temp<array[j])
			{
				array[j+1]=array[j];
				j--;
			}
			array[j+1]=temp;
		}
	}
	else if(max>1 && mode !=0)
	{
		for(i=1;i<max;i++)
		{
			temp = array[i];		
			j=i-1;
			while(j>=0 && temp>array[j])
			{
				array[j+1]=array[j];
				j--;
			}
			array[j+1]=temp;
		}

	}
	return 0;
}
/*************************************************************************
    > File Name: API_calculator.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 20时10分24秒
 ************************************************************************/
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
/*************************************************************************
    > File Name: API_encrypt.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 12时34分00秒
 ************************************************************************/

//函数的功能：对文件加密
//第一个参数：要加密的文件路径名
//返回值    ：返回-1表示加密失败，返回0表示加密成功
int encrypt(const char *pathname)
{
	if(NULL == pathname)
	{
		return -1;
	}
	FILE *sfd = fopen(pathname,"r");
	if(NULL==sfd)
	{
		return -1;
	}
	FILE *dfd = fopen("temp","w");
	if(NULL == dfd)
	{
		return -1;
	}
	int buf,ret;
	while(!feof(sfd))
	{
		buf = fgetc(sfd);
		buf=~buf;
		ret = fputc(buf,dfd);
		if(ret < 0)
		{
			return -1;
		}
	}
	fclose(sfd);
	fclose(dfd);
	if(rename("temp",pathname))
	{
		return -1;
	}

	return 0;
}

/*************************************************************************
    > File Name: API_select.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 19时32分13秒
 ************************************************************************/

//函数的功能：对int型数组进行排序
//第一个参数：int型的数组名
//第二个参数：数组的长度
//第三个参数：数组排序的方式，mode = 0 为升序，mode ！= 0 为降序
//返回值    ：返回-1表示排序失败，返回0表示排序成功
int select_sort(int *array,int max,int mode)
{
	if(!array)
	{
		return -1;
	}
	int i,j,temp;
	if(max>1 && mode == 0)
	{
		for(i=0;i<max-1;i++)
		{
			for(j=i+1;j<max;j++)
			{
				if(array[i]>array[j])
				{
					temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}

			}
		}
	}
	else if(max>1 && mode !=0)
	{
		for(i=0;i<max-1;i++)
		{
			for(j=i+1;j<max;j++)
			{
				if(array[i]<array[j])
				{
					temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}
/*************************************************************************
    > File Name: API_copy.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 11时31分23秒
 ************************************************************************/

//函数的功能：文件复制
//第一个参数：要复制的文件路径名
//第二个参数：复制后的文件路径名
//返回值    ：返回-1表示复制失败，返回0表示复制成功
int copy(const char *src,const char *dest)
{
#define BUF_SIZE  256
	if(NULL==src || NULL==dest)
	{
		return -1;
	}
	int sfd = open(src,O_RDONLY);
	if(sfd < 0)
	{
		return -1;
	}
	int dfd = open(dest,O_WRONLY | O_CREAT,0666);
	if(dfd < 0)
	{
		return -1;
	}
	char buf[BUF_SIZE]="";
	int rret = 0;
	int wret = 0;
	while((rret = read(sfd,buf,BUF_SIZE))> 0)
	{
		printf("rret = %d,read : %s\n",rret,buf);
		wret = write(dfd,buf,rret);
		if(wret < 0)
		{
			return -1;
		}
		bzero(buf,BUF_SIZE);
	}
	if(rret ==-1 )
	{
		return -1;
		close(sfd);
		close(dfd);
		remove(dest);
	}
#undef BUF_SIZE
	close(sfd);
	close(dfd);
	return 0;
}

			}
		}
		
	}
	return 0;
}
/*************************************************************************
    > File Name: API_reverse.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 14时34分22秒
 ************************************************************************/
//函数的功能：对字符串中以单词反转
//第一个参数：要反转的字符串
//函数返回值：操作成功返回0；操作失败返回-1
int reverse(char *string)
{
#define BUF_SIZE 1024
#define MAX 256
	if(NULL == string)
	{
		return -1;
	}
	char *temp = NULL;
	int total_length = strlen(string);
	char delim[]=" ";
	char *temp_buf=NULL;
	char t_buf[MAX]="";
	char *buf=malloc(BUF_SIZE);
	if(NULL == buf)
	{
		return -1;
	}
//	int set = (int)' ';
//	memset(buf,set,BUF_SIZE);
	bzero(buf,BUF_SIZE);
	temp_buf = buf+total_length;
	temp = strtok(string,delim);
	while(temp != NULL)
	{
		/*
		if(temp==string)
		{
			temp_buf=temp_buf - strlen(temp);
			strcpy(temp_buf,temp);
			
		}
		else{
			temp_buf=temp_buf - strlen(temp)-1;
			strncpy(temp_buf,temp,strlen(temp));
		}
		temp = strtok(NULL,delim);*/
		bzero(t_buf,MAX);
		strcpy(t_buf,temp);
		if(temp != string)
		{	
			strcat(t_buf," ");
		}
		temp_buf=temp_buf - strlen(t_buf);
		strncpy(temp_buf,t_buf,strlen(t_buf));
		temp = strtok(NULL,delim);

	}
	strcpy(string,buf);
	free(buf);
#undef MAX 
#undef BUF_SIZE
	return 0;
}
/*************************************************************************
    > File Name: API_bubble.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 19时58分02秒
 ************************************************************************/

//函数的功能：对int型数组进行排序
//第一个参数：int型的数组名
//第二个参数：数组的长度
//第三个参数：数组排序的方式，mode = 0 为升序，mode ！= 0 为降序
//返回值    ：返回-1表示排序失败，返回0表示排序成功
int bubble(int *array,int max,int mode)
{
	if(!array)
	{
		return -1;
	}
	int i,j,temp;
	if(max>1 && mode ==0)
	{
		for(i=0;i<max-1;i++)
		{
			for(j=i;j+1<max;j++)
			{
				if(array[j]>array[j+1])
				{
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}
	}
	else if(max>1 && mode !=0)
	{
		for(i=0;i<max-1;i++)
		{
			for(j=i;j+1<max;j++)
			{
				if(array[j]<array[j+1])
				{
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}
	}
	return 0;
}
