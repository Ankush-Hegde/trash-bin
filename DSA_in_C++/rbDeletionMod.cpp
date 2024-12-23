#include <iostream>
using namespace std;
// modified
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

Node* inorderSuccessor(Node* node) {
    while (node->left != NULL) {
      node = node->left;
    }
    return node;
  }

void DELETEFIX(Node* x) { //fix double black conflict
    while (x != root && x->colour == 'B') {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->colour == 'R') {
                w->colour = 'B';
                x->parent->colour = 'R';
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->left->colour == 'B' && w->right->colour == 'B') {
                w->colour = 'R';
                x = x->parent;
            } else {
                if (w->right->colour == 'B') {
                    w->left->colour = 'B';
                    w->colour = 'R';
                    rotateRight(w);
                    w = x->parent->right;
                }
                w->colour = x->parent->colour;
                x->parent->colour = 'B';
                w->right->colour = 'B';
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->colour == 'R') {
                w->colour = 'B';
                x->parent->colour = 'R';
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->colour == 'B' && w->left->colour == 'B') {
                w->colour = 'R';
                x = x->parent;
            } else {
                if (w->left->colour == 'B') {
                    w->right->colour = 'B';
                    w->colour = 'R';
                    rotateLeft(w);
                    w = x->parent->left;
                }
                w->colour = x->parent->colour;
                x->parent->colour = 'B';
                w->left->colour = 'B';
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->colour = 'B';
}

// void RBTRANSPLANT(Node* u, Node* v) {
//     if (u->parent == nullptr) {
//         root = v;
//     } else if (u == u->parent->left) {
//         u->parent->left = v;
//     } else {
//         u->parent->right = v;
//     }
//     v->parent = u->parent;
// }


void RBTRANSPLANT(Node* u, Node* v) { // swap node
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent; // Update parent pointer of v
    }
}

void DELETENODEHELPER(Node* node, int key) { // delete function
    Node* z = nullptr;
    Node* x = nullptr, *y = nullptr;
    while (node != nullptr) {
        if (node->data == key) {
            z = node;
            break; // Node found, exit the loop
        }
        if (node->data < key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    
    if (z == nullptr) {
        cout << "Node with key " << key << " not found." << endl;
        return;
    }

    char y_original_colour = z->colour;
    if (z->left == nullptr) {
        x = z->right;
        RBTRANSPLANT(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        RBTRANSPLANT(z, z->left);
    } else {
        y = inorderSuccessor(z->right);
        y_original_colour = y->colour;
        x = y->right;
        if (y->parent != z) {
            RBTRANSPLANT(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        RBTRANSPLANT(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->colour = z->colour;
    }
    delete z;
    if (y_original_colour == 'B') {
        DELETEFIX(x);
    }
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
            cout << root->data<<root->colour << endl;
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

void deleteNode(int key) {
    DELETENODEHELPER(root, key);
}

int main() {
// Test the RedBlackTree
    int arr[] = {1, 4, 6, 3, 5, 7, 8, 2, 9};
    for (int i = 0; i < 9; i++) {
        insert(arr[i]);
        cout << endl;
    }
    printTree();
    deleteNode(6);
    // cout<<"+++++++++++++++++++";
    printTree();
    return 0;
}