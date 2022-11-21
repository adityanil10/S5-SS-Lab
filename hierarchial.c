#include<stdio.h>
#include<string.h>

void main()
{
        char d[50][50][50],o[10];
        int i,m,n[30],j;
        printf("Enter the number of directories of ROOT");
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
                printf("Enter the number of all subdirectories in directory %d :",i);
                scanf("%d",&o[i]);
		printf("Enter the number of files in the last subdirectory of %d : ",i);
		scanf("%d",&n[i]);
        }
        printf("Enter the name of the ROOT : ");
        scanf("%s",&d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("Enter the name of Main Directory %d : ",i);
                scanf("%s",&d[i][0]);
        }
        for(i=1;i<=m;i++)
        {	
		printf("Enter the name of the subdirectories of %d :",i);
		for(j=1;j<=o[i];j++)
		{
			scanf("%s",&d[i][j]);
		}
	}
	i=0;
	for(i=1;i<=m;i++)
	{
		printf("Enter the name of the files in last folder of %d :",i);
		for(j=o[i]+1;j<=n[i]+o[i];j++)
		{
			scanf("%s",&d[i][j]);
		}
        }						 
      
        printf("The directory structure\n");
        printf("The ROOT : \t            %s \n",d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("The Directory %d :%s\n",i,d[i][0]);
                printf("The subdirectories : \n");
                for(j=1;j<=n[i]+o[i];j++)
                {
			if(j<=o[i])
			{
				printf ("% *s\n",j,d[i][j]);
			}
			else
			{
				printf ("% *s\n",10,d[i][j]);
			}	                        
                }
        }

}

