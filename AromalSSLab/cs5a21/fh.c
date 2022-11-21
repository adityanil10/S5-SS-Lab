// hire

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct
{
	char dname[10],fname[10][10];
	int fcnt;
	int un;
}dir[10];

void main()
{
	int i,ch,dcnt,k;
	char f[30], d[30], c[30][30];
	dcnt=0;
	ccnt=0;
	
	while(1)
	{
		printf("\n\n1. Create User\t2. Create Directory\t3.Create File\t4. Delete File\t5. Search File\t6. Display Files\t7. Exit\nEnter your choice -- ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter user name : ");
				get(c[ccnt]);
				ccnt++;
				break;
			
			case 2: 
				printf("\nEnter name of directory -- ");
				scanf("%s", dir[dcnt].dname);
				dir[dcnt].fcnt=0;
				dcnt++;
				printf("Directory created");
				break;
			
			case 3: 
				printf("\nEnter name of the directory -- ");
				scanf("%s",d);
				
				for(i=0;i<dcnt;i++)
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter the name of the file -- ");
						scanf("%s",f);
						
						int flag = 0;
						
						for(k=0;k<dir[i].fcnt;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File %s already exists.",f);
								flag = 1;
								break;
							}
						}
						
						if(flag == 0)
						{
							printf("File %s created.",f);
							strcpy(dir[i].fname[dir[i].fcnt],f);
							dir[i].fcnt++;
						}
						break;
					}
					
				if(i==dcnt)
					printf("Directory %s not found.",d);
					
				break;

			case 4: 
				printf("\nEnter name of the directory -- ");
				scanf("%s",d);
				
				for(i=0;i<dcnt;i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter name of the file -- ");
						scanf("%s",f);
						for(k=0;k<dir[i].fcnt;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File %s is deleted ",f);
								dir[i].fcnt--;
								strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
								goto jmp;
							}
						}
						printf("File %s not found",f);
						goto jmp;
					}
				}
				printf("Directory %s not found",d);
				jmp : 
				break;
				
				case 5: 
				printf("\nEnter name of the directory -- ");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter the name of the file -- ");
						scanf("%s",f);
						for(k=0;k<dir[i].fcnt;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File %s is found ",f);
								goto jmp1;
							}
						}
						printf("File %s not found",f);
						goto jmp1;
					}
				}
				printf("Directory %s not found",d);
				jmp1: 
				break;
			
			case 6: 
				if(dcnt==0)
				printf("\nNo Directory's ");
				else
				{
					printf("\nDirectory\tFiles");
					for(i=0;i<dcnt;i++)
					{
						printf("\n%s\t\t",dir[i].dname);
						for(k=0;k<dir[i].fcnt;k++)
							printf("\t%s",dir[i].fname[k]);
					}
				}
				break;
				
			default:
				printf("Exiting!\n");
				exit(0);
		}
	}
}
