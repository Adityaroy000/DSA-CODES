class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int>mpp;
        if(n%groupSize != 0) return false;
        for(int card : hand){
            mpp[card]++;
        }
        if(n%groupSize == 0){
            for(auto it = mpp.begin(); it!=mpp.end(); it++){
                int card = it->first;
                int cnt = it->second;
                if(cnt>0){
                    for(int i = 0; i<groupSize; i++){
                        if(mpp[card+i]<cnt) return false;
                        mpp[card+i] -= cnt;
                    }
                }
            }            
        }
        return true;
    }
};