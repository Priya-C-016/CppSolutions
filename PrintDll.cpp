void printForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printBackward(Node* head) {
    if (head == NULL) return;

    // Go to last node
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    // Traverse backward
    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
