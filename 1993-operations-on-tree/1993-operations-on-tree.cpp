class LockingTree {
public:
    unordered_map<int,int>mpp;
    vector<vector<int>>adj;
    vector<int>parent;
    vector<int>temp;
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

    void check_locked_descendant (int node){
        queue<int>q;
        for(auto it : adj[node]){
            q.push(it);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(mpp.count(curr)) {
                temp.push_back(curr);
            }
            for(auto it : adj[curr]){
                q.push(it);
            }
        }
    }
    
    bool upgrade(int num, int user) {
        temp.clear();
        if(mpp.count(num)) return false;

        int curr = num;
        while(parent[curr] != -1){
            if(mpp.count(parent[curr])) return false;
            curr = parent[curr];
        }

        check_locked_descendant(num);
        if(temp.empty() == true) return false;

        mpp[num] = user;

        for(int i : temp){
            mpp.erase(i);
        }

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