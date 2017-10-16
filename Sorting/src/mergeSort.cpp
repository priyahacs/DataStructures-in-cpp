#include<iostream>

using namespace std;


void merge(int arr[],int l,int mid,int r)
{
    int n1,n2;
    int i,j,k;
    
    n1 = mid-l+1;
    n2 = r-mid;
    
    int temp1 [n1];
    int temp2[n2];
    
    for(i =0;i< n1;i++)
    {
        temp1[i] = arr[l+i];
    }
    
    for(i= 0 ;i< n2;i++)
    {
        temp2[i] = arr[mid+1+i];
    }
    i= 0,j=0,k=0;
    while(i< n1 && j< n2)
    {
        if(temp1[i] <= temp2[j])
        {
            arr[l+k] = temp1[i];
            i++;
           
        }
        else if( temp1[i] > temp2[j])
        {
            arr[l+k] = temp2[j];
            j++;
        }
         k++;
    }
    
    while(i<n1)
    {
        arr[l+k] = temp1[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        arr[l+k] = temp2[j];
        j++;
        k++;
    }
    
    return;
    
}






void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        
        merge(arr,l,mid,r);
    }
    
    return;
}


int main()
{
    int arr[] = {38,27,43,3,9,82,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int l = 0;
    int r = size-1;
    
    mergeSort(arr,l,r);
    
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}