// sequential

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct file
{
	int id;
	int size;
	int start;
	int nblock;
}a[MAX];

void main()
{
	int b,n,i,j,temp;
	double t;
	
	printf("Enter block size : ");
	scanf("%d",&b);
	
	printf("Enter no. of files : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		a[i].id = i;
		
		printf("Enter size of file %d : ",i);
		scanf("%d",&a[i].size);
		
		printf("Enter start of file %d : ",i);
		scanf("%d",&a[i].start);
		
		a[i].nblock = a[i].size/b;
	}
	
	printf("Enter no. of filename to display details : ");
	scanf("%d",&j);
	
	printf("\nfile_id\tfile_size\tstart\tblocks_occupied\n");
	printf("\n%d\t%d\t\t%d\t",a[j].id,a[j].size,a[j].start);
	
	temp = a[j].start;
	for(i=0;i<a[j].nblock;i++)
	{
		printf("%d -> ",temp);
		temp++;
	}
	printf("\n");
}
