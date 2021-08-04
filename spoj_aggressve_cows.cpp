/* problem statement:
https://www.spoj.com/problems/AGGRCOW/
code:
*/
#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,cows;//N is just the max of n
long long positions[N];
bool canPlaceCows(long long minDistant){
    long long lastpos=-1;
    long long cows_count=cows;
    for(long long i=0;i<n;i++){
        if(positions[i]-lastpos>=minDistant||lastpos==-1){//lastpos==-1 just for first cow
            cows_count--;
            lastpos=positions[i];//cows has been put at i and lastpos has been updated
        }
        if(cows_count==0)break;
    }
    return cows_count==0;//all cows is placed

}
int main(){
    long long t;
    cin>>t;
    while(t--){
        cin>>n>>cows;
        for(long long i=0;i<n;i++){
            cin>>positions[i];
        }
        sort(positions,positions+n);
        //tttttfffffff
        long long low=0,hi=1e9,mid;//hi is max length of array so it is max distance also;
        while(hi-low>1){
            mid=(low+hi)/2;
            if(canPlaceCows(mid)){
                low=mid;
            }else{
                hi=mid-1;//mid is false so mid is discarded
            }
        }
        if(canPlaceCows(hi)){
            cout<<hi<<endl;
        }else{
            cout<<low<<endl;
        }
    }
}