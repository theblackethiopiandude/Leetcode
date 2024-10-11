int countConsistentStrings(string allowed, vector<string>& words) {
        bool umap[26];
        for(char ch: allowed)
            umap[ch - 'a'] = true;
        
        int ans = 0;
        for(const auto& word : words){
            bool allow = true;
            for(int i = 0; i < word.length(); i++)
                if(!umap[word[i] - 'a']){
                    allow = false;
                    break;
                }

            if(allow) ans++;
        }
        return ans;
    } // Runtime Error but worked as a test case
