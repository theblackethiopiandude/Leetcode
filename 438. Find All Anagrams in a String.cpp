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
