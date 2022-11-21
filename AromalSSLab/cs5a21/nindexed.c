// indexed

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

struct file
{
	int id;
	int size;
	int nblock;
	int start[MAX];
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
		
		printf("Enter index of file %d : ",i);
		scanf("%d",&a[i].start[0]);
		
		a[i].nblock = a[i].size/b;
		
		printf("Enter blocks used : \n");
		for(j=1;j<a[i].nblock+1;j++)
			scanf("%d",&a[i].start[j]);
	}
	
	printf("\nEnter no. of filename to display details : ");
	scanf("%d",&j);
	
	printf("\nfile_id\tfile_size\tindex\tblocks_occupied\n");
	printf("\n%d\t%d\t\t%d\t",a[j].id,a[j].size,a[j].start[0]);

	for(i=1;i<a[j].nblock+1;i++)
	{
		printf("%d -> ",a[j].start[i]);
	}
	printf("-1\n");
}
