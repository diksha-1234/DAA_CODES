#include<stdio.h>
int BinarySearch(int arr[],int lb,int ub,int key)
{
    int mid;
    while(lb<=ub)
    {
    mid=lb+(ub-lb)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        ub=mid-1;
    }
    else{
        lb=mid+1;
    }
    }
    return -1;
}
int main()
{
    int arr[50],n,i,key,index,lb,ub;
    printf("enter the size of an array");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    lb=0;
    ub=n-1;
    printf("enter the key to be searched");
    scanf("%d",&key);
    index=BinarySearch(arr,lb,ub,key);
    if(index!=-1)
    {
        printf("element found at index %d",index);
    }
    else{
        printf("element not found");
    }
}