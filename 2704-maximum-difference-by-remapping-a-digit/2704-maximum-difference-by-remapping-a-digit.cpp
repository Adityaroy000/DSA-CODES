class Solution {
public:
    int minMaxDifference(int num) {
        string nums = to_string(num);

        char mini = '#';
        for(int i=0;i<nums.size();i++){
            if(nums[i]!='9'){
                mini = nums[i];
                break;
            }
        }

        string temp = nums;
        if(mini != '#'){
            for(int i=0;i<temp.size();i++){
                if(temp[i]==mini) temp[i] = '9';
            }
        }

        int maxnum = stoi(temp);

        char maxi = nums[0];
        temp = nums;

        for(int i=0;i<temp.size();i++){
            if(temp[i]==maxi) temp[i] = '0';
        }

        int idx = 0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='0') continue;
            else{
                idx = i;
                break;
            }
        }
        string t = temp.substr(idx);

        int minNumber;
        if(t.empty()){
            minNumber = 0;
        }else{
            minNumber = stoi(t);
        }

        return maxnum-minNumber;
    }
};