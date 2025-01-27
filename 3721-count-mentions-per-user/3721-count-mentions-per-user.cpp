class Solution {
public:
    static bool cmp(vector<string>a,vector<string>b){
        int timea = stoi(a[1]);
        int timeb = stoi(b[1]);
        return timea == timeb? a[0]>b[0] : timea<timeb;
    }
    void onmess(vector<string>temp,vector<int>& mention,vector<int>& offline){
        int timestamp = stoi(temp[1]);
        vector<string>idn;
        stringstream s(temp[2]);
        string word;   
        while(s >> word){
            idn.push_back(word);
        }
        for(string st : idn){
            if(st == "ALL"){
                for(int i = 0;i<mention.size(); i++){
                    mention[i]++;
                }
            }else if(st == "HERE"){
                for(int i=0;i<mention.size();i++){
                    if(offline[i]==0 || offline[i]+60 <= timestamp){
                        mention[i]++;
                    }
                }
            }else{
                int n = stoi(st.substr(2));
                mention[n]++;
            }
        }
    }
    void offmess(vector<string>temp,vector<int>& mention,vector<int>& offline){
        int timestamp = stoi(temp[1]);
        int id = stoi(temp[2]);
        offline[id] = timestamp;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mention(numberOfUsers);
        vector<int>offline(numberOfUsers);

        sort(events.begin(),events.end(),cmp);

        for(vector<string>temp:events){
            if(temp[0]=="MESSAGE"){
                onmess(temp,mention,offline);
            }else if(temp[0]=="OFFLINE"){
                offmess(temp,mention,offline);
            }
        }
        return mention;
    }
};