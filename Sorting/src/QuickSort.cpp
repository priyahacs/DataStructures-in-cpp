#include<iostream>

using namespace std;


void swap(int *one, int * two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}


int partition(int arr[], int l,int r)
{
    int part = arr[r];
    
    int i = l-1;
    
    for(int j= l;j<r;j++)
    {
        if(arr[j] <= part)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    
    swap(&arr[i+1],&arr[r]);
    return i+1;

}


void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int part =  partition(arr,l,r);
        
        quickSort(arr,l,part-1);
        quickSort(arr,part+1,r);
       
    }
    
    return;
}


int main()
{
    int arr[] = {38,27,43,3,9,82,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int l = 0;
    int r = size-1;
    
    quickSort(arr,l,r);
    
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}