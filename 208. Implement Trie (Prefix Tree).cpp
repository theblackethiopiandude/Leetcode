class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        auto curr = head;
        for(char ch: word){
            if(!curr->child.count(ch))
                curr->child[ch] = new Node(ch);

            curr = curr->child[ch];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        auto curr = head;
        for(char ch: word){
            if(!curr->child.count(ch))
                return false;
                
            curr = curr->child[ch];
        }

        return curr->end;
    }
    
    bool startsWith(string prefix) {
        auto curr = head;
        for(char ch: prefix){
            if(!curr->child.count(ch))
                return false;
                
            curr = curr->child[ch];
        }

        return true;
    }
private:
    class Node {
        public:
            unordered_map<char, Node*> child;
            bool end = false;
            char value;
            
            explicit Node(char value) : value(value){

            }
    };
    Node* head = new Node(' ');
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
