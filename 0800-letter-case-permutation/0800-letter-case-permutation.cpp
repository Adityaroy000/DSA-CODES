class Solution {
public:
    void helper(string s,string op,vector<string>& ans){
        if(s.length()==0){
            ans.push_back(op);
            return;
        }
        string op1 = "";
        string op2 = "";

        if(isalpha(s[0])){
            op1 = op;
            op2 = op;

            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin()+0);

            helper(s,op1,ans);
            helper(s,op2,ans);
        }else{
            op.push_back(s[0]);

            s.erase(s.begin()+0);

            helper(s,op,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string op = "";
        vector<string>ans;

        helper(s,op,ans);
        return ans;
    }
};