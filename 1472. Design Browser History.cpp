class BrowserHistory {
public:
    BrowserHistory(string homepage) {
      curr = new Node(homepage);
    }
    
    void visit(string url) {
        auto node = new Node(url);
        curr->next = node;
        node->prev = curr;
        curr = node;
    }
    
    string back(int steps) {
        while(curr->prev && steps--)
            curr = curr->prev;
        
        return curr->value;
    }
    
    string forward(int steps) {
        while(curr->next && steps--)
            curr = curr->next;

        return curr->value;
    }
private:
    class Node{
        public:
            string value;
            Node* prev = nullptr;
            Node* next = nullptr;
            Node(string value):value(value){ }
    };

    Node* curr = nullptr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
