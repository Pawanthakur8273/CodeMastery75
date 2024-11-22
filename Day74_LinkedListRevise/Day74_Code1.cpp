#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to delete N nodes after M nodes
void deleteNodes(Node* head, int M, int N) {
    Node* current = head;
    while (current) {
        for (int i = 1; i < M && current; ++i)
            current = current->next;
        if (!current) break;

        Node* temp = current->next;
        for (int i = 0; i < N && temp; ++i) {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
        current->next = temp;
        current = temp;
    }
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeSortedLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSortedLists(l1, l2->next);
        return l2;
    }
}

// Function to find the Kth node from the end
Node* findKthFromEnd(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;
    for (int i = 0; i < k; ++i) {
        if (!fast) return nullptr;
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// Function to find the intersection of two linked lists
Node* getIntersection(Node* head1, Node* head2) {
    Node* a = head1;
    Node* b = head2;
    while (a != b) {
        a = a ? a->next : head2;
        b = b ? b->next : head1;
    }
    return a;
}

// Merge Sort for Linked List
Node* merge(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    // Split list into halves
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
}

// Flatten a linked list
struct NodeWithDown {
    int data;
    NodeWithDown* next;
    NodeWithDown* down;
    NodeWithDown(int val) : data(val), next(nullptr), down(nullptr) {}
};

NodeWithDown* mergeDown(NodeWithDown* a, NodeWithDown* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->down = mergeDown(a->down, b);
        return a;
    } else {
        b->down = mergeDown(a, b->down);
        return b;
    }
}

NodeWithDown* flatten(NodeWithDown* root) {
    if (!root || !root->next) return root;

    root->next = flatten(root->next);
    return mergeDown(root, root->next);
}

// Utility functions
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void printFlattenList(NodeWithDown* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->down;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    // Example usage for each function
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    cout << "Original List: ";
    printList(head1);

    cout << "After deleting 2 nodes after 1 node: ";
    deleteNodes(head1, 1, 2);
    printList(head1);

    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "Merged Sorted Lists: ";
    Node* merged = mergeSortedLists(list1, list2);
    printList(merged);

    cout << "3rd Node from the End: ";
    Node* kth = findKthFromEnd(merged, 3);
    if (kth) cout << kth->data << endl;

    Node* inter1 = new Node(1);
    inter1->next = new Node(2);
    inter1->next->next = new Node(3);
    Node* inter2 = new Node(4);
    inter2->next = inter1->next->next;

    cout << "Intersection Node: ";
    Node* intersect = getIntersection(inter1, inter2);
    if (intersect) cout << intersect->data << endl;

    Node* toSort = new Node(4);
    toSort->next = new Node(2);
    toSort->next->next = new Node(1);
    toSort->next->next->next = new Node(3);

    cout << "Sorted List: ";
    Node* sorted = mergeSort(toSort);
    printList(sorted);

    NodeWithDown* flat = new NodeWithDown(5);
    flat->down = new NodeWithDown(7);
    flat->down->down = new NodeWithDown(8);
    flat->next = new NodeWithDown(10);
    flat->next->down = new NodeWithDown(11);

    cout << "Flattened List: ";
    NodeWithDown* flattened = flatten(flat);
    printFlattenList(flattened);

    return 0;
}
