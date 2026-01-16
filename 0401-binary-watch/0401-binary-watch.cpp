class Solution {
public:
    vector<int>hr = {8,4,2,1};
    vector<int>mn = {32,16,8,4,2,1};
    vector<string>ans;
    void solve(int idx, int turnedOn, int h, int m){
        if(h>11 || m > 59) return;

        if(turnedOn == 0){
            string time = to_string(h)+":";
            if(m<10) time += "0";
            time += to_string(m);
            ans.push_back(time);
            return;
        }

        if(idx == 10) return;

        if(idx<4) solve(idx+1,turnedOn-1,h+hr[idx],m);
        else solve(idx+1, turnedOn-1,h,m+mn[idx-4]);

        solve(idx+1,turnedOn,h,m);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        solve(0,turnedOn,0,0);
        
        return ans;
    }
};