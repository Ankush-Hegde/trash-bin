#include <iostream>
using namespace std;
// insertion
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	char colour;
	
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
		parent = NULL;
		colour = 'R'; //default will be R if root B
	}
};

bool ll;
bool rr;
bool lr;
bool rl;
Node* root = nullptr;

Node* rotateLeft(Node* node) {
    Node* x = node->right;
    Node* y = x->left;
    
    //perform rotation
    x->left = node;
    node->right = y;
    
    node->parent = x;
    if (y != nullptr)
        y->parent = node;
    return x;
}

// Function to perform Right Rotation
Node* rotateRight(Node* node) {
    Node* x = node->left;
    Node* y = x->right;
    
    //perform rotation
    x->right = node;
    node->left = y;
    
    node->parent = x;
    if (y != nullptr)
        y->parent = node;
    return x;
}

Node* insertHelp(Node* root, int data) {
        bool f = false; // Flag to check RED-RED conflict
 
        if (root == NULL)
            return new Node(data);
        else if (data < root->data) {
            root->left = insertHelp(root->left, data);
            root->left->parent = root;
            // if (root != this->root) {
                if (root->colour == 'R' && root->left->colour == 'R')
                    f = true;
            // }
        } else {
            root->right = insertHelp(root->right, data);
            root->right->parent = root;
            // if (root != this->root) {
                if (root->colour == 'R' && root->right->colour == 'R')
                    f = true;
            // }
        }
 
        // Perform rotations
        if (ll) {
            root = rotateLeft(root);
            root->colour = 'B';
            root->left->colour = 'R';
            ll = false;
        } else if (rr) {
            root = rotateRight(root);
            root->colour = 'B';
            root->right->colour = 'R';
            rr = false;
        } else if (rl) {
            root->right = rotateRight(root->right);
            root->right->parent = root;
            root = rotateLeft(root);
            root->colour = 'B';
            root->left->colour = 'R';
            rl = false;
        } else if (lr) {
            root->left = rotateLeft(root->left);
            root->left->parent = root;
            root = rotateRight(root);
            root->colour = 'B';
            root->right->colour = 'R';
            lr = false;
        }
 
        // Handle RED-RED conflicts
        if (f) {
            if (root->parent->right == root) {
                if (root->parent->left == nullptr || root->parent->left->colour == 'B') {
                    if (root->left != nullptr && root->left->colour == 'R')
                        rl = true;
                    else if (root->right != nullptr && root->right->colour == 'R')
                        ll = true;
                } else {
                    root->parent->left->colour = 'B';
                    root->colour = 'B';
                    // if (root->parent != this->root)
                        root->parent->colour = 'R';
                }
            } else {
                if (root->parent->right == nullptr || root->parent->right->colour == 'B') {
                    if (root->left != nullptr && root->left->colour == 'R')
                        rr = true;
                    else if (root->right != nullptr && root->right->colour == 'R')
                        lr = true;
                } else {
                    root->parent->right->colour = 'B';
                    root->colour = 'B';
                    // if (root->parent != this->root)
                        root->parent->colour = 'R';
                }
            }
            f = false;
        }
        return root;
    }
    
    void printTreeHelper(Node* root, int space) {
        if (root != nullptr) {
            space += 10;
            printTreeHelper(root->right, space);
            cout << endl;
            for (int i = 10; i < space; i++)
                cout << " ";
            cout << root->data << endl;
            printTreeHelper(root->left, space);
        }
    }
    
// Function to insert data into the tree
void insert(int data) {
    if (root == nullptr) {
        root = new Node(data);
        root->colour = 'B';
    } else
        root = insertHelp(root, data);
}
    
void printTree() {
    printTreeHelper(root, 0);
}

int main() {
// Test the RedBlackTree
    int arr[] = {1, 4, 6, 3, 5, 7, 8, 2, 9};
    for (int i = 0; i < 9; i++) {
        insert(arr[i]);
        cout << endl;
    }
    printTree();
    return 0;
}