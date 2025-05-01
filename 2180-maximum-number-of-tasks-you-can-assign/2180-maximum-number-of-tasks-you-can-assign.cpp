class Solution {
public:
    bool isPoss(int mid,vector<int>& tasks,vector<int>& workers,int pills,int strength){
        int pillsused = 0;
        multiset<int>st(workers.begin(),workers.begin()+mid);
        for(int i = mid-1;i>=0;i--){
            int req = tasks[i];
            auto it = prev(st.end());
            
            if(*it >= req){
                st.erase(it);
            }else if(pillsused>=pills){
                return false;
            }else{
                int ministr = req-strength;
                auto weakworker = st.lower_bound(ministr);
                if(weakworker == st.end()) return false;
                st.erase(weakworker);
                pillsused++;
            }
        }
        return true;
    } 
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());

        int low = 0,high = min(n,m);
       
        int ans = 0;
        while(low<=high){
            int mid = (high+low)/2;
            if(isPoss(mid,tasks,workers,pills,strength)){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
};