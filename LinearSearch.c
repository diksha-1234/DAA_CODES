#include<stdio.h>
int LinearSearch(int arr[],int n,int key)
{
for(int i=0;i<n;i++)
{
    if(arr[i]==key)
    return i;
}
return -1;
}
int main()
{
    int arr[50];
    int n,i;
    int key;
    printf("enter the size of an array");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter key to be searched");
    scanf("%d",&key);
    int index=LinearSearch(arr,n,key);
    if(index!=-1){
        printf("element found at index %d",index);
    }
    else{
        printf("element not found");
    }
    return 0;
}