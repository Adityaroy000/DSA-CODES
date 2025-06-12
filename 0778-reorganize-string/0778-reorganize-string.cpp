class Solution {
public:
    typedef pair<int,int> p;
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char,int>mpp;
        for(char ch: s){
            mpp[ch]++;
        }
        
        priority_queue<p>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }

        string ans ="";
        while(!pq.empty() && pq.size()>1){
            auto [freq1,ch1] = pq.top();
            pq.pop();
            auto [freq2,ch2] = pq.top();
            pq.pop();

            ans.push_back(ch1);
            ans.push_back(ch2);

            if(freq1 > 1) {
                freq1--;
                pq.push({freq1,ch1});
            }
            if(freq2 > 1) {
                freq2--;
                pq.push({freq2,ch2});
            }
        }

        if(!pq.empty()){
            auto [freq,ch] = pq.top();
            pq.pop();

            if(freq>1) return "";
            else ans.push_back(ch);
        }

        return ans;
    }
};