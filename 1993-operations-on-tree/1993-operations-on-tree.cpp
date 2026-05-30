class LockingTree {
public:
    unordered_map<int,int>mpp;
    vector<vector<int>>adj;
    vector<int>parent;
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        adj.resize(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(mpp.count(num)==0){
            mpp[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(mpp.count(num)){
            if(mpp[num] == user) {
                mpp.erase(num);
                return true;
            }
            return false;
        }
        return false;
    }

    bool check_locked_descendant (int node){
        queue<int>q;
        for(auto it : adj[node]){
            q.push(it);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(mpp.count(curr)) return true;

            for(auto it : adj[curr]){
                q.push(it);
            }
        }

        return false;
    }

    void unlock_locked_descendant(int node){
        queue<int>q;
        for(auto it : adj[node]){
            q.push(it);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(mpp.count(curr)){
                mpp.erase(curr);
            }

            for(auto it : adj[curr]){
                q.push(it);
            }
        }
    }
    
    bool upgrade(int num, int user) {
        
        if(mpp.count(num)) return false;

        int curr = num;
        while(parent[curr] != -1){
            if(mpp.count(parent[curr])) return false;
            curr = parent[curr];
        }

        bool solve = check_locked_descendant(num);
        if(solve == false) return false;

        mpp[num] = user;

        unlock_locked_descendant(num);

        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */