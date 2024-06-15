vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        int m = 1998;
        unordered_map<string, int> com;
        {
            unordered_map<string, int> umap;
            for(int i = 0; i < list1.size(); i++)
                umap[list1[i]]+= i;
            
            
            for(int i = 0; i < list2.size(); i++){
                if(umap.count(list2[i])){
                    com[list2[i]] = umap[list2[i]] + i;
                    m = min(com[list2[i]], m);
                }
            }
        }

        vector<string> ans;
        for(auto& pair : com)
            if(pair.second == m)
                ans.push_back(pair.first);
               
        return ans;
    }
