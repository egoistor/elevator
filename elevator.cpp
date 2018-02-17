#include<stdio.h>
#include<math.h>
int main()
{
	struct Dianti{
		int	time;
		int begin;
		int end;
	};
	struct Dianti stu[5],w;//打的时候不会C++，拿结构体凑合了 
	int i,j;
	 FILE *fpRead=fopen("input.txt","r");  
    for(int i=0;i<5;i++)  
    {  
        fscanf(fpRead,"%d %d %d",&stu[i].time,&stu[i].begin,&stu[i].end);    
    }  
     fclose(fpRead);  //从input中写入数据
	for (i=0;i<5;i++)
	{
		if (stu[i].begin==0)
		stu[i].begin=10;
		if (stu[i].end==0)
		stu[i].end=10;
	}//因为数据问题无法正确表达原意，所以进行数据修改 
	for (i=0;i<5;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if (stu[i].time>stu[i+1].time)
			{
				w=stu[i];
				stu[i]=stu[i+1];
				stu[i+1]=w;
			}
		}
	}//对请求时间进行排序，出租车的模式 
	FILE *fp=fopen("output.txt","w");  
	int sumtime=stu[0].begin,waittime;
	for (i=0;;)
	{
    	if (stu[i].time>sumtime)
    	waittime=stu[i].time-sumtime;
    	sumtime+=waittime+1;//等待旅客的时间 
    	fprintf(fp,"%d时，停靠在%d楼\n",sumtime,stu[i].begin);
		sumtime+=abs(stu[i].end-stu[i].begin)+1;
		fprintf(fp,"%d时，停靠在%d楼\n",sumtime,stu[i].end);
		i++;//单程结束，计数加一 
		if (i==5)
		break;
		else
		{
			sumtime+=abs(stu[i].begin-stu[i-1].end);
		 } 
	}
	printf("%d",sumtime);//计算总时间 
	return 0;
 } 
