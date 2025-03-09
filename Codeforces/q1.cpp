#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    int ans ;
    int temp = n;
    if(n>5){
        ans = temp/5;
        int rem = temp%5;
        if(rem!=0) ans = ans+1;
    }else{
        ans = 1;
    }
    cout<<ans<<endl;
    return 0;
}