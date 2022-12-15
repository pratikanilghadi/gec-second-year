#include<stdio.h>
#define MAX 100

int linear(int arr[],int size,int skey);
int binary(int arr[],int low,int up,int skey);
void selection(int arr[],int n);
void bubble(int arr[],int n);
void insertion(int arr[],int n);
void merge_sort(int arr[],int low,int up);
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void copy(int arr[],int temp[],int low,int up);

int main()
{
 int choice,n,arr[MAX],search,s;

 while(1)
 {
  printf("\n1-Linear Search\n");
  printf("2-Binary Search\n");
  printf("3-Bubble Sort\n");
  printf("4-Selection Sort\n");
  printf("5-Insertion Sort\n");
  printf("6-Merge Sort\n");
  printf("7-Exit\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);

  switch(choice)
  {
   case 1:printf("How many elements you want to enter in the array : ");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
           printf("Enter the element: ");
           scanf("%d",&arr[i]);
          }
          printf("Enter the element to be searched: ");
          scanf("%d",&search);
          s=linear(arr,n,search);
          if(s!=-1)
          {
           printf("Element found at position %d \n",s+1);
          }
          else
          {
           printf("Element not found\n");
          }
          break;

   case 2:printf("How many elements you want to enter in the array : ");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
           printf("Enter the element: ");
           scanf("%d",&arr[i]);
          }
          printf("Enter the element to be searched: ");
          scanf("%d",&search);
          s=binary(arr,0,n-1,search);
          if(s!=-1)
          {
           printf("Element found at position %d \n",s+1);
          }
          else
          {
           printf("Element not found\n");
          }
          break;

   case 3:printf("How many elements you want to enter in the array : ");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
           printf("Enter the element: ");
           scanf("%d",&arr[i]);
          }
          printf("Unsorted Array is : ");
          for(int i=0;i<n;i++)
          {
              printf("%d ",arr[i]);
          }
          printf("\n");
          bubble(arr,n);
          break;

   case 4:printf("How many elements you want to enter in the array : ");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
           printf("Enter the element: ");
           scanf("%d",&arr[i]);
          }
          printf("Unsorted Array is : ");
          for(int i=0;i<n;i++)
          {
              printf("%d ",arr[i]);
          }
          printf("\n");
          selection(arr,n);
          break;

   case 5:printf("How many elements you want to enter in the array : ");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
           printf("Enter the element: ");
           scanf("%d",&arr[i]);
          }
          printf("Unsorted Array is : ");
          for(int i=0;i<n;i++)
          {
              printf("%d ",arr[i]);
          }
          printf("\n");
               insertion(arr,n);
          break;

   case 6:printf("How many elements you want to enter in the array : ");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
           printf("Enter the element: ");
           scanf("%d",&arr[i]);
          }
          printf("Unsorted Array is : ");
          for(int i=0;i<n;i++)
          {
              printf("%d",arr[i]);
          }
          printf("\n");
          merge_sort(arr,0,n-1);
          printf("\nSorted array : ");
          for(int i=0;i<n;i++)
          {
           printf("%d ",arr[i]);
          }
          break;
  }
 }
}

int linear(int arr[],int size,int skey)
{
 int i=0;
 while(i<size && skey!=arr[i])
 {
  i++;
 }
 if(i<size)
 {
  return i;
 }
 else
 {
  return -1;
 }
}

int binary(int arr[],int low,int up,int skey)
{
       int mid;
       if(low>up)
       {
              return -1;
       }
       mid=(low+up)/2;
       if(skey<arr[mid])
       {
              binary(arr,low,mid,skey);
       }
       else if(skey>arr[mid])
       {
              binary(arr,mid+1,up,skey);
       }
       else
       {
              return mid;
       }
       return 0;
}

void selection(int arr[],int n)
{
       for(int i=0;i<n-1;i++)
       {
              int min=i;
              for(int j=i+1;j<n;j++)
              {
                     if(arr[min]>arr[j])
                     {
                            min=j;
                     }
                     
              }
              if(i!=min)
              {
                     int temp=arr[i];
                     arr[i]=arr[min];
                     arr[min]=temp;
              }
                     printf("Pass %d :",i+1);
                     for(int i=0;i<n;i++)
                     {
                            printf("%d ",arr[i]);
                     }
                     printf("\n");


       }
       printf("Sorted array : ");
       for(int i=0;i<n;i++)
       {
              printf("%d ",arr[i]);
       }
       printf("\n");
}

void bubble(int arr[],int n)
{
       int change=0;
       for(int i=0;i<n-1;i++)
       {
              change=0;
              for(int j=0;j<n-1-i;j++)
              {
                     if(arr[j]>arr[j+1])
                     {
                            int temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                            change++;
                     }
                     
              }
              if(change==0)
              {
                     break;
              }
               printf("Pass %d :",i+1);
                     for(int i=0;i<n;i++)
                     {
                            printf("%d ",arr[i]);
                     }
                     printf("\n");
              
       }
       printf("Sorted array : ");
       for(int i=0;i<n;i++)
       {
              printf("%d ",arr[i]);
       }
       printf("\n");

}

void insertion(int arr[],int n)
{
       int i,j,k;
       for(i=1;i<n;i++)
       {
              k=arr[i];
              for(j=i-1;j>=0 && k<arr[j];j--)
              {
                     arr[j+1]=arr[j];
              }
              arr[j+1]=k;
              printf("Pass %d: ",i);
              for(int t=0;t<n;t++)
              {
                     printf("%d ",arr[t]);
              }
              printf("\n");
       }
       printf("Sorted array : ");
       for(int i=0;i<n;i++)
       {
              printf("%d ",arr[i]);
       }
       printf("\n");
}

void merge_sort(int arr[],int low,int up)
{
       int mid;
       int temp[MAX];
       if(low<up)
       {
              mid=(low+up)/2;
              merge_sort(arr,low,mid);
              merge_sort(arr,mid+1,up);
              merge(arr,temp,low,mid,mid+1,up);
              copy(arr,temp,low,up);
       }
}

void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
       int i=low1,j=low2,k=low1;
       while((i<=up1) && (j<=up2))
       {
              if(arr[i]<= arr[j])
              {
                     temp[k++]=arr[i++];
              }
              else
              {
                     temp[k++]=arr[j++];
              }
       }
       while(i<=up1)
       {
              temp[k++]=arr[i++];
       }
       while(j<=up2)
       {
              temp[k++]=arr[j++];
       }  
       
}

void copy(int arr[],int temp[],int low,int up)
{
       int i;
       for(int i=low;i<=up;i++)
       {
              arr[i]=temp[i];
       }
}