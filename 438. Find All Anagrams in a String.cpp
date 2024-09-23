vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        sort(p.begin(), p.end());
        const int window_size = p.length();

        for(int L = 0, R = 0; R < s.length(); R++){
            int window = R - L + 1;
            if(window == window_size){
                string y = s.substr(L, window);
                sort(y.begin(), y.end());

                if(y == p)
                    ans.push_back(L);
                L++;
            }
        }

        return ans;
}    // Works with TLE!

vector<int> findAnagrams(string s, string p) {
        vector<int> ans, pcount(26, 0), scount(26, 0);
        const int window_size = p.length();

        for(char c: p)
            pcount[c - 'a']++;

        for(int L = 0, R = 0; R < s.length(); R++){
            scount[s[R] - 'a']++;

            if((R - L + 1) == window_size){
                bool valid = true;
                for(int i = 0; i < 26; i++)
                    if(pcount[i] != scount[i])
                        valid = false;

                if(valid)
                    ans.push_back(L);

                scount[s[L++] - 'a']--;
                
            }
        }

        return ans;
}
