vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        {
            unordered_map<int, unordered_set<int>> umap;

            for(auto& log: logs)
                umap[log[0]].insert(log[1]);

            for(auto& pair: umap)
                ans[pair.second.size()-1]++;
        }

        return ans;
}
