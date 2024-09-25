vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(auto& word : strs){
            auto sorted = word;
            sort(sorted.begin(), sorted.end());
            umap[sorted].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto& pair: umap)
            ans.push_back(pair.second);
        
        return and;
}
