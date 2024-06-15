string mergeAlternately(string word1, string word2) {
        int n = min(word1.length(), word2.length());

        string ans;
        for (int i = 0; i < n; i++){
                ans += word1[i];
                ans += word2[i];
        }
        return ans + word1.substr(n) + word2.substr(n);
    }
