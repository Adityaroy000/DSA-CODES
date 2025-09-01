class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>>pq;

        for(int i=0;i<n;i++){
            double pass = classes[i][0];
            double total = classes[i][1];

            double oldRatio = pass/total;
            double newRatio = (pass+1)/(total+1);

            double gain = newRatio-oldRatio;

            pq.push({gain,i});
        }
        while(extraStudents){
            double oldgain = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            classes[idx][0]++;
            classes[idx][1]++;

            double newpass = classes[idx][0];
            double newtotal = classes[idx][1];

            double oldRatio = newpass/newtotal;
            double newRatio = (newpass+1)/(newtotal+1);

            double newgain = newRatio-oldRatio;
            pq.push({newgain,idx}); 
            extraStudents--;
        }
 
        double ratio = 0;

        for(int i=0;i<n;i++){
            ratio += (double(classes[i][0]))/classes[i][1];
        }
        return double(ratio/n);
    }
};