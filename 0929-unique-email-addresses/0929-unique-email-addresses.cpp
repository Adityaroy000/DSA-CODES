class Solution {
public:
    int find(string em){
        int n = em.size();

        for(int i=0;i<n;i++){
            if(em[i]=='@'){
                return i;
            }
        }
        return 0;
    }
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();

        unordered_set<string>st;

        for(int i=0;i<n;i++){
            string em = emails[i];

            int idx = find(em);

            string norm = "";
            int j=0;
            while(j<=idx){
                if(em[j] == '.'){
                    j++;
                    continue;
                }
                if(em[j] == '+') {
                    while(j<=idx && em[j] != '@') j++;
                }
                norm.push_back(em[j]);
                j++;
            }
            norm = norm+em.substr(idx+1);
            st.insert(norm);
        }

        return st.size();
    }
};