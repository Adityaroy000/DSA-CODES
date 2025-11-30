class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3 == 0){
            vector<long long>ans;
            long long div = num/3;
            ans.push_back(div-1);
            ans.push_back(div);
            ans.push_back(div+1);
            return ans;
        }
        return {};
    }
};