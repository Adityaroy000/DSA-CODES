class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // mass of planet >= mass of asteroid -> asteroid destroyed and planet gains mass
        // else planet is destroyed

        sort(asteroids.begin(),asteroids.end());
        long long m = mass;
        int n = asteroids.size();
        for(int x : asteroids){
            if(m >= x) m += x;
            else return false;
        }

        return true;
    }
};