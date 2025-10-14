#include <iostream>
#include<cmath>
#include <string>
using namespace std;
bool isprime(int n) 
{
   if (n<=1)
   return false;
   
    for (int i = 2; i <= sqrt(n); i += 1) 
    {
        if (n % i == 0) 
        return false;
    }
    return true;
}

bool isgood (string s, int i, int size, bool b)
{
   
    if (i>=size)
    return b;
     int digit = s[i] - '0';
    if (i%2==0 && digit%2!=0)
    {
       b=false;
    }
   else if (i%2!=0 && !isprime(digit))
    {
       b= false;
    }
   
   return isgood(s,i+1,size,b);
   
}
int main() {
    string s;
    bool b=true;
   cout<<"Enter string: ";
   cin>>s;
   cout<<"It is: ";
    int size=s.length();
   cout<<isgood(s,0,size,b);
    return 0;
}