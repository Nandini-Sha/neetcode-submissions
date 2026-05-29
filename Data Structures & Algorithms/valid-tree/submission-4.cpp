class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> s;
    int visited = 0;
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        for(int i = 0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1);

        return visited==n;
    }
    void dfs(int i, int prev){
        s.insert(i);
        visited++;
        for(auto j:mp[i]){
            if(j==prev) continue;
            if(s.find(j) != s.end()) return;

            dfs(j,i);
        }
    }
};


