#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 struct node *lchild;
 int info;
 struct node *rchild;	
}node;

node *search( node *ptr, int skey);
node *insert( node *ptr,int ikey);
node *del( node *ptr,int dkey);
void levelorder( node *ptr);
void displaygivenlevel( node *ptr,int level);
void preorder(node* ptr);
void postorder(node *ptr);
void inorder(node* ptr);

int main()
{
	 node *root=NULL, *ptr;
	 int choice,data;
	 while(1)
  {
   printf("\n1.Search.\n");
   printf("2.Insert.\n");
   printf("3.Delete.\n");
   printf("4.Display.\n");
   printf("5.preorder \n");
   printf("6.postorder \n");
   printf("7.inorder \n");
   printf("8.Exit.\n");
   printf("\nEnter your choice: \n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:printf("\nEnter element to be searched: \n");
           scanf("%d",&data);
           ptr=search(root,data);
           if(ptr==NULL)
             printf("\nKey not present.");
           else
             printf("\nKey is present.");
           break;

    case 2:printf("\nEnter element to be inserted: ");
           scanf("%d",&data);
           root=insert(root,data);
           break;

    case 3:printf("\nEnter element to be deleted: ");
           scanf("%d",&data);
           root=del(root,data);
           break;

    case 4:printf("\nThe Tree elements are displayed in Levelorder Traversal: \n");
           levelorder(root);
           break;

    case 5:preorder(root);
           break;

    case 6:postorder(root);
    break;

    case 7:inorder(root);
    break;
           
       case 8:
           exit(1);
       default:
            printf("\nINVALID INPUT");
   }
	}	
}

 node *search( node *ptr, int skey){
	if(ptr==NULL){
		printf("\nKey not found\n");
		return NULL;
	}
	else if(skey<ptr->info)
	  return search(ptr->lchild,skey);
	else if(skey>ptr->info)
	  return search(ptr->rchild,skey);
	else
	  return ptr;
}

 node *insert( node *ptr,int ikey){
	if(ptr==NULL){
		ptr=( node *)malloc(sizeof( node));
		ptr->info=ikey;
		ptr->lchild=NULL;
		ptr->rchild=NULL;
	}
	else if(ikey < ptr->info)
	  ptr->lchild=insert(ptr->lchild,ikey);
	else if(ikey > ptr->info)
	  ptr->rchild=insert(ptr->rchild,ikey);
	else
	 printf("Duplicate Key \n");
	return ptr;
}

 node *del( node *ptr,int dkey){
	 node *tmp,*succ;
	if(ptr==NULL){
		printf("%d not present in Tree\n",dkey);
		return ptr;
	}
	if(dkey < ptr->info)
	  ptr->lchild=del(ptr->lchild,dkey);
	else if(dkey > ptr->info)
      ptr->rchild=del(ptr->rchild,dkey);
    else{
    	
    	if(ptr->lchild!=NULL && ptr->rchild!=NULL){
    		succ=ptr->rchild;
    		while(succ->lchild!=NULL)
    		 succ=succ->lchild;
    		ptr->info=succ->info;
    		ptr->rchild=del(ptr->rchild,succ->info);
    	}
    	else{
    		tmp=ptr;
    		if(ptr->lchild!=NULL)
    		  ptr=ptr->lchild;
    		else if(ptr->rchild!=NULL)
    		  ptr=ptr->rchild;
    		else
    		  ptr=NULL;
    		free(tmp);
    	}
    }
    return ptr;
}

int height( node *ptr){
	int hleft,hright;
	if(ptr==NULL)
	 return 0;
	hleft=height(ptr->lchild);
	hright=height(ptr->rchild);
	if(hleft>hright)
	  return 1+hleft;
	else
	  return 1+hright;
}

void levelorder( node *ptr){
	int h=height(ptr);
	int i;
	for(i=1;i<=h;i++)
	  displaygivenlevel(ptr,i);
}

void displaygivenlevel( node *ptr,int level){
	if(ptr==NULL)
	  return;
	if(level==1)
	  printf("%d ",ptr->info);
	else if(level>1){
		displaygivenlevel(ptr->lchild,level-1);
		displaygivenlevel(ptr->rchild,level-1);
	}
}

void preorder(node* ptr) 
{ 
	if (ptr == NULL) 
    return; 
	printf("%d ", ptr->info);   
	preorder(ptr->lchild);  
	preorder(ptr->rchild); 
}     

void postorder(node *ptr) 
{ 
	if (ptr == NULL) 
    return; 
	postorder(ptr->lchild); 
	postorder(ptr->rchild); 
	printf("%d ",ptr->info); 
} 

void inorder(node* ptr) 
{ 
	if (ptr == NULL) 
	return; 
	inorder(ptr->lchild); 
    printf("%d ", ptr->info);   
	inorder(ptr->rchild); 
} 