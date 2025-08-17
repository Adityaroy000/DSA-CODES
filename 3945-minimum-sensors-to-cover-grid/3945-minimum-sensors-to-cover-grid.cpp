class Solution {
public:
    int minSensors(int n, int m, int r) {
        int cover = 2 * r + 1;

        int rows = ceil((double)n/cover);  

        int cols = ceil((double)m/cover);  

        return rows * cols;
    }
};