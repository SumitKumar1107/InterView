#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int inv_count = 0;
    
    i = left;//index of left subarray
    j = mid; //j is index of right subarray
    k = left; // k is index for resultant merged subarray
    
    while((i<=mid-1) && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            //counting inversion
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid-i);
        }
    }
    
    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    
    for(int i=left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}

int mergesort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count = 0;
    
    if(right>left)
    {
        mid = (left+right)/2;
        inv_count += mergesort(arr,temp,left,mid);
        inv_count += mergesort(arr,temp,mid+1,right);
        
        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}


int main()
{
    int arr[] = {5,3,2,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int temp[n];
    
    int ans = mergesort(arr,temp,0,5);
    cout<<"number of inversions "<<ans;
    return 0;
}