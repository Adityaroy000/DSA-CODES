class Solution {
public:
/*
Suppose you start at i and go right first.

First time you hit a positive → you consume 1 from the right side → so right side had R units, now R-1.

Direction flips to left → you travel left until you hit a positive → consume 1 from the left side → L-1.

Flip again, go right, consume 1 from right, and so on…

So the sequence of consumed units, by side, looks like:

Starting right: R, L, R, L, R, L, ...

Starting left: L, R, L, R, L, R, ...

You alternate sides when consuming positives.

We will consume units in the order:
R, L, R, L, R, L, ...
For it to end with all zeros, we must be able to consume:
exactly R units from the right side, and
exactly L units from the left side.
Think about counts:
If L = R
Then the sequence is R, L, R, L, ... and both sides can be fully consumed while alternating. Possible ✅
If R = L + 1
Sequence: R, L, R, L, ..., R → right side has exactly one more unit, so we still can alternate and end after taking the last unit from the right. Possible ✅
*/
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt  = 0;
        vector<int>psum(n),ssum(n);

        for(int i=1;i<n;i++){
            psum[i] = psum[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            ssum[i] = ssum[i+1]+nums[i+1];
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int L = psum[i];
                int R = ssum[i];

                if(R == L) ans += 2;
                else if(abs(L-R)==1) ans += 1;
            }
        }
        return ans;
    }
};