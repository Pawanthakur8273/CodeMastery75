#include<iostream>
#include<queue>
using namespace std;

class Node{
 public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertAtBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root->data > data){
        root->left = insertAtBST(root->left, data);
    }
    else{
        root->right = insertAtBST(root->right, data);
    }
    return root;

}

void CreateBST(Node* &root){
    cout << "Enter Data: " << endl;
    int data;
    cin >> data;

    while(data != -1){
        root = insertAtBST(root, data);
        cout << "Enter Data: " << endl;
        cin >> data;
    }
}

void levelOrderTravversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

}

Node* getMax(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while(temp != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* getMin(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while(temp != NULL){
        temp = temp->left;
    }
    return temp;
}

bool isPresent(Node* root, int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    else if(root->data > target){
        return isPresent(root->left, target);
    }
    else{
        return isPresent(root->right, target);
    }
}

void preOrder(Node* root){
    if(root == NULL){
        cout << "Can not traverse root is NULL"<< endl;
        return;
    }
    //NLR
    cout << root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(Node* root){
    if(root == NULL){
        cout << "Can not traverse root is NULL"<< endl;
        return;
    }
    //LNR
    InOrder(root->left);
    cout << root->data <<" ";
    InOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        cout << "Can not traverse root is NULL"<< endl;
        return;
    }
    //RNL
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data <<" ";
}

Node* deleteFromBST(Node* &root, int target){
    if(root == NULL){
        return NULL;
    }
    if(root->data == target){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        else{
            Node* Mini = getMin(root->right);
            root->data = Mini->data;
            root->right = deleteFromBST(root->right, Mini->data);

        }
    }
    else if(root->data > target){
        root->left = deleteFromBST(root->left, target);
    }
    else{
        root->right = deleteFromBST(root->right, target);
    }
}

Node* bstFromInordet(int inorder[], int s, int e){
    if(s > e){
        return NULL;
    }
    int min = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = bstFromInordet(inorder, s, mid-1);
    root->right = bstFromInordet(inorder, mid+1, e);

    return root;
}

void convertBSTtoDLL(Node* root, Node* &head){
    if(root == NULL){
        return;
    }
    //RNL
    convertBSTtoDLL(root->right, head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;
    convertBSTtoDLL(root->left, head);
}

Node* convertDLLtoBST(Node* &head, int n){
    if(head == NULL || n<=0){
        return NULL;
    }
    //LNR
    Node* leftSubtree = convertDLLtoBST(head, n/2);
    Node* root = head;
    root->left = leftSubtree;
    head = head->right;
    Node* rightSubtree = convertDLLtoBSt(head, n-n/2-1);
    root->right = rightSubtree;
    return root;
}

int main() {
    Node* root = NULL; // Create an empty tree

    // Create BST by taking input until -1 is entered
    CreateBST(root); 

    // Level-order traversal of the BST
    cout << "Level Order Traversal: " << endl;
    levelOrderTravversal(root);

    // Get the maximum node in the BST
    Node* maxNode = getMax(root);
    if (maxNode != NULL) {
        cout << "Maximum Value: " << maxNode->data << endl;
    }

    // Get the minimum node in the BST
    Node* minNode = getMin(root);
    if (minNode != NULL) {
        cout << "Minimum Value: " << minNode->data << endl;
    }

    // Check if a value is present in the BST
    int target = 10;
    if (isPresent(root, target)) {
        cout << target << " is present in the BST." << endl;
    } else {
        cout << target << " is not present in the BST." << endl;
    }

    // Pre-order traversal (NLR)
    cout << "Pre-Order Traversal: " << endl;
    preOrder(root);
    cout << endl;

    // In-order traversal (LNR)
    cout << "In-Order Traversal: " << endl;
    InOrder(root);
    cout << endl;

    // Post-order traversal (LRN)
    cout << "Post-Order Traversal: " << endl;
    postOrder(root);
    cout << endl;

    // Delete a node from BST
    int deleteValue = 5;
    root = deleteFromBST(root, deleteValue);
    cout << "After deleting " << deleteValue << ": " << endl;
    levelOrderTravversal(root);

    return 0;
}
