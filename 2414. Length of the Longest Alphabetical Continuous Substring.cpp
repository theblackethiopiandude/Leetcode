int longestContinuousSubstring(string s) {
        int maxSeq = 1;
        for(int R = 1, currSeq = 1; R < s.size(); R++){
            if(s[R] - s[R-1] == 1)
                currSeq++;
            else
                currSeq = 1;
    
            maxSeq = max(maxSeq, currSeq);
        }
        return maxSeq;
    }

int longestContinuousSubstring(string s) {
        int maxSeq = 1;
        for(int R = 1, currSeq = 1; R < s.size(); R++){
            currSeq = (s[R] - s[R-1] == 1)? currSeq + 1 : 1;    
            maxSeq = max(maxSeq, currSeq);
        }
        
        return maxSeq;
    }
