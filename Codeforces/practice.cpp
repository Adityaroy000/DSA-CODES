#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    vector<int>ans;
    for(int k = 0; k<t; k++){
        cin>>n;
        string str1;
        cin>>str1;
        int I = n-1,r = 0;
        for(int i = 0; i<n; i++){
            if(str1[i]=='A'){
                I = i;
                break;
            }
        }
        for(int i = n-1; i>=0; i--){
            if(str1[i]=='B'){
                r = i;
                break;
            }
        }
        ans.push_back(max(0,(r-I)));
    }
    for(auto it: ans){
        cout<<it<<endl;
    }
    
    return 0;
}