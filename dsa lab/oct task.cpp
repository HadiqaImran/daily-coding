#include <iostream>
using namespace std;
void dec2oct (int n)
{
    if (n<=0)
    {
        return;
    }
    else
    dec2oct(n/8);
   cout<<n%8;
}
int main() {
    int n;
   cout<<"Enter num: ";
   cin>>n;
   cout<<"OCT value is: ";
   dec2oct(n);


    return 0;
}