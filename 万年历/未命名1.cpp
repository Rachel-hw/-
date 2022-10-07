#include<stdio.h>

int year,month,day,sum = 0,i,sum1;
int run[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int ping[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][10] = {"һ","��","��","��","��","��","��"};

int Year_Check(int year)
{
	if ((year%4==0&&year%100!=0) ||year%400==0)
	{
		return 1;//���귵��1 
	}
	else
	{
		return 0;
	}
	
}

void PrintStar()
{
	printf("************************************************\n"); 
}

void PrintBegining()
{
	PrintStar();
	printf("\t������\t\n");
	for (i = 0;i<7;i++)
	{
		printf("%s\t",week[i]);
	}
	printf("\n");
}


//1900\1\1������һ ,��User����������յ�1900������
int DaySum(int year,int month,int day,int run[],int ping[])
{
	for (i=1900;i<year;i++)
	{
		if (Year_Check(i) == 1)
		{
			sum+=366;
		}
		else
		{
			sum+=365;
		}
	}
	for (i=0;i<month-1;i++)
	{
		if (Year_Check(year) == 1){
			sum += run[i];
		}
		else{
			sum += ping[i];
		}
	}
	return sum;
}

void PrintAll(int year,int month,int day,int sum)
{
	int temp,result;
	result = sum%7;
	for (i=0;i<result;i++)
	{
		printf("\t");
	}
	temp = 7 - result;
	if (Year_Check(year) == 1)
	{
		for (i = 1;i <= run[month-1];i++)
		{
			if (i != day){
			printf("%d\t",i);
			}
			else
			{
				printf("%d*\t",i);
			}
			if (i == temp || (i-temp) %7 == 0 )
			{
				printf("\n");
			}
		
		}
	}
	else
	{
		for (i = 1;i <= ping[month-1];i++)
		{
			if (i != day){
			printf("%d\t",i);
			}
			else
			{
				printf("%d*\t",i);
			}
			if (i == temp || (i-temp) %7 == 0 )
			{
				printf("\n");
			}
			
		}
	}
	
	printf("\n");
}

int main()
{
	char ch = 'r';
	while(ch == 'r' || ch == 'R')
	{
	printf("���������ѯ���ꡢ�¡��գ�");
	scanf("%d %d %d",&year,&month,&day);
	PrintBegining();
	sum = DaySum(year,month,day,run,ping);
	PrintAll(year,month,day,sum);	
	PrintStar();
	printf("\n%d\n",sum);
	printf("��r���¿�ʼ�������λ�˳�����");
	scanf("%s",&ch);
	}
	return 0;	
}
