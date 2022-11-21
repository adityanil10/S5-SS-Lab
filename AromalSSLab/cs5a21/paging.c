// paging

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
	int s[10], fno[10][20];

	printf("\nEnter the memory size : ");
	scanf("%d",&ms);

	printf("\nEnter the page size : ");
	scanf("%d",&ps);

	nop = ms/ps;
	printf("\nThe no. of pages available in memory are : %d ",nop);

	printf("\nEnter number of processes : ");
	scanf("%d",&np);
	rempages = nop;
	
	for(i=1;i<=np;i++)
	{
		printf("\nEnter no. of pages required for p[%d]: ",i);
		scanf("%d",&s[i]);

		if(s[i] >rempages)
		{
			printf("\nMemory is Full");
			break;
		}
		rempages = rempages - s[i];

		printf("\nEnter pagetable for p[%d] :\n",i);
		for(j=0;j<s[i];j++)
			scanf("%d",&fno[i][j]);
	}

	printf("\nEnter Logical Address to find Physical Address ");
	printf("\nEnter process no. : ");
	scanf("%d", &x);
	printf("Enter pagenumber : ");
	scanf("%d",&y);
	printf("Enter offset : ");
	scanf("%d",&offset);

	if(x>np || y>s[i]+1)
		printf("\nInvalid Input");

	else
	{ 
		pa=fno[x][y]*ps+offset;
		printf("\nThe Physical Address is : %d",pa);
	}
	printf("\n");
}
