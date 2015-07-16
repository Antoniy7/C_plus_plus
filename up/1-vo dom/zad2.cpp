#include<iostream>
using namespace std;
//bool flag=0;
int main()
{
    int date,month,year;
      bool y=0;

    cin>>date>>month>>year;

             //  if (year-1<0) {cout<<abs(year-1)<<" before BC "<<endl; year=-100; bc=true;}
              if (year<0) {cout<<"error"<<endl; y=1; }
             if (date==1 && month==1 && y==0) cout<<"31 "<<"12 "<<year-1<<endl;
             bool flag2=0;   bool flag=0; bool flag1=0;
    	if ( ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0)))
        {    flag2=1;
            if (month==2)
            {
             if (date<29 && date>1)
             {
                 flag=1;
               /*date--;*/  cout<<date-1<<" "<<month<<" "<<year<<endl;
             }

            }
            if (date==1 && month==3)
               { cout<<"29 "<<"2 "<<year<<endl; flag1=1;}
        }
              if (date==1 && month==3 && flag1==0 && y==0) cout<<"28 "<<month-1<<" "<<year<<endl; // dasdasdasasd
           if (date<30 && date>1 && y==0 && (month==4 || month==6 || month==9 || month==11))
               cout<<date-1<<" "<<month<<" "<<year<<endl;
          if (date<=31 && date>1 && y==0 && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                  cout<<date-1<<" "<<month<<" "<<year<<endl;


                 if (date==1 && y==0 && (month==2 || month==4 || month==6 || month==8 || month==9 || month==11))
                 {
                     int d=31;
                     cout<<d<<" "<<month-1<<" "<<year<<endl;
                 }
             if (date==1 && y==0 && (month==5 || month==7 || month==10 || month==12))
                cout<<"30 "<<month-1<<" "<<year<<endl;
                     bool t=0;
                    if (month==2 && date>29)
                    {
                      cout<<"error"<<endl; t=1;
                    }
             if ((date>31 || date==0 || month>12 || month==0 ) && t==0 )
                  cout<<"error"<<endl;
              if (month==2 && flag==0 )
              {
                if (date<=28 && date>1 && y==0)
                {
               /*date--;*/  cout<<date-1<<" "<<month<<" "<<year<<endl;
                }

              }
              if (date==31 && (month==4 || month== 6 || month==9 || month==11)) cout<<"error"<<endl;
               if (month==2 && date==29 && flag2==1) {cout<<date-1<<" "<<month<<" "<<year<<endl; date--;}
              if (month==2 && date==29) cout<<"error"<<endl;

    return 0;
}
