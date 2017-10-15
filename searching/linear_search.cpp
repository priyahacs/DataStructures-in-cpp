#include <iostream>
using namespace std;

int main()
{
    int number[5] = {1,5,4,6,7};
    int search = 10;
    
    for(int i =0;i< sizeof(number)/sizeof(*number);i++)
    {
     if(number[i] == search)
     {
         cout<<"Found the number "<<search<< "at position "<< i<<endl;
         return 0;
     }
    }
    
    
    cout<<"Number "<<search<< "not found"<< endl;
    return 0;
 }