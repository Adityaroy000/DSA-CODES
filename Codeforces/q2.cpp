#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    vector<string>str;
    string s;
    for(int i = 1; i<=n; i++){
        cin>>s;
        str.push_back(s);
    }
    vector<int>ans;
    for(auto &it : str){
        int cnt = 0;
        if(it.length()>1){
            for(int i = 0; i<it.length()-1; i++){
                if(it[i]==it[i+1]) {
                    cnt++;
                    break;
                }
            }
            if(cnt == 0) ans.push_back(it.length());
            else ans.push_back(1);
        }
        
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
    return 0;
}