class BrowserHistory {
public:
    explicit BrowserHistory(const string& homepage) {
      curr = new Node(homepage);
    }
    
    void visit(const string& url) {
        Node* temp = curr->next;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
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
            explicit Node(const string& value):value(value){ }
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
