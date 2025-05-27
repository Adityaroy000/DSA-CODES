class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1 = 0,sum2=0;
        
        int divbym = floor(n/m);

        sum2 = m*((divbym*(divbym+1))/2);

        int ts = (n*(n+1))/2;

        sum1 = ts-sum2;
        

        return (sum1-sum2);
    }
};