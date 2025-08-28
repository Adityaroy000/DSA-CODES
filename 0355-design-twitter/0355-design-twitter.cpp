class Twitter {
public:
    int timestamp;
    unordered_map<int,vector<pair<int,int>>>tweet;
    unordered_map<int,unordered_set<int>>following;
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>feed;
        if(tweet.find(userId)!=tweet.end()){
            for(auto & tw : tweet[userId]){
                feed.push(tw);
            }
        }

        if(following.find(userId)!=following.end()){
            for(auto &fid : following[userId]){
                if(tweet.find(fid)!=tweet.end()){
                    for(auto & tw : tweet[fid]){
                        feed.push(tw);
                    }
                }
            }
        }

        vector<int>ans;
        int cnt = 0;
        while(!feed.empty() && cnt < 10){
            ans.push_back(feed.top().second);
            feed.pop();
            cnt++;
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId)!=following[followerId].end()){
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */