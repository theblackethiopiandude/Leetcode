int strStr(string haystack, string needle) {
        int L = 0, l = 0, start = -1;
        int R = haystack.length(), r = needle.length();
        if(r > R)
            return -1;

        while(L < R){
            if(haystack[L] == needle[l]){
                L++, l++;
                if(l == 1)
                    start = L;
                if(l == r)
                    return L - r;
            }
            else if(l > 0){
                l = 0;
                L = start;
                start = -1;
            }else
                L++;

        }
        
        return -1;
    }
