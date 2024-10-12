bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;

        for(int num: arr)
            umap[num]++;
        
        unordered_set<int> uset;
        for(const auto& [_, value] : umap){
            if(uset.count(value))
                return false;
            
            uset.insert(value);
        }

        return true;
    }
