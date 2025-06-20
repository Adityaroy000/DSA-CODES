class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        string t = s;
        unordered_map<char,char>mpp = {
            {'N','S'},
            {'S','N'},
            {'E','W'},
            {'W','E'}
        };
        vector<string>temp = {"NE","NW","SE","SW"};
        int maxdist = 0;
        int srcx=0,srcy=0;
        for(int i=0;i<temp.size();i++){
            char vDir = temp[i][0];
            char hDir = temp[i][1];
            int x=0,y=0,cnt=0;
            for(int j = 0;j<n&&cnt<k;j++){
                if(s[j] != vDir && s[j] != hDir){
                    if(mpp[s[j]] == vDir){
                        s[j] = vDir;
                        cnt++;
                    }else{
                        s[j] = hDir;
                        cnt++;
                    }
                }
            }
            for(int j=0;j<n;j++){
                 if(s[j]=='N'){
                    y += 1;
                }else if(s[j]=='S'){
                    y -= 1;
                }else if(s[j]=='E'){
                    x += 1;
                }else{
                    x -= 1;
                }

                int dist = abs(srcx-x)+abs(srcy-y);
                maxdist = max(maxdist,dist);
            }
            s = t;
        }
        return maxdist;
    }
};