class Solution {
public:
    void ddfs(int node,int distance,vector<int>& edges,vector<int>& dist,vector<int>& vis){
        if(node == -1 || vis[node]==1) return;
        vis[node] = 1;
        dist[node] = distance;
        ddfs(edges[node],distance+1,edges,dist,vis);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        if(node1==node2) return node1;

        vector<int>dist2(n,-1);
        vector<int>dist1(n,-1);
        vector<int>vis1(n,0),vis2(n,0);
        //dfs for node1
        ddfs(node1,0,edges,dist1,vis1);
        ddfs(node2,0,edges,dist2,vis2);

        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(dist1[i] != -1 && dist2[i] != -1) {
                if(max(dist1[i], dist2[i]) < mini) {
                    mini = max(dist1[i], dist2[i]);
                    ans = i;
                }
            }
        }

        return ans;
    }
};