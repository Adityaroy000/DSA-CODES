class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows, cols;
        for(auto b : buildings){
            int r = b[0]-1;
            int c = b[1]-1;

            rows[r].push_back(c);
            cols[c].push_back(r);
        }
        int count = 0;
        for(auto& it:rows){
            sort(it.second.begin(),it.second.end());
        }
        for(auto& it:cols){
            sort(it.second.begin(),it.second.end());
        }


        for(auto& b:buildings){
            int r = b[0]-1;
            int c = b[1]-1;
            bool left=false,right=false,up=false,down = false;
           
            const auto& row = rows[r];
            if(!row.empty()){
                if(row.front()<c) left = true;
                if(row.back()>c)  right = true;
            }
            const auto& col = cols[c];
            if(!col.empty()){
                if(col.front()<r) up = true;
                if(col.back()>r) down = true;
            }
            
            if(left&&right&&up&&down) count++;
        }
        return count;
    }
};