#include<stdio.h>
#include<math.h>
int main()
{
	struct Dianti{
		int	time;
		int begin;
		int end;
	};
	struct Dianti stu[5],w;//���ʱ�򲻻�C++���ýṹ��պ��� 
	int i,j;
	 FILE *fpRead=fopen("input.txt","r");  
    for(int i=0;i<5;i++)  
    {  
        fscanf(fpRead,"%d %d %d",&stu[i].time,&stu[i].begin,&stu[i].end);    
    }  
     fclose(fpRead);  //��input��д������
	for (i=0;i<5;i++)
	{
		if (stu[i].begin==0)
		stu[i].begin=10;
		if (stu[i].end==0)
		stu[i].end=10;
	}//��Ϊ���������޷���ȷ���ԭ�⣬���Խ��������޸� 
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
	}//������ʱ��������򣬳��⳵��ģʽ 
	FILE *fp=fopen("output.txt","w");  
	int sumtime=stu[0].begin,waittime;
	for (i=0;;)
	{
    	if (stu[i].time>sumtime)
    	waittime=stu[i].time-sumtime;
    	sumtime+=waittime+1;//�ȴ��ÿ͵�ʱ�� 
    	fprintf(fp,"%dʱ��ͣ����%d¥\n",sumtime,stu[i].begin);
		sumtime+=abs(stu[i].end-stu[i].begin)+1;
		fprintf(fp,"%dʱ��ͣ����%d¥\n",sumtime,stu[i].end);
		i++;//���̽�����������һ 
		if (i==5)
		break;
		else
		{
			sumtime+=abs(stu[i].begin-stu[i-1].end);
		 } 
	}
	printf("%d",sumtime);//������ʱ�� 
	return 0;
 } 
