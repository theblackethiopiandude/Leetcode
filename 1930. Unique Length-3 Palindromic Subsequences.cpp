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

int countPalindromicSubsequence(string s) {
        unordered_set<string> palindromes;
        unordered_set<char> L;
        unordered_map<char, int> R;

        for(int i = 0; i < s.length(); i++)
            R[s[i]]++;
        
        for(int M = 0; M < s.length(); M++){
            R[s[M]]--;
            
            for(const auto letter : L)
                if(R[letter] > 0)
                    palindromes.insert(string(1, letter) + s[M]);


            L.insert(s[M]);
        }

        return palindromes.size();
    }

int countPalindromicSubsequence(string s) {
        unordered_set<string> palindromes;
        unordered_set<char> L;
        unordered_map<char, int> R;

        for(const char c : s)
            R[c]++;
        
        for(const char m : s){
            R[m]--;
            
            for(const auto letter : L)
                if(R[letter] > 0)
                    palindromes.insert(string(1, letter) + m);


            L.insert(m);
        }

        return palindromes.size();
    }
