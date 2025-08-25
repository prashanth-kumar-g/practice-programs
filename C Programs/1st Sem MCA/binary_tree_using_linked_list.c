// Program for binary tree implemetation using doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node* createNode(int ele)
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->left=NULL;
	new->data=ele;
	new->right=NULL;
	return new;
}

struct node* insertNode(struct node *root, int ele)
{
	if(root==NULL)
	{
		return createNode(ele);
	}
	char ch;
	printf("\n Insert %d to the left or right of %d (L/R) : ",ele,root->data);
	scanf(" %c",&ch);
	if(ch=='l' || ch=='L')
	{
		root->left=insertNode(root->left,ele);
	}
	else
	{
		root->right=insertNode(root->right,ele);
	}
	return root;
}

void preorderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d --> ",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void postorderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d --> ",root->data);
	}
}


void inorderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		inorderTraversal(root->left);
		printf("%d --> ",root->data);
		inorderTraversal(root->right);
	}
}

int main()
{
	struct node *root=NULL;
	int ch,ele;
	while(1)
	{
		printf("\n------------------------------------------------------------------------------");
		printf("\n                       BINARY TREE IMPLEMENTATION                             ");
	        printf("\n                      ----------------------------                            ");
		printf("\n      1) Insert Node    2) Preorder Traversal    3) Inorder Traversal         ");
		printf("\n      4) Postorder Traversal    5) Exit                                       ");
		printf("\n------------------------------------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Inserted : ");
				scanf("%d",&ele);
				root=insertNode(root,ele);
				printf("\n The Element %d is Inserted \n",ele);
				break;
			case 2: printf("\n Preoder Traversal : ");
				preorderTraversal(root);
				printf("NULL \n");
				break;
			case 3: printf("\n Inoder Traversal : ");
				inorderTraversal(root);
				printf("NULL \n");
				break;
			case 4: printf("\n Postoder Traversal : ");
				postorderTraversal(root);
				printf("NULL \n");
				break;
			case 5: printf("\n Exiting... \n\n");
				exit(0);
			default: printf("\n Invalid Choice, Select Again. \n");
				 break;
		}
	}
	return 0;
}
