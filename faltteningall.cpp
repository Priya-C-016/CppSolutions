 Node* flatten(Node* head) {
        if (!head) return nullptr;

    stack<Node*> st;
    Node* curr = head;

    while (curr) {
        if (curr->child) {
            //  Save next in stack if it exists
            if (curr->next) {
                st.push(curr->next);
            }

            // Connect child as next
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = nullptr;
        }

        // If end of level and stack not empty
        if (!curr->next && !st.empty()) {
            Node* temp = st.top();
            st.pop();
            curr->next = temp;
            temp->prev = curr;
        }

        // Move ahead
        curr = curr->next;
    }

    return head;
    }
