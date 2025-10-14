#include <iostream>
#include<cmath>
#include <string>
using namespace std;
int count (int n)
{
   
    if (n==1)
    return 1;
    if (n==2)
    return 2;
   
   return count(n-1) + count (n-2);
   
}
int main() {
    int n;
   cout<<"Enter num: ";
   cin>>n;
   cout<<"Total ways are: ";
   cout<<count(n);
    return 0;
}