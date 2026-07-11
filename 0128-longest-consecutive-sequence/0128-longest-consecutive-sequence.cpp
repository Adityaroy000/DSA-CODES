class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;

        set<int>st(nums.begin(),nums.end());

        int cnt = 1,maxi=INT_MIN;
        vector<int>temp;
        for(auto it : st){
            temp.push_back(it);
        }

        int s = temp.size();

        for(int i=1;i<s;i++){
            if(temp[i] == temp[i-1]+1) cnt++;
            else{
                maxi = max(maxi,cnt);
                cnt = 1;
            }
        }

        maxi = max(maxi,cnt);

        return maxi;

    }
};