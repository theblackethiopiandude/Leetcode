bool checkIfPangram(string sentence) {
        unordered_set<char> us;
        for(const char ch: sentence){
            us.insert(ch);
            if(us.size() == 26) return true;
        }
        return false;
    }
