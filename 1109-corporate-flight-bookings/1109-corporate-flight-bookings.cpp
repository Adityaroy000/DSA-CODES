class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        int s = bookings.size();

        for(int i=0;i<s;i++){
            int st = bookings[i][0]-1;
            int en = bookings[i][1]-1;
            int seat = bookings[i][2];

            if(st<n) ans[st]+=seat;
            if(en+1<n) ans[en+1]-=seat;
        }
        int sum = 0;
        vector<int>p;
        for(int i=0;i<n;i++){
            sum += ans[i];
            p.push_back(sum);
        }
        return p;
    }
};