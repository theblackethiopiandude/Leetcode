string frequencySort(string s) {
        map <int, string> x;
        
        {
            unordered_map<char, int> freq;
            for(char ch:s)
                freq[ch]++;
            
            for(auto& pair: freq)
                for(int i = pair.second; i > 0; i--)
                    x[pair.second] += pair.first;
        }

        string t = "";
        for (auto it = x.rbegin(); it != x.rend(); ++it)
            t += it->second;


        return t;
    }
