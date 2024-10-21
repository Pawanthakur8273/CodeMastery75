#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInToBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (root->data > data) {
        root->left = insertInToBST(root->left, data);
    } else {
        root->right = insertInToBST(root->right, data);
    }
    return root;
}

void CreateBST(Node*& root) {
    cout << "Enter Data: " << endl;
    int data;
    cin >> data;

    while (data != -1) {
        root = insertInToBST(root, data);
        cout << "Enter Data: " << endl;
        cin >> data;
    }
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    // NLR
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void InorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    // LNR
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    // LRN
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void LevelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

int getMin(Node* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

Node* getMax(Node* root) {
    if (root == NULL) {
        cout << "No Node is present, Hence Returning NULL..." << endl;
        return NULL;
    }
    Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

bool BinarySearch(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    } else if (root->data > target) {
        return BinarySearch(root->left, target);
    } else {
        return BinarySearch(root->right, target);
    }
}

Node* deleteFromBst(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == target) {
        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: Node with one child
        else if (root->left != NULL && root->right == NULL) {
            Node* ChildSubTree = root->left;
            delete root;
            return ChildSubTree;
        } else if (root->left == NULL && root->right != NULL) {
            Node* ChildSubTree = root->right;
            delete root;
            return ChildSubTree;
        }
        // Case 3: Node with two children
        else {
            Node* maxi = getMax(root->left);  // You could also use getMin from the right subtree
            root->data = maxi->data;
            root->left = deleteFromBst(root->left, maxi->data);
            return root;
        }
    } else if (root->data > target) {
        root->left = deleteFromBst(root->left, target);
    } else {
        root->right = deleteFromBst(root->right, target);
    }
    return root;
}

int main() {
    Node* root = NULL;
    CreateBST(root);
    cout << endl;

    cout << "Levelorder Traversal: " << endl;
    LevelOrderTraversal(root);
    cout << endl;

    cout << "PreOrder Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "InOrder Traversal: " << endl;
    InorderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: " << endl;
    postOrderTraversal(root);
    cout << endl;

    cout << "Mini Element of Tree is: " << endl;
    cout << getMin(root);
    cout << endl;

    cout << "Maxi Element of Tree is: " << endl;
    Node* maxi = getMax(root);
    if (maxi != NULL) {
        cout << maxi->data << endl;
    }
    cout << endl;

    cout << "Binary Search on BST: " << endl;
    bool found = BinarySearch(root, 110);
    if (found) {
        cout << "Element is present" << endl;
    } else {
        cout << "Element is absent" << endl;
    }

    int target;
    cout << "Enter the value of target: " << endl;
    cin >> target;
    while (target != -1) {
        deleteFromBst(root, target);
        LevelOrderTraversal(root);
        cout << "Enter the value of target: " << endl;
        cin >> target;
    }

    return 0;
}
