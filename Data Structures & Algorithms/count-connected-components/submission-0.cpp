class Solution {
public:
    unordered_map<int,vector<int>> map;
    unordered_set<int> s;
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0;i<edges.size();i++){
            map[edges[i][0]].push_back(edges[i][1]);
            map[edges[i][1]].push_back(edges[i][0]);
        }
        int Components = 0;
        for(int i = 0;i<n;i++){
            if(s.find(i) == s.end()){
                dfs(i);
                Components++;
            }
        }

        return Components;
    }

    void dfs(int i){
        s.insert(i);
        for(auto j:map[i]){
            if(s.find(j)==s.end()) dfs(j);

            
        }
    }
};
