class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target) return 0;

        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mpp[routes[i][j]].push_back(i);
            }
        }

        queue<int>q;
        vector<bool>vis(n,false);
        
        for(auto &bus:mpp[source]){
            q.push(bus);
            vis[bus] = true;
        }

        int cnt = 1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int busnumber = q.front();
                q.pop();

                for(auto &stop:routes[busnumber]){
                    if(stop == target) return cnt;

                    for(auto &route : mpp[stop]){
                        if(!vis[route]){
                            vis[route] = true;
                            q.push(route);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};