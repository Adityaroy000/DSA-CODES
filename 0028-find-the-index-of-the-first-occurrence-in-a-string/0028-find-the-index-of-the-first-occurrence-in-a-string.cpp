class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int h = haystack.size();

        int i=0;
        while(i<h){
            int k=i;
            for(int j=0;j<n;j++){
                if(needle[j] == haystack[k]) k++;
            }
            if(k-i == n) return i;

            i++;
        }
        return -1;
    }
};