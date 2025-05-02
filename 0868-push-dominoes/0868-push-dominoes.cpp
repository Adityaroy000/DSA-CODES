class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        
        vector<int>left_closest_r(n,-1);
        vector<int>right_closest_l(n,-1);
        //Left to right traversal to find right push
        for(int i=0;i<n;i++){
            if(i==0){
                if(dominoes[i]=='R') left_closest_r[i] = i;
            }else if(dominoes[i]=='R'){
                left_closest_r[i]=i;
            }else{
                if(left_closest_r[i-1]!= -1 && dominoes[i]!='L'){
                    left_closest_r[i] = left_closest_r[i-1];
                }
            }
        }
        //Right to left traversal to find left push
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(dominoes[i]=='L') right_closest_l[i] = i;
            }else if(dominoes[i]=='L'){
                right_closest_l[i]=i;
            }else{
                if(right_closest_l[i+1]!= -1 && dominoes[i]!='R'){
                    right_closest_l[i] = right_closest_l[i+1];
                }
            }
        }
        string ans = dominoes;
        for(int i = 0;i<n;i++){
            if(left_closest_r[i]==right_closest_l[i]) ans[i] = '.';
            else if(left_closest_r[i]== -1) ans[i] = 'L';
            else if(right_closest_l[i]== -1) ans[i] = 'R';
            else{
                int leftclosestRdist = abs(i-left_closest_r[i]);
                int rightclosestLdist = abs(i-right_closest_l[i]);
                if(leftclosestRdist > rightclosestLdist) ans[i] = 'L';
                else if(leftclosestRdist < rightclosestLdist) ans[i] = 'R';
                else ans[i] = '.';
            }
        }
        return ans;
    }
};