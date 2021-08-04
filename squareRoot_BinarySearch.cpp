#include<bits/stdc++.h>
using namespace std;
double z =1e-6;
double multiply(double mid , int n){
    double ans=1;
    for(int i=0;i<n;i++){
        ans*=mid;//multiplying mid n times ;
    }
    return ans;
}
int main(){
    double x;
    int n;
    cin>>n;
    cin>>x;
        double low=1,hi=x,mid;
        while(hi-low>z){
            mid=(low+hi)/2; 
            if(multiply(mid,n)<x)//       for finding nth root like x^n
            //if(mid*mid<x)   used for finding sqrt
            {
               low=mid;
            }else{
                hi=mid;
            }
        }
        cout<<setprecision(10)<<low<<endl;
        cout<<pow(x,1.0/n);//both are same 
        
}