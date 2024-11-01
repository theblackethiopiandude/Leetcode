string getHint(string secret, string guess) {
        unordered_map<char, int> umap;
        for(const char ch: secret)
            umap[ch]++;
        
        int x = 0, y = 0, z = 0;
        for(int i = 0; i < secret.length(); i++){
            if(umap.count(guess[i])){
                if(guess[i] == secret[i]){
                    x++;
                    umap[guess[i]]--;
                }    
            }
        }

        for(int i = 0; i < secret.length(); i++){
            if(umap.count(guess[i])){
                if(guess[i] != secret[i] && umap[guess[i]] > 0){
                    y++;
                    umap[guess[i]]--;
                }
            }
        }

        ostringstream oss;
        oss << x << 'A' << y << 'B';

        return oss.str();

    }

string getHint(string secret, string guess) {
        unordered_map<char, int> umap;
        int x = 0, y = 0;

        for(int i = 0; i < secret.length(); i++){
            if(guess[i] == secret[i])
                x++;
            else
                umap[secret[i]]++;
        }
        
        for(int i = 0; i < secret.length(); i++){
            if(umap.count(guess[i])){
                if(guess[i] != secret[i] && umap[guess[i]] > 0){
                    y++;
                    umap[guess[i]]--;
                }

            }
        }

        ostringstream oss;
        oss << x << 'A' << y << 'B';

        return oss.str();
    }
