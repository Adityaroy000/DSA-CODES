class Solution {
public:
    int pivotInteger(int n) {
        int tsum = (n*(n+1))/2;

        for(int i=1;i<=n;i++){
            int psum = (i*(i+1))/2;
            int ssum = tsum-psum+i;
            if(psum == ssum){
                return i;
            }
        }
        return -1;
    }
};