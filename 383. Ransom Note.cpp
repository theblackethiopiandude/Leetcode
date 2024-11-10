bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for(const char ch: magazine)
            umap[ch]++;
        
        for(const char ch: ransomNote){
            if(umap.count(ch))
                if(umap[ch] > 0)
                    umap[ch]--;
                else
                    return false;
            else
                return false;
            
        }

        return true;
    }
