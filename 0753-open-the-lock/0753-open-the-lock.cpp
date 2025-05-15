class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>visitedCombination(deadends.begin(),deadends.end());

        unordered_map<char,char>nextTurn = {
            {'0','1'},
            {'1','2'},
            {'2','3'},
            {'3','4'},
            {'4','5'},
            {'5','6'},
            {'6','7'},
            {'7','8'},
            {'8','9'},
            {'9','0'}
        };
        unordered_map<char,char>prevTurn = {
            {'1','0'},
            {'2','1'},
            {'3','2'},
            {'4','3'},
            {'5','4'},
            {'6','5'},
            {'7','6'},
            {'8','7'},
            {'9','8'},
            {'0','9'}
        };

        if(visitedCombination.find("0000")!=visitedCombination.end()) return -1;

        queue<string>q;
        q.push("0000");
        if(visitedCombination.find("0000")!=visitedCombination.end()) return -1;

        visitedCombination.insert("0000");

        int turn = 0;
        while(!q.empty()){
            for(int NoOfNodesAtCurrentLevel = q.size(); NoOfNodesAtCurrentLevel>0;NoOfNodesAtCurrentLevel--){
                string currCombination = q.front();
                q.pop();
                
                if(currCombination == target) return turn;

                for(int wheel = 0;wheel<4;wheel++){
                    string newCombination = currCombination;
                    newCombination[wheel] = nextTurn[newCombination[wheel]];
                    if(visitedCombination.find(newCombination)==visitedCombination.end()){
                        visitedCombination.insert(newCombination);
                        q.push(newCombination);
                    }

                    newCombination = currCombination;
                    newCombination[wheel] = prevTurn[newCombination[wheel]];
                    if(visitedCombination.find(newCombination)==visitedCombination.end()){
                        visitedCombination.insert(newCombination);
                        q.push(newCombination);
                    }
                }
            }
            turn += 1;
        }
        return -1;
        
    }
};