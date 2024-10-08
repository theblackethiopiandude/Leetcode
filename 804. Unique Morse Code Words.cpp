int uniqueMorseRepresentations(vector<string>& words) {
        string dot[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> uset;
        for(const auto& word: words){
            string ans = "";
            for(char ch: word){
                ans += dot[ch - 'a'];
            }
            uset.insert(ans);
        }
        
        return uset.size();
    }
