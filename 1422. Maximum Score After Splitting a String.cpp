int maxScore(string s) {
        int zero = 0;
        int one = 0;

        for(int i = 0; i < s.length(); i++)
            if(s[i] == '1')
                one++;
        
        int ans = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == '0')
                zero++;
            else if(s[i] == '1')
                one--;

            ans = max(ans, zero + one);
        }


        return ans;
    }
