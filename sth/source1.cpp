#include <iostream>
#include<fstream>

using namespace std;

int main()
{

ifstream inputFile("test.txt",ios::in);

if(!inputFile.is_open())
{
    cerr<<"Cannot open file";
    return 1;
}
ofstream outputFile ("result.txt",ios::out);

if(!outputFile)
  {
       cerr<<"Cannot open outputFile";
       return 1 ;
  }
bool canRead= true;
do{
    int number;
    inputFile>>number;
    if(inputFile.good())
    {
        outputFile<<number<<endl;
    }
    else
    {
        if(inputFile.eof())
            {
                canRead= false;
                break;
            }
        else if(inputFile.bad())
            {
                cerr<<"BAD state";
                return 1 ;
            }
        else if(inputFile.fail())
            {
                inputFile.clear();
                char c;
                while(inputFile.get(c) && c!= '\n');
                if(!inputFile)
                    canRead=false;
            }
    }

}
while(canRead);

outputFile.close();
inputFile.close();

    return 0;
}
