class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = num.size();
        string t = num;
        
        while(k>0){
            int idx = -1;
            for(int i=n-2;i>=0;i--){
                if(t[i]<t[i+1]){
                    idx = i;
                    break;
                }
            }
            if(idx == -1) break;

            for(int i=n-1;i>idx;i--){
                if(t[i]>t[idx]){
                    swap(t[i],t[idx]);
                    break;
                }
            }
            reverse(t.begin()+idx+1,t.end());
            k--;
        }
        int swaps = 0;
        for(int i=0;i<n;i++){
            if(num[i]!=t[i]){
                char f = t[i];
                for(int j=i+1;j<n;j++){
                    if(num[j]==f){
                        for(int k=j;k>i;k--){
                            swap(num[k],num[k-1]);
                            swaps++;
                        }
                        break;
                    }
                }
            }
        }
        return swaps;
    }
};