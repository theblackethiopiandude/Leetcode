int minimumRecolors(string blocks, int k) {
       int minRecolor = INT_MAX;
       for(int L = 0, R = 0, recolor = 0; R < blocks.size(); R++){
            if(blocks[R] == 'W')
                recolor++;
            if(R - L + 1 == k){
                minRecolor = min(minRecolor, recolor);

                if(blocks[L++] == 'W')
                    recolor--;
            }
            
       } 
       return minRecolor;
    }
