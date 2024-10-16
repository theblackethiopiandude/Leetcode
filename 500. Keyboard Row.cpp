vector<string> findWords(vector<string>& words) {
        const string first = "qwertyuiop";
        const string second = "asdfghjkl";
        const string third = "zxcvbnm";

        unordered_map<char, int> umap;

        for(char ch: first)
            umap[ch] = 1;
        
        for(char ch: second)
            umap[ch] = 2;
        
        for(char ch: third)
            umap[ch] = 3;

        vector<string> ans;
        for(const auto& word : words){
            int row = umap[tolower(word[0])];
            bool valid = true;
            for(char ch : word){
                if(row != umap[tolower(ch)]){
                    valid = false;
                    break;
                }

            }

            if(valid) ans.push_back(word);
        }

        return ans;
    }
