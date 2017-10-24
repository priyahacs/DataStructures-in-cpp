#include<iostream>
using namespace std;


void swap(int * A, int * B)
{
    
    int temp = *A;
    *A  = *B;
    *B= temp;
    
    return;
}



void bubbleSort(int arr[],int length)
{
    bool swapped = false;
    for(int i=0;i<length-1;i++)
    {
        swapped = false;
        for(int j= 0;j<length-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapped = true;
                swap(&arr[j],&arr[j+1]);
            }
        }
        
        if(swapped == false)
        {
            break;
        }
        
    }
    
    cout<<"Array afer sorting:"<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<arr[i];
    }
    
    return;
}


int main()
{
    int arr[] = {5,1,4,2,8};
    
    int size  = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Size of array is:"<<size<<endl;
    bubbleSort(arr, size);
    cout<<endl;
    return 0;
    
}