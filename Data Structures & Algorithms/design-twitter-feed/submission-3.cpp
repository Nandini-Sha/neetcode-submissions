class Twitter {
private:
    int t = 0;

    struct User {
        int userID;
        vector<pair<int,int>> tweetids; // {time, tweetId}
        unordered_set<int> followings;

        User(int id) {
            userID = id;
        }
    };

    unordered_map<int, User*> users;

    User* getuser(int userID) {
        if (users.find(userID) == users.end()) {
            users[userID] = new User(userID);
        }
        return users[userID];
    }

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        User* u = getuser(userId);
        u->tweetids.push_back({t++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> list;

        if (users.find(userId) == users.end())
            return list;

        User* u = getuser(userId);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;

        auto pushTweets = [&](const vector<pair<int,int>>& tweets) {
            for (auto &tweet : tweets) {
                if (que.size() < 10) {
                    que.push(tweet);
                } else if (tweet.first > que.top().first) {
                    que.pop();
                    que.push(tweet);
                }
            }
        };

        // own tweets
        pushTweets(u->tweetids);

        // followings' tweets
        for (auto follower : u->followings) {
            User* f = getuser(follower);
            pushTweets(f->tweetids);
        }

        while (!que.empty()) {
            list.push_back(que.top().second);
            que.pop();
        }

        reverse(list.begin(), list.end());
        return list;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // FIX: prevent self-follow

        User* u = getuser(followerId);
        u->followings.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // FIX: ignore self-unfollow

        User* u = getuser(followerId);
        u->followings.erase(followeeId);
    }
};