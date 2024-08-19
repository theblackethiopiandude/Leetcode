char repeatedCharacter(string s) {
        vector<int> set(26, 0);
        for(char ch: s){
            if(set[ch-97])
                return ch;

            set[ch-97] = 1;
        }
        
        return -1;
  }
