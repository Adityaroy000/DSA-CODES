#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    string s;
    cin>>s;

    int cnt  = 0;
    int len = s.length();
    if(len == 1) cout<<0<<endl;
    if(len == 2) {
        if(s[0]!=s[1]) cout<<0<<endl;
        else cout<<1<<endl;
    }
    if(len>=3){
        int left = 0;
        int mid = left+1;
        int right = mid+1;

        for(int i = 0;i<len; i++){
            if(s[left] == s[mid] && left<len && mid<len){
                cnt++;
                if(right<len && s[left] != s[right] ){
                    left = left+2;
                    mid = left+1;
                    right = mid+1;
                }else{
                    left++;
                    mid++;
                    right++;
                }
                
                if(right>=len || left>=len || mid >=len) break;
            }else{
                left++;
                mid++;
                right++;
                if(right>=len || left>=len || mid >=len) break;
            }
        }
        if(cnt != 0 && s[left] == s[mid]){
            cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}