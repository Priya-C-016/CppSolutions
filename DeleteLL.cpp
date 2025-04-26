void deleteNode(Node* &head, int val) {
    if (head == NULL) return;

    if (head->data == val) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if (temp->next == NULL) return;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
