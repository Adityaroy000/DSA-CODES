class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int t = tops.size();
        int b = bottoms.size();

        unordered_map<int,int>mpptop;
        unordered_map<int,int>mppbot;
        for(int i = 0;i<t;i++){
            mpptop[tops[i]]++;
        }
        for(int i = 0;i<b;i++){
            mppbot[bottoms[i]]++;
        }
        int max_freq_top = -1,max_freq_bot =-1;
        int cnt = 0;
        if(mpptop.size()<mppbot.size()){
            int check = 0;
            for(auto &it:mpptop){
                if(it.second>check) {
                    check = it.second;
                    max_freq_top = it.first;
                }
            }
            for(int i = 0;i<t;i++){
                if(tops[i]!=max_freq_top){
                    if(bottoms[i]==max_freq_top){
                        swap(tops[i],bottoms[i]);
                        cnt++;
                    }else return -1;
                }
            }
        }else if(mpptop.size()>mppbot.size()){
            int check = 0;
            for(auto &it:mppbot){
                if(it.second>check) {
                    check = it.second;
                    max_freq_bot = it.first;
                }
            }
            for(int i = 0;i<b;i++){
                if(bottoms[i]!=max_freq_bot){
                    if(tops[i]==max_freq_bot){
                        swap(tops[i],bottoms[i]);
                        cnt++;
                    }else return -1;
                }
            }
        }else{
            int check = 0;
            for(auto &it:mpptop){
                if(it.second>check) {
                    check = it.second;
                    max_freq_top = it.first;
                }
            }
            int check1 = 0;
            for(auto &it:mppbot){
                if(it.second>check1) {
                    check1 = it.second;
                    max_freq_bot = it.first;
                }
            }
            int topelefreq = mpptop[max_freq_top];
            int botelefreq = mppbot[max_freq_bot];
            if(topelefreq<=botelefreq){
                for(int i = 0;i<b;i++){
                    if(bottoms[i]!=max_freq_bot){
                        if(tops[i]==max_freq_bot){
                            swap(tops[i],bottoms[i]);
                            cnt++;
                        }else return -1;
                    }
                }
            }else{
                for(int i = 0;i<t;i++){
                    if(tops[i]!=max_freq_top){
                        if(bottoms[i]==max_freq_top){
                            swap(tops[i],bottoms[i]);
                            cnt++;
                        }else return -1;
                    }
                }
            }
        }
        return cnt;
    }
};