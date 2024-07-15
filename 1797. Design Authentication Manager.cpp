class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive){}
    
    void generate(string tokenId, int currentTime) {
        auto node = new Node(make_pair(tokenId, currentTime));
        addNode(node);
        umap[tokenId] = node;
    }
    
    void renew(string tokenId, int currentTime) {
        if(umap.count(tokenId)){
            auto startTime = umap[tokenId]->token.second;
            if(currentTime < startTime + ttl)
                moveToFront(umap[tokenId], currentTime);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto node = head;
        int count = 0;
        while(node != nullptr){
            if(currentTime < node->token.second + ttl)
                count++;
            else{
                if(node->next)
                    node->next = nullptr;
                tail = node;
                break;
            }
                
            
            node = node->next;
        }
        return count;
    }
    private:
        class Node{
            public:
                pair<string, int> token;
                Node* next = nullptr;
                Node* prev = nullptr;
                explicit Node(const pair<string, int>& token):token(token){}
        };

        Node* head = nullptr;
        Node* tail = nullptr;
        unordered_map<string, Node*> umap;
        int ttl;
        
        void addNode(Node* node){
            if(head == nullptr){
                head = node;
                tail = node;
            }else{
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
        void moveToFront(Node* node, int currentTime){
            if(node == head){
            }else if(node == tail){
                tail->prev->next = nullptr;
                tail = tail->prev;
            }else{
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            node->token.second = currentTime;
            addNode(node);
        }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
