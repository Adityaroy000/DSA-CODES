class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        unordered_map<char, vector<pair<int, int>>> portal;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = matrix[i][j];
                if (isupper(ch)) {
                    portal[ch].push_back({i, j});
                }
            }
        }

        vector<bool>usedPortal(26,false);

        using T = tuple<int,int,int>;

        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,0,0});

        dist[0][0] = 0;

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [steps,row,col]= pq.top();
            pq.pop();
            if (row == m - 1 && col == n - 1) return steps;
            //if(steps>dist[row][col]) continue;

            char c = matrix[row][col];
            if(c>='A'&&c<='Z'&&!usedPortal[c-'A']){
                usedPortal[c-'A'] = true;
                for(auto& [i,j]:portal[c]){
                    if(steps<dist[i][j]){
                        dist[i][j] = steps;
                        pq.push({steps,i,j});
                    }
                }
            }
            // 4 directions
            for (int k = 0; k < 4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    matrix[nrow][ncol] != '#') {
                    if(steps+1<dist[nrow][ncol]){
                        dist[nrow][ncol] = steps+1;
                        pq.push({steps+1,nrow,ncol});
                    }
                }
            }
        }
        return -1;
    }
};
