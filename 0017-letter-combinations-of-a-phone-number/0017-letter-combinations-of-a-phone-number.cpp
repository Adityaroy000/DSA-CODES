class Solution {
public:
    vector<string>ans;
    string res;
    void help(int idx,string digits,unordered_map<char,string>& mpp){
        if(idx==digits.size()){
            ans.push_back(res);
            return;
        }

        for(char ch : mpp[digits[idx]]){
            res.push_back(ch);
            help(idx+1,digits,mpp);
            res.pop_back();
        }
    } 
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<char,string>mpp{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        help(0,digits,mpp);

        return ans;
    }
};