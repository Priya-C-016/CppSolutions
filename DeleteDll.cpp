void deleteNode(Node* &head, int val) {
    if (head == NULL) return;

    Node* temp = head;

    // If head needs to be deleted
    if (temp->data == val) {
        head = temp->next;
        if (head) head->prev = NULL;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
}
