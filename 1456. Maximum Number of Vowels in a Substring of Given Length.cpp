int maxVowels(string s, int k) {
        int maxVowel = 0;
        for(int L = 0, R = 0, vowel = 0; R < s.size(); R++){
            switch(s[R]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel++;
            }
            if(R - L + 1 == k){
                maxVowel = max(maxVowel, vowel);
                switch(s[L++]){
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        vowel--;
                }
            }
        }
        return maxVowel;
    }


int maxVowels(string s, int k) {
        int maxVowel = 0;
        unordered_set<char> v({'a', 'e', 'i', 'o', 'u'});
        for(int L = 0, R = 0, vowel = 0; R < s.size(); R++){
            if(v.count(s[R]))
                vowel++;
            
            if(R - L + 1 == k){
                maxVowel = max(maxVowel, vowel);
                if(v.count(s[L++]))
                    vowel--;
            }
        }
        return maxVowel;
    }
