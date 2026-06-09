class Solution {
public:
    int countSeniors(vector<string>& details) {
        // first 10 -> phn no
        // 11th char -> gender
        //12th and 13th -> age
        //14th qand 15th -> seat alloted

        int n= details.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            string s = details[i].substr(11,2);
            int age = stoi(s);

            if(age > 60) cnt++;
        }
        return cnt;
    }
};