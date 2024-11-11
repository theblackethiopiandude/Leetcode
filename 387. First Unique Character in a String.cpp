int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        for(const char ch: s)
            umap[ch]++;
        for(int i = 0; i < s.length(); i++)
            if(umap[s[i]] == 1)
                return i;
        return -1;
    }
