bool areOccurrencesEqual(string s) {
        {
            unordered_map<char, int> umap;
            for(const char ch: s)
                umap[ch]++;
            
            int x = umap[s[0]];

            for(const auto& [_, count] : umap)
                if(x != count)
                    return false;
        }
        return true;
    }
