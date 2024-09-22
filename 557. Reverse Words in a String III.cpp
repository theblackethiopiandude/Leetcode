class Solution {
public:
    string reverseWords(string s) {
        string ans;
        auto k = split(s);
        for (auto& word: k){
            int i = 0, j = word.length() - 1;
            while(i < j)
                swap(word[i++], word[j--]);
            ans += word;
            if(word != *(k.end() - 1))
                ans += ' ';
        }
        
            
        return ans;
    }
private:
    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string word;
        while (ss >> word) {
            tokens.push_back(word);
        }
        return tokens;
    }
};
