// problem statement:
// https://www.spoj.com/problems/EKO/

// code:

#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e6+10;//N is the number of trees
long long m;//amount of wood
long long trees[N];
bool iswoodSufficiant(int h){
    long long wood=0;
    for(int i=0;i<n;i++){
        if(trees[i]>=h){
            wood+=(trees[i]-h);
        }
    }
    return wood>=m;
}

int main(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
       cin>>trees[i];
   }
   long long lo=0,hi=1e9,mid;
   //TTTTTFFFFF
   while(hi-lo>1){//O(logh) h=hi
       mid=(hi+lo)/2;
       if(iswoodSufficiant(mid)){//O(N)
           lo=mid;//we need max hight sowe we will go up
       }else{
           hi=mid-1;//don'consider mid bcoz of its false as woodsufficiant returns false
       }

   }//time complexicity=O(Nlogh);
   if(iswoodSufficiant(hi))//we have to find max h so consider hi first
   {
       cout<<hi<<endl;
   }else
     cout<<lo<<endl; 
}
