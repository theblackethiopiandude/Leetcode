vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, char> umap;
        for(const auto& word: words){
            for(int i = 0; i < pattern.length(); i++){
                umap[pattern[i]] = word[i];
            }

            bool valid = true;
            for(int i = 0; i < pattern.length(); i++){
                if(umap[pattern[i]] != word[i]){
                    valid = false;
                    break;
                }

            }
            unordered_set<char> uset;
            if(valid){
                for(const auto& [_, value]: umap)
                    uset.insert(value);
                
                valid = uset.size() == umap.size();
            }
            umap.clear();

            if(valid)
                ans.push_back(word);
        }

        return ans;
    }


vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, char> umap;
        unordered_set<char> uset;
        for(const auto& word: words){
            for(int i = 0; i < pattern.length(); i++){
                umap[pattern[i]] = word[i];
                uset.insert(word[i]);
            }

            bool valid = uset.size() == umap.size();

            for(int i = 0; valid && i < pattern.length(); i++)
                if(umap[pattern[i]] != word[i])
                    valid = false;

            umap.clear();
            uset.clear();
                
            if(valid)
                ans.push_back(word);
        }

        return ans;
    }
