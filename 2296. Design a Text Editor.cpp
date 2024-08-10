class TextEditor {
public:
    TextEditor() {
        head = new Node('*');
        cursor = head;
    }

    void addText(string text) {     
        for(char ch: text){
            auto temp = new Node(ch);
            if(cursor->next){
                cursor->next->prev = temp;
                temp->next = cursor->next;
            }

            cursor->next = temp;
            temp->prev = cursor;
            cursor = cursor->next;
        }
        
    }
    
    int deleteText(int k) {
        int i = k;
        auto dStart = cursor;
        for(; i > 0 && cursor->prev; i--){
            cursor = cursor->prev;
        }

        if(i > 0){
            head->next = dStart->next;
            cursor = head;
        }else{
            cursor->next->prev = nullptr;
            cursor->next = dStart->next;
        }
        if(dStart->next)
            dStart->next->prev = cursor;

        return k - i;
    }
    
    string cursorLeft(int k) {
        string ans = "";
        for(int i = k; i > 0 && cursor->prev; cursor = cursor->prev, i--);
        for(auto curr = cursor; curr->prev; curr = curr->prev){
            ans += curr->val;
            if(ans.length() > 9)
                break;
        }
        for(int L = 0, R = ans.length()-1; L < R;)
            swap(ans[L++], ans[R--]);

        return ans;
    }
    
    string cursorRight(int k) {
        string ans = "";
        for(int i = k; i > 0 && cursor->next; cursor = cursor->next, i--);
        for(auto curr = cursor; curr->prev; curr = curr->prev){
            ans += curr->val;
            if(ans.length() > 9)
                break;
        }
        for(int L = 0, R = ans.length()-1; L < R;)
            swap(ans[L++], ans[R--]);

        return ans;
    }
private:
    class Node{
        public:
            Node* prev = nullptr;
            Node* next = nullptr;
            char val;
            explicit Node(char ch): val(ch){}
    };
    Node* head = nullptr;
    Node* cursor = nullptr;
};
