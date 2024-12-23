#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *rchild,*lchild;
 };
typedef struct node *NODE;

NODE createbst(NODE,int);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE searchkey(NODE,int);

void main()
 {
  NODE root=NULL;
  int ch,item,n,i,key;
  do
  {
   printf(".....binary search tree operations....\n");
   printf("1.create BST\n2.inorder traversal\n3.pre order traversal\n4.post order traversal\n5.search\n6.exit\n");
   printf("enter your choice");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1: printf("\n\nBST for how many nodes?:");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
             printf("\nenter the data for node %d:",i);
             scanf("%d",&item);
             root=createbst(root,item);
             }
printf("\n BST created\n");
break;
    case 2: printf("\nBST traversal in inorder\n");
            inorder(root);
            break;
     case 3: printf("\nBST trversal inpreorder\n");
            preorder(root);
            break;
      case 4: printf("\nBST trversal in postorder\n");
            postorder(root);
             break;
      case 5: printf("enter the key element to be searched:\n");
               scanf("%d",&key);
            searchkey(root,key);
              break;
       case 6: exit(0);
              break;
    default:printf("\n\ninvalid option!try again!\n\n");
}
}
while(ch!=6);
}


NODE createbst(NODE root,int item)
 {
  if(root==NULL)
   {
    root=(NODE)malloc(sizeof(struct node));
    root->lchild=root->rchild=NULL;
    root->data=item;
    return root;
  }
 else if(item<root->data)
     root->lchild=createbst(root->lchild,item);
 else if(item>root->data)
     root->rchild=createbst(root->rchild,item);
 else
    printf("dublicate element not allowed!");
  return(root);
 }
  void inorder(NODE root)
   {
    if(root!=NULL)
     {
      inorder(root->lchild);
      printf("%d",root->data);
      inorder(root->rchild);
      }
    }
 

void preorder(NODE root)
 {
  if(root!=NULL)
   {
    printf("%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
   }
  }


void postorder(NODE root)
  {
   if(root!=NULL)
    {
     postorder(root->lchild);
     postorder(root->rchild);
     printf("%d",root->data);
     }
}

NODE searchkey(NODE root,int key)
 {
  int flag=0;
  if(root==NULL)
   {
    printf("BST is empty\n");
    return;
   }
 while(root!=NULL)
  {
   if(key==root->data)
   {
    flag=1;
    break;
   
   }
  if(key<root->data)
   {
    root=root->lchild;
   }
   else
    {
    root=root->rchild;
    }
  }
if(flag==1)
   {
   printf("key element %d is found in BST\n",key);
   }
else
   {
   printf("key element %d is not found in BST\n",key);
   }
}

