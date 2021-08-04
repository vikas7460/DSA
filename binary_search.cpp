#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());//need to be sorted to use binary search;
    int to_find;
    cin>>to_find;
    int low=0,hi=n-1;
     int mid;
     while(hi-low>1){
         mid=(hi+low)/2;
         if(v[mid]<to_find){
             low=mid+1;
         }else{
             hi=mid;//= bcoz of v[mid]>=to_find;
         }
     }
     if(v[low]==to_find){
         cout<<"index is :"<<low<<endl;
     }else if(v[hi]==to_find){
         cout<<"index is :"<<hi<<endl;
     }else{
         cout<<" not found";
     }
}