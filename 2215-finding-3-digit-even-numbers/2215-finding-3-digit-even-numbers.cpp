class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[digits[i]]++;
        }
        sort(digits.begin(),digits.end());
        int maxEle = digits[n-1];
        int limit = maxEle*100 + maxEle*10 + maxEle;
        int minEle = digits[0];
        int low = 0;
        if(minEle == 0) low = 100;
        else low = minEle*100 + minEle*10 + minEle;
        for(int i = low;i<=limit;i++){
            int temp = i;
            if(i%2==0){
                vector<int>threeDigit;
                while(temp>0){
                    threeDigit.push_back(temp%10);
                    temp = temp/10;
                }
                unordered_map<int,int>count;
                for(int i= 0;i<3;i++){
                    count[threeDigit[i]]++;
                }
                bool flag = true;
                for(auto &it : count){
                    int key = it.first;
                    int freq = it.second;
                    if(mpp.find(key)!=mpp.end() && mpp[key]>=freq){
                        flag = true;
                    }else {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans.push_back(i);
            }
        }
        return ans;
    }
};