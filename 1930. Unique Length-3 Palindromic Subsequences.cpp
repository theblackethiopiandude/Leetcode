int countPalindromicSubsequence(string s) {
        unordered_set<string> palindromes;
        unordered_map<char, int> L, R;
        
        for(int i = 0; i < s.length(); i++)
            R[s[i]]++;
        
        for(int M = 0; M < s.length(); M++){
            R[s[M]]--;
            
            for(const auto& [letter, count] : L)
                if(R[letter] > 0)
                    palindromes.insert(string(1, letter) + s[M]);


            L[s[M]]++;
        }

        return palindromes.size();
    }
