class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string temp ="";
        int n = num;
        while(n>0){
            int ld = n%10;
            temp = to_string(ld)+temp;
            n /= 10;
        }
        
        int cnt = 0;
        int l=0,r=k-1;
        while(r<temp.size()){
            string d = temp.substr(l,r-l+1);

            int div = stoi(d);

            if(div != 0 && num % div == 0) cnt++;
            l++;
            r++;
            
        }
        return cnt;
    }
};