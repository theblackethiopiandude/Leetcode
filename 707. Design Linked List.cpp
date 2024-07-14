class MyLinkedList {
public:
    MyLinkedList() {
        
    }

    ~MyLinkedList() {
        auto current = head;
        while(current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        } 
    }

    int get(int index) {
        if(index < size){
            if(index == 0)
                return head->val;
            else if(index == size-1)
                return tail->val;
            else{
                auto curr = head;
                for(int i = 0; i < index; curr = curr->next, i++)
                    continue;
                return curr->val;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        auto node = new Node(val);
        if(head){
            node->next = head;
            head->prev = node;
        }else
            tail = node;
        head = node;
        size++;
    }
    
    void addAtTail(int val) {
        auto node = new Node(val);
        if(tail){
            node->prev = tail;
            tail->next = node;
        }else
            head = node;

        tail = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index <= size){
            if(index == 0)
                addAtHead(val);
            else if(index == size)
                addAtTail(val);
            else{
                auto node = new Node(val);
                auto curr = head;
                for(int i = 0; i < index; curr = curr->next, i++)
                    continue;
                node->prev = curr->prev;
                curr->prev->next = node;
                curr->prev = node;
                node->next = curr;
                size++;
            }
            
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < size){
            size--;
            if(head == tail){
                head = nullptr;
                tail = nullptr;
                return;
            }else if(index == 0){
                head->next->prev = nullptr;
                head = head->next;
            }else if(index == size){
                tail->prev->next = nullptr;
                tail = tail->prev;
            }else{
                auto curr = head;
                for(int i = 0; i < index; curr = curr->next, i++)
                    continue;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
        }
    }
private:
    class Node {
        public:
            int val;
            Node* prev = nullptr;
            Node* next = nullptr;
            explicit Node(const int val) : val(val) {}
        };

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
