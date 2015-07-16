#include<iostream>
using namespace std;

int main()
{
    int n,br=0;
    cin>>n;
   unsigned long long  g;
    unsigned long long p=0;

     while (n!=br)
    {
             p++;
            g=p*p;
      if (g%10==p || g%100==p || g%1000==p || g%10000==p || g%100000==p || g%1000000==p || g%10000000==p || g%100000000==p || g%1000000000==p || g%10000000000==p || g%100000000000==p || g%1000000000000==p || g%10000000000000==p || g%100000000000000==p || g%1000000000000000==p)
        {
            cout<<p<<endl; br++;
        }
     }
    return 0;
}
