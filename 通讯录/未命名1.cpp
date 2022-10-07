#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

#define LEN sizeof(struct LianXiRen)
#define FORMAT "%-10s%-40s%-15s\n"
#define DATA PeoP[i].Name,PeoP[i].GuanXi,PeoP[i].Tele



struct LianXiRen{
	char Name[10];
	char GuanXi[40]; 
	char Tele[15];
		
} PeoP[300];

void Input();
void Search();
void Update();
void Del();
void Display();
void Sort();
void Menu();

void Menu() //创建开始菜单
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t|-------------通讯录菜单------------|\n");
	printf("\t\t|\t0.Exit\t\t\t    |\n");
	printf("\t\t|\t1.Input\t\t\t    |\n");
	printf("\t\t|\t2.Update\t\t    |\n");
	printf("\t\t|\t3.Delete\t\t    |\n");
	printf("\t\t|\t4.Sort\t\t\t    |\n");
	printf("\t\t|\t5.Search\t\t    |\n");
	printf("\t\t|\t6.Display\t\t    |\n");
	printf("\t\t|-------------通讯录菜单------------|\n");
	printf("\n\n\t\t请输入数字（0 ~ 6）：");
}


void Input() //输入联系人信息
{
	int i,count = 0;
	char ch[2];
	FILE *fp;
	if ((fp = fopen("data.txt","a+")) == NULL){
		printf("Fail to open files...\n");
		return;}
	while (!feof(fp))
	{
		if (fread(&PeoP[count],LEN,1,fp) == 1 ){
			count++;}
	}
	fclose(fp);
	
	if (count == 0){
		printf("NO DATA...\n");}       //判断当前通讯录是否为空 
	else{
		system("cls");
		Display();}        //不为空则显示所有人信息 
	if ((fp = fopen("data.txt","wb")) == NULL){
		printf("Fail to open files...");
		return;}
		
	for (i=0;i<count;i++){	
		fwrite(&PeoP[i],LEN,1,fp);}
	printf("Please Input(y/n)...");
	scanf("%s",&ch);
	while (strcmp(ch,"Y") ==0 || strcmp(ch,"y") == 0 )
	{
		printf("NAME:");
		scanf("%s",&PeoP[count].Name);
		for(i=0;i<count;i++)
		{
			if (strcmp(PeoP[i].Name,PeoP[count].Name) == 0)
			{
				printf("You have had a same name people...");
				getch();
				fclose(fp);
				return;
			}
		}
		printf("GuanXi:");
		scanf("%s",PeoP[count].GuanXi);
		printf("Telephone Number:");
		scanf("%s",PeoP[count].Tele);
		if (fwrite(&PeoP[i],LEN,1,fp) != 1 ){
			printf("Can not saved...");
			getch();}
		else
		{
			printf("%s saved successed!\n",&PeoP[count].Name);
			count++;
			break;
		}		
	}
	
	fclose(fp);
	printf("\tOK!\n");
}


void Search()//寻找联系人 
{
	FILE *fp;
	int i,count=0;
	char ch[2],name[15];
	
	if ((fp = fopen("data.txt","rb")) == NULL)
	{
		printf("Fail to open files...");
		return;
	}
	
	while (!feof(fp))
	{
		if(fread(&PeoP[count],LEN,1,fp) == 1 )
		{
			count++;
		}
	}
	fclose(fp);
	
	if (count == 0)
	{
		printf("NO DATA...");
		return;
	}
	
	printf("Please input the name:");
	scanf("%s",&name);
	for (i=0;i<count;i++)
	{
		if (strcmp(name,PeoP[i].Name) == 0)
		{
			printf("We have found, display...?(y/n)");
			scanf("%s",&ch);
			if (strcmp(ch,"Y") || strcmp(ch,"y"))
			{
				printf("Name\tGuanXi\tTelephone\n");
				printf(FORMAT,DATA);
				break;
			}
		}
	}
	if (i == count)
		{
		printf("Fail to find files...");
		}
	return;
}


void Update()//更新联系人 
{
	FILE *fp;
	int i,j,count = 0;
	char name[15];
	if ((fp=fopen("data.txt","r+")) == NULL)
	{
		printf("Fail to open files...");
		return;
	}
	while(!feof(fp))
	{
		if ((fread(&PeoP[count],LEN,1,fp)) == 1)
		{
			count++;
		}
	}
		if (count == 0)
		{
			printf("There is no record...");
			fclose(fp);
			return;
		}
		Display();
		printf("Please input the name that you want to update...\n");
		printf("UPdate Name:");
		scanf("%s",name);
		for (i = 0;i<count;i++)
		{
			if (strcmp(name,PeoP[i].Name) == 0)
			{
				printf("We have found it!Now you can start to update...\n");
				printf("update name:\n");
				scanf("%s",PeoP[i].Name);
				printf("update GuanXi:\n");
				scanf("%s",PeoP[i].GuanXi);
				printf("update Telephone Number:\n");
				scanf("%s",PeoP[i].Tele);
				printf("Update Successed!\n");
				if ((fp = fopen("data.txt","wb")) == NULL)
				{
					printf("Fail to open files...");
					return;
				}
				for (j=0;j<count;j++)
				{
					if ((fwrite(&PeoP[j],LEN,1,fp)) != 1)
					{
						printf("Fail to saved!");
						getch();
					}
				}
					fclose(fp);
					return;	
			}
			printf("We have no found...");
			break;
			
		}
	return;		
}


void Del() //删除联系人 
{
	FILE *fp;
	int i,j,count = 0;
	char ch[2],name[15];
	if ((fp = fopen("data.txt","r+")) == NULL)
	{
		printf("Fail to open files...");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&PeoP[count],LEN,1,fp) == 1)
		{
			count++;
		}
		fclose(fp);
		if (count == 0)
		{
			printf("There is no record...");
			return;
		}
		Display();
		printf("Please input the name you want to delete...");
		scanf("%s",name);
		for (i=0;i<count;i++)
		{
			if (strcmp(name,PeoP[i].Name) == 0)
			{
				printf("Have found it!Delete...?(y/n)\n");
				scanf("%s",&ch);
				if (strcmp(ch,"y") == 0|| strcmp(ch,"Y") == 0)
				{
					for(j=i;j<count;j++)
					{
						PeoP[j] = PeoP[j+1];
						count--;
					}
					if ((fp = fopen("data.txt","wb")) == NULL)
					{
						printf("Fail to open files...");
						return;			
					}
					for(j=0;j<count;j++)
					if (fwrite(&PeoP[j],LEN,1,fp) !=1)
					{
						printf("Fail to open files...");
						getch();
					}
					fclose(fp);
					printf("Delete Successed!\n");
					return;
				}
		
		
			}
		}
		printf("Not Found record...\n");
	}
}

void Display()//  显示联系人 
{
	FILE *fp;
	int i,count = 0;
	fp = fopen("data.txt","rb");
	while (!feof(fp))
	{
		if (fread(&PeoP[count],LEN,1,fp) == 1)
		{
			count++;
		}
	}
	fclose(fp);
	printf("Name      GuanXi                                Telephone\n");
	for (i=0;i<count;i++)
	{
		printf(FORMAT,DATA);
	}
}

void Sort()
{
	FILE *fp;
	struct LianXiRen temp;
	int i=0,j=0,count=0;
	if ((fp = fopen("data.txt","r+") ) == NULL)
	{
		printf("Fail to open files...\n");
		return;
	}
	while(!feof(fp))
	{
		if (fread(&PeoP[count],LEN,1,fp) == 1)
		{
			count++;
		}
	}
	fclose(fp);
	if (count == 0)
	{
		printf("NO DATA...\n");
		return;
	}
	for (i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if (strcmp(PeoP[i].Name,PeoP[j].Name)>0)
			{
				temp = PeoP[i];
				PeoP[i] = PeoP[j];
				PeoP[j] = temp;
			}
		}
	}
	if ((fp = fopen("data.txt","wb") ) == NULL)
	{
		printf("Fail to open files...\n");
		return;
	}
	for (i=0;i<count;i++)
	{
		if (fwrite(&PeoP[i],LEN,1,fp) != 1)
		{
			printf("Fail to saved...!\n");
			getch();
		}
	}
	fclose(fp);
	printf("saved successed...!\n");
	return;
}





int main()
{
	int n;
	Menu();
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
			case 1: Input();    break;
			case 2: Update();   break;
			case 3: Del();      break;
			case 4: Sort();     break;
			case 5: Search();   break;
			case 6: Display();  break;
			default: break;
		}
		getch();
		Menu();
		scanf("%d",&n);
	}
	
	
		
	
	
	return 0;
}

