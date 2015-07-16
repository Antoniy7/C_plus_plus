#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


void randomShuffle(vector<int> v){
    for(int i=0;i<v.size();i++){
        v[i]=v[rand()%(i+1)];
    }
}

void insertionSort(vector<int> &v){
    int j,tmp;
    for(int i=1;i<(int)v.size();i++){
        j=i;
        while(j>0 && v[j-1]>v[j]){
            tmp=v[j];
            v[j]=v[j-1];
            v[j-1]=tmp;
            j--;
        }
    }
}

void quicksort(vector<int> &v){
    if((int)v.size()<14){
        insertionSort(v);
        return;
    }
    int pivot = v[v.size()/2];
    vector<int> v1,v2,vp;
    v1.reserve(v.size());
    v2.reserve(v.size());
    for(int i=0;i<(int)v.size();i++){
        if(v[i]<pivot){
            v1.push_back(v[i]);
        }
        else if(v[i]==pivot){
            vp.push_back(v[i]);
        }
        else{
            v2.push_back(v[i]);
        }
    }
    quicksort(v1);
    quicksort(v2);

    v.clear();
    v.insert(v.end(),v1.begin(),v1.end());
    v.insert(v.end(),vp.begin(),vp.end());
    v.insert(v.end(),v2.begin(),v2.end());


}

int main()
{
    vector<int> a;
    int t;
    int tmp;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&tmp);
        a.push_back(tmp);
    }
    quicksort(a);
    for(int i=0;i<(int)a.size()-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[a.size()-1]);
}

