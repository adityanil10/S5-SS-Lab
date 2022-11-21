#include <stdio.h>
#include <stdlib.h>

struct node {
  char name[10];
  struct node* next[10];
  int fcnt;
};

// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->name = value;
  newNode->next[0] = NULL;
  newNode->fcnt = 0;

  return newNode;
}

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// Insert on the right of the node
struct node* insertR(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int i,ch,dcnt,k;
	char f[30], d[30];
	dcnt=0;
	
	struct node* root = createNode("root");
	//insertR(root, 3);

    //printf("Inorder traversal \n");
    //inorderTraversal(root);

	
	while(1)
	{
		printf("\n\n1. Create File or Folder\t3. Delete File or Folder\t4. Search File\t5. Display Files\t6. Exit\nEnter your choice -- ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
				
				break;
			
			case 2: 
				printf("\nEnter name of the directory -- ");
				scanf("%s",d);
				
				for(i=0;i<dcnt;i++)
					if(strcmp(d,dir[i].dname)==0)
					{
						/*
						printf("Enter name of the file -- ");
						scanf("%s",dir[i].fname[dir[i].fcnt]);
						printf("File created");
						break;
						*/
						
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
				
				/*
				printf("\nEnter the name of the file -- ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f, dir.fname[i])==0)
					{
						printf("File name %s already exists ", f);
						break;
					}
				}
				if(i==dir.fcnt)
				{
					printf("File %s not found",f);
					strcpy(dir.fname[dir.fcnt],f);
					dir.fcnt++;
				}
				break;
				*/
			
			case 3: 
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
				
				case 4: 
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
			
			case 5: 
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
