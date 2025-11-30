class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        for(long long pen = 0;1LL*pen*cost1<=total;pen++){
            long long pencost = pen*cost1;
            long long rem = total-pencost;
            long long tpencil = rem/cost2;

            ways += (tpencil+1);
        }
        return ways;
    }
};