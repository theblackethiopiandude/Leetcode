bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for(const auto& ch : s)
            umap[ch]++;

        for(const auto& ch : t)
            umap[ch]--;
        
        for(const auto& pair:umap)
            if(pair.second != 0)
                return false;    
        
        return true;
    }
