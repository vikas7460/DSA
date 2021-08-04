#include<bits/stdc++.h>
using namespace std;
int upperbound(vector<int> &v,int element){//upperbound means just bigger element so eleminate = condition as well
    int low =0,hi=v.size()-1;
    int mid;
    while(hi-low>1){
         mid=(low+hi)/2;
         if(v[mid]<=element){
             low=mid+1;

         }else{
             hi=mid;
         }
    }
    if(v[low]>element){//first consider lower index lo then hi if 4 is found at 3 no need to go at 4 index
           return low;
    } if(v[hi]>element){
        return hi;
    }
    return -1;
    

}
int lowerbound(vector<int> &v,int element){// lower bound means that element and just bigger than that element
    int low =0,hi=v.size()-1;
    int mid;
    while(hi-low>1){
         mid=(low+hi)/2;
         if(v[mid]<element){
             low=mid+1;//+1 bcoz mid is smaller than our element;

         }else{
             hi=mid;//mid  included bcoz it may be our lb;
         }
    }
    if(v[low]>=element){//first consider lower index lo then hi if 4 is found at 3 no need to go at 4 index
           return low;
    } if(v[hi]>=element){
        return hi;
    }
    return -1;
    

}
int main(){
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   sort(v.begin(),v.end());
   int element;
   cin>>element;//whose lower bound is to be found
   int lb=lowerbound(v,element);
   cout<<"lower bound index:"<<lb<<endl;
   cout<<"lower bound element is:"<<v[lb]<<endl;
   int ub=upperbound(v,element);
   cout<<"upperbound index:"<<ub<<endl;
   cout<<"upperbound element is:"<<v[ub]<<endl;

}