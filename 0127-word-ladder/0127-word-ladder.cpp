class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int s = wordList[0].size();
        int cnt1=0;
        for(int i = 0 ;i<n; i++){
            if(endWord == wordList[i]) cnt1++;
        }
        if(cnt1==0) return 0;
        queue<string>q;
        q.push(beginWord);
        vector<int>vis(n,0);
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            for(int k=0;k<size;k++){
                auto it = q.front();
                q.pop();
                for(int i = 0; i<n; i++){
                    int cnt  = 0;
                    if(vis[i]==0){
                        for(int j=0;j<s;j++){
                            if(it[j]!=wordList[i][j]) cnt++;
                        }
                        if(cnt == 1){
                            q.push(wordList[i]);
                            vis[i]=1;
                            if(wordList[i]==endWord) return count+1;
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};