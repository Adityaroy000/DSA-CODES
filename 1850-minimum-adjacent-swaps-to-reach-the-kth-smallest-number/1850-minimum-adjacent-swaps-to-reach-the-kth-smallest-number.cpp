class Solution {
public:
/*
Core Idea (Left-to-Right)

You fix the string from left to right.

At each position i, you ask:

“Which digit is supposed to be here in the final string?”
That digit is t[i].

If num[i] is already t[i], move on.

If not, you pull the correct digit from the right side using adjacent swaps.

To get the needed digit from j to i using only adjacent swaps, you must move it left j - i times. You can’t do better than that.

logic:
Fix the string from left to right. At each position, pull the correct digit from the right using the smallest number of adjacent swaps (bubble it left). The total number of such steps is the minimum number of adjacent swaps.
*/
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
            //If in the given string digit already matches the digit in target string, nothing to do
            if(num[i]!=t[i]){
                // The digit that must be placed here in given string (from the target permutation)
                char f = t[i];
                for(int j=i+1;j<n;j++){
                    // Find the first occurrence of that digit to the RIGHT
                    if(num[j]==f){
                    // Bubble this digit leftwards until it reaches position i . Each single-step movement is one adjacent swap
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