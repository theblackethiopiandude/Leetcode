class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(const char& c : s){
            if(isVowel(c))
                vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        string ans = "";
        int i = 0;
        for(const char& c : s){
            if(isVowel(c)){
                ans += vowels[i++];
                continue;
            }
            ans += c;
        }

        return ans;
    }

private:
    bool isVowel(const char& c){
        switch (c) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
            default:
                return false;
        }
    }
};
