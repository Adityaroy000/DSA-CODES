#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int cost = 0;
    for(int i = 1; i<=w; i++){
        cost += (i*k);
    }
    int left = cost - n;
    if(left < 0 ) cout<<0<<endl;
    else cout<<left<<endl;
    return 0;
}