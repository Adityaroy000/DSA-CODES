class Twitter {
public:
    int timestamp;//global timestamp to keep track of order of tweets
    unordered_map<int,vector<pair<int,int>>>tweets;//userId,{timestamp,tweetId}
    unordered_map<int,unordered_set<int>>follower;//userId,set of followers
    Twitter():timestamp(0) {} // for each object twitter timestamp will be created
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>feed;//most recent tweets will be at top wrt to timestamp
        if(tweets.find(userId)!=tweets.end()){//Include the user's own tweets
            for(const auto& tweet : tweets[userId]){
                feed.push(tweet);
            }
        }
        if(follower.find(userId)!=follower.end()){// Include tweets from users the current user follows
            for(int followeeId : follower[userId]){
                if(tweets.find(followeeId)!=tweets.end()){
                    for(const auto& tweet : tweets[followeeId]){
                        feed.push(tweet);
                    }
                }
            }
        }
        // Extract the top 10 most recent tweets
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
        if(followerId!=followeeId){// Prevent self-following
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