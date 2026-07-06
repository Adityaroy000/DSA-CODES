class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;

        vector<string>temp;

        while(ss>>word){
            temp.push_back(word);
        }

        int n = temp.size();
        int i;
        for(i=0;i<n-1;i++){
            string p = temp[i];
            string n = temp[i+1];

            if(p[p.size()-1] != n[0]) return false;
        }

        if(temp[i][temp[i].size()-1] != temp[0][0]) return false;

        return true;
    }
};