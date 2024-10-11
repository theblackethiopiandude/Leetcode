int countConsistentStrings(string allowed, vector<string>& words) {
        bool umap[26] = {false};  // [FIX] was because all umap elements were not initialized & contained garbage values unless explicitly set. Accessing or using these uninitialized values leads to unpredictable behavior
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
    } 

int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> uset(allowed.begin(), allowed.end());
        
        int ans = 0;
        for(const auto& word : words){
            bool allow = true;
            for(int i = 0; i < word.length(); i++){
                if(! uset.count(word[i])){
                    allow = false;
                    break;
                }
            }
            if(allow) ans++;
        }
        return ans;
    }
