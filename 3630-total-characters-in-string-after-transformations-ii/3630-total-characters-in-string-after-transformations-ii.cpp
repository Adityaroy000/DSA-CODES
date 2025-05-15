using ll = long long;
class Solution {
public:
    typedef vector<vector<int>> matrix;
    int mod = 1e9+7;

    matrix matrixMultiply(matrix& m1,matrix& m2){
        matrix ans(26,vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    ans[i][j] = (ans[i][j]+(1LL*m1[i][k]*m2[k][j])%mod)%mod;
                }
            }
        }
        return ans;
    }

    matrix matrixExp(matrix& base, int exponent){
        if(exponent == 0){
            matrix I(26,vector<int>(26,0));
            for(int i=0;i<26;i++){
                I[i][i] = 1;
            }
            return I;
        }

        matrix half = matrixExp(base,exponent/2);
        matrix res = matrixMultiply(half,half);
        if(exponent%2==1){
            res = matrixMultiply(res,base);
        }

        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int>initialFreq(26,0);
        for(char &ch:s){
            initialFreq[ch-'a']++;
        }
        //T matrix
        matrix T(26,vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int add = 1;add<=nums[i];add++){
                T[(i+add)%26][i] ++;
            }
        }
        
        //T^T
        matrix res = matrixExp(T,t);

        vector<int>newFreq(26,0);
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                newFreq[i]= (newFreq[i]+(1LL*res[i][j]*initialFreq[j])%mod)%mod;
            }
        }

        int totallen = 0;
        for(int i=0;i<26;i++){
            totallen = (totallen+newFreq[i])%mod; 
        }
        return totallen;

    }
};