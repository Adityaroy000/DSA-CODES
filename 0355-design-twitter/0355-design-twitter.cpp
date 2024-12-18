class Twitter {
public:
    int timestamp;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>follower;
    Twitter():timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>feed;
        if(tweets.find(userId)!=tweets.end()){
            for(const auto& tweet : tweets[userId]){
                feed.push(tweet);
            }
        }
        if(follower.find(userId)!=follower.end()){
            for(int followeeId : follower[userId]){
                if(tweets.find(followeeId)!=tweets.end()){
                    for(const auto& tweet : tweets[followeeId]){
                        feed.push(tweet);
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
        if(followerId!=followeeId){
            follower[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follower[followerId].find(followeeId)!= follower[followerId].end()){
            follower[followerId].erase(followeeId);
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