string decodeMessage(string key, string message) {
        unordered_map<char, char> umap;
        umap[' '] = ' ';
        char count = 'a';
        for(char ch : key){
            if(ch > 'z')
                break;
            if(!umap.count(ch))
                umap[ch] = count++;
        }
        
        string ans;
        for(char ch : message)
            ans += umap[ch];
        
        return ans;

    }
