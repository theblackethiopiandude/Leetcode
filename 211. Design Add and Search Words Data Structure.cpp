class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(const string& word) {
        auto curr = head;
            for(char ch : word){
                if(curr->child[ch - 'a'] == nullptr)
                    curr->child[ch - 'a'] = new Node(ch);

                curr = curr->child[ch - 'a'];
            }
        curr->end = true;
    }
    
    bool search(const string& word) {
        bool found = true;
        search(head, word, 0, found);
        return found;
    }
private:
    class Node {
        public:
            char value;
            Node* child[26] = {nullptr};
            bool end = false;
            explicit Node(char value) : value(value){
                for(int i = 0; i < 26; i++){
                    child[i] = nullptr;
                }
            }
    };
    Node* head = new Node(' ');
    void search(Node* node, const std::string& word, int index, bool& found){
            if(!node){
                found = false;
                return;
            }
            if(index == word.length()){
                found = node->end;
                return;
            }
            auto curr = (word[index] == '.')? nullptr: node->child[word[index] - 'a'];
            if(!curr && word[index] != '.'){
                found = false;
                return;
            }
            if(word[index] == '.'){
                bool average = false;
                for(const auto& value: node->child) {
                    bool valid = true;
                    search(value, word, index + 1, valid);
                    average = average || valid;
                    if(average)
                        break;
                }
                found = average;
            }
            if(!curr)
                return;
            search(curr, word, index + 1, found);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
