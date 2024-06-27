vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < groupSizes.size(); i++)
            umap[groupSizes[i]].push_back(i);
        
        vector<vector<int>> ans;
        for(auto& pair: umap){
            if(pair.second.size() > pair.first){
                int partitionSize = pair.first;
                int numberOfPartitions = pair.second.size() / partitionSize;
                auto it = pair.second.begin();
                for (int i = 0; i < numberOfPartitions; ++i) {
                    std::vector<int> part(it, it + partitionSize);
                    ans.push_back(part);
                    it += partitionSize;
                }
                continue;
            }

            ans.push_back(pair.second);
        }
        return ans;
    }
