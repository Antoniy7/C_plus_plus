#include<iostream>
using namespace std;
int main()
{
    double x,y;
    bool flag=false;
    cin>>x>>y;
           if (y==0 && (x==-1 || x==1 || x==2 || x==-2))
                {
                  cout<<"bravo"<<endl;  flag=true;
                }
        if (y>0)
         {
           if (x*x+y*y<=4)
            cout<<"bravo"<<endl;
         else cout<<"ne"<<endl;
         }

           if (y<0)
           {
                if (x<=1 && x>=-1 && y<=-2)
                cout<<"bravo"<<endl;
                else cout<<"ne"<<endl;
           }
             if (y==0 && flag==false)
             {
                   if ((x<2 && x>1) || (x<-1 && x>-2))
                     cout<<"bravo"<<endl;
                 else cout<<"ne"<<endl;
             }

     return 0;
}
