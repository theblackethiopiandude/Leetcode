class AuthenticationManager {
public:
    
    AuthenticationManager(int timeToLive):ttl(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        umap[tokenId]= currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(umap.count(tokenId)){
            if(currentTime < umap[tokenId])
                umap[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto [_, expiryTime]: umap) 
            if(currentTime < expiryTime)
                count++;

        return count;
    }
    private:
        unordered_map<string, int> umap;
        int ttl;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
