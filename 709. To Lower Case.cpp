string toLowerCase(string s) {
        for(int i = 0; i < s.length(); i++)
            if(65 <= s[i] && s[i] <= 90)
                s[i] += 32;

        return s;
  }

string toLowerCase(string s) {
        for(char& ch: s)
            if(65 <= ch && ch <= 90)
                ch |= 32; // can also be SPACE ' '

        return s;
}
