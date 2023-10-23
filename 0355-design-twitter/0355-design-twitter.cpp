class Twitter {
    vector<pair<int, int>> posts;
    unordered_map<int, unordered_set<int>> follows;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int limit = 10;
        
        int numPosts = posts.size();
        
        vector<int> res;
        
        for (int i = numPosts - 1; i >= 0; i--) {
            if (limit == 0) return res;
            
            int followeeId = posts[i].first;
            int tweetId = posts[i].second;
            if (follows[userId].find(followeeId) != follows[userId].end() || followeeId == userId) {
                res.push_back(tweetId);
                limit--;
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows[followerId].find(followeeId) != follows[followerId].end())
            follows[followerId].erase(followeeId);   
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