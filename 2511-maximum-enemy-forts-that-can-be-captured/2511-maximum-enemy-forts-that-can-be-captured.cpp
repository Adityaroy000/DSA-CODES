class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        bool flag = false;
        for(int i=0;i<n;i++){
            if(forts[i]== -1) {
                flag = true;
                break;
            }
        }

        if(!flag) return 0;

        bool flag1 = false;
        for(int i=0;i<n;i++){
            if(forts[i]== 1) {
                flag1 = true;
                break;
            }
        }

        if(!flag1) return 0;

        int maxi = 0;
        int previdx = -1;
        for(int i=0;i<n;i++){
            if(forts[i]!=0){
                if(previdx != -1 && forts[previdx] == -forts[i]){
                    if(abs(i-previdx) > 1){
                        maxi = max(maxi,i-previdx-1);
                    }
                }
                previdx = i;
            }
        }
        
        return maxi;
    }
};