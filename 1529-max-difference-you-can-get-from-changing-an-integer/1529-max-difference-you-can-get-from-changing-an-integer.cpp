class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();
        
        char x,y;
        char dig = '#';
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
                dig = s[i];
                break;
            }
        }
        string temp = s;
        if(dig != '#'){
            for(int i=0;i<n;i++) {
                if(temp[i]==dig) temp[i] = '9';
            }
        }
        int maxi = stoi(temp);
        int mini = INT_MAX;
        temp = s;

        if(temp[0]!= '1'){
            dig = s[0];
            for(int i=0;i<n;i++){
                if(temp[i]==dig) temp[i]='1';
            }
        }else{
            dig = '#';
            for(int i=1;i<n;i++){
                if(temp[i] != '1' && temp[i] != '0'){
                    dig = temp[i];
                    break;
                }
            }
            if(dig != '#'){
                for(int i=0;i<n;i++){
                    if(temp[i] ==dig) temp[i] = '0';
                }
            }
        }
        mini = stoi(temp);
        return maxi-mini;
    }
};