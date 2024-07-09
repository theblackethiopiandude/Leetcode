void deleteNode(ListNode* node) {
        auto n = node->next;
        node->val = n->val;
        node->next = n->next;
        delete n;
    }
