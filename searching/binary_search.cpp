#include <iostream>
using namespace std;

/*
 Binary search in sorted array
 If the array is already sorted the complextity is O(logn) else O(logn + nlogn)  */

int main()
{
    int number[] = {1,4,5,6};
    int search = 10;
    int length = sizeof(number)/sizeof(*number);
    int mid;
    int start = 0;
    int end = length-1;
    
   while(start < end)
   {
       
       mid = (start + end)/2;
       
       cout<<"start " << start<<" end"<< end<<" middle"<< mid<<endl;
       if(number[mid] == search)
       {
           cout<<"Found the number "<<search<< "at position "<< mid <<endl;
           return 0;
       }
       else if(search < number[mid])
       {
           end = mid-1;
       }
       else
       {
           start = mid+1;
       }
       
       
   }
    
    cout<<"Number "<<search<< "not found"<< endl;
    return 0;:
}