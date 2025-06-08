class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        int count = 1;
        for(int i=0;i<n;i++){
            ans.push_back(count);
            if(count*10 <= n){
                count = count*10;
            }else{
                if( count >= n) count /= 10;
                count++;
                while(count % 10 == 0) count /= 10;
            }
        }
        return ans;
    }
};