class Solution {
public:
    bool checkDivisibility(int n) {
        int sumd = 0;
        int prod = 1;
        int num = n;
        while(num>0){
            sumd += (num%10);
            prod *= (num%10);
            num = num/10;
        }
        
        int res = sumd+prod;

        if(n%res == 0) return true;

        return false;
    }
};