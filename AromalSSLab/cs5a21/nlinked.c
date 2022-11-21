// linked

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

struct file
{
	int id;
	int size;
	int nblock;
	int blocks[MAX];
}a[MAX];

void main()
{
	int b,n,i,j,temp;
	
	printf("Enter block size : ");
	scanf("%d",&b);
	
	printf("Enter no. of files : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		a[i].id = i;
		
		printf("\nEnter size of file %d : ",i);
		scanf("%d",&a[i].size);
		
		a[i].nblock = a[i].size/b;
		
		printf("Enter blocks used : \n");
		for(j=0;j<a[i].nblock;j++)
			scanf("%d",&a[i].blocks[j]);
	}
	
	printf("\nEnter no. of filename to display details : ");
	scanf("%d",&j);
	
	printf("\nfile_id\tfile_size\tstart\tend\tblocks_occupied\n");
	printf("\n%d\t%d\t\t%d\t%d\t",a[j].id,a[j].size,a[j].blocks[0],a[j].blocks[a[j].nblock-1]);

	for(i=0;i<a[j].nblock;i++)
	{
		printf("%d -> ",a[j].blocks[i]);
	}
	printf("\n");
}
