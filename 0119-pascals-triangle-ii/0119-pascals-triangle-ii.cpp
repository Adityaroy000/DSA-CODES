class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>temp;
        temp.push_back(1);
        if(rowIndex == 0) return temp;

        int cnt  = 0;
        while(cnt <= rowIndex){
            if(cnt == rowIndex) return temp;
            cnt++;
            int n = temp.size();
            vector<int>newtemp;
            newtemp.push_back(1);
            for(int i=0;i<n-1;i++){
                newtemp.push_back(temp[i]+temp[i+1]);
            }
            newtemp.push_back(1);
            temp = newtemp;
        }

        return temp;
    }
};