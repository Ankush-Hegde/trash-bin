#include <iostream>
using namespace std;
#define Const_order 4

class BTreeNode {
    public:
    int *keys; // array of keys
    int numberOfKeys; //current number of keys
    int order; //order of tree
    BTreeNode **pointerToChild; // pointer to child
    bool isLeaf; // is leaf, true when leaf

    BTreeNode(int orderValue) {
        isLeaf = true;
        order = orderValue;
        numberOfKeys = 0;
        keys = new int[order - 1];
        pointerToChild = new BTreeNode *[order];
    }

    // member function 
    // u can access the object of node directly from the function,
    // ex:node1->splitChild(), now u can access object of node1 like keys directly as keys
    void splitChild(int indexOfY, BTreeNode *y);
    void insertNonFull(int data);
    void traverse();
    BTreeNode *search(int k);
};
BTreeNode *root = nullptr;

void BTreeNode::splitChild(int indexOfY, BTreeNode *y)
{
    // Create a new node which is going to store ((order / 2)-1) keys
    // of y
    BTreeNode *newNode = new BTreeNode(y->order);
    newNode->isLeaf = y->isLeaf;
    newNode->numberOfKeys = (y->order / 2) - 1;

    // Copy the last ((order / 2)-1) keys of y to newNode
    for (int j = 0; j < (y->order / 2)-1; j++)
        newNode->keys[j] = y->keys[j+(y->order / 2)];

    // Copy the last (order / 2) children of y to newNode
    if (!y->isLeaf)
    {
        for (int j = 0; j < (y->order / 2); j++)
            newNode->pointerToChild[j] = y->pointerToChild[j+(y->order / 2)];
    }

    // Reduce the number of keys in y
    y->numberOfKeys = (y->order / 2) - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = numberOfKeys; j >= indexOfY+1; j--)
        pointerToChild[j+1] = pointerToChild[j];

    // Link the new child to this node
    pointerToChild[indexOfY+1] = newNode;

    // A key of y will move to this node. Find the location of
    // new key and move all greater keys one space ahead
    for (int j = numberOfKeys-1; j >= indexOfY; j--)
        keys[j+1] = keys[j];

    // Copy the middle key of y to this node
    keys[indexOfY] = y->keys[(y->order / 2)-1];

    // Increment count of keys in this node
    numberOfKeys++;
}

// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
void BTreeNode::insertNonFull(int data)
{
    // Initialize index as index of rightmost element
    int i = numberOfKeys-1;

    // If this is a leaf node
    if (isLeaf == true)
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while (i >= 0 && keys[i] > data)
        {
            keys[i+1] = keys[i];
            i--;
        }

        // Insert the new key at found location
        keys[i+1] = data;
        numberOfKeys = numberOfKeys+1;
    }
    else // If this node is not leaf
    {
        // Find the child which is going to have the new key
        while (i >= 0 && keys[i] > data)
            i--;

        // See if the found child is full
        if (pointerToChild[i+1]->numberOfKeys == order-1)
        {
            // If the child is full, then split it
            // u can call this function without -> since parent function is member function
            // calling member function inside member function dosent need ->
            splitChild(i+1, pointerToChild[i+1]);

            // After split, the middle key of pointerToChild[i] goes up and
            // pointerToChild[i] is splitted into two.  See which of the two
            // is going to have the new key
            if (keys[i+1] < data)
                i++;
        }
        pointerToChild[i+1]->insertNonFull(data);
    }
}

void insert(int data) {

    if (root == nullptr) { // if  tree is empty
        root = new BTreeNode(Const_order); // create new node of order 4
        root->keys[0]= data; // insert key
        root->numberOfKeys= 1;
    }
    else {
        if (root->numberOfKeys==root->order-1) { // check if root is full
            // Allocate memory for new root
            BTreeNode *newRoot = new BTreeNode(root->order);

            // Make old root as child of new root
            newRoot->pointerToChild[0] = root;
            newRoot->isLeaf = false;

            // Split the old root and move 1 key to the new root
            newRoot->splitChild(0, root);

            // New root has two children now. Decide which of the
            // two children is going to have new key
            int i = 0;
            if (newRoot->keys[0] < data)
                i++;
            newRoot->pointerToChild[i]->insertNonFull(data);

            // Change root
            root = newRoot;
        }
        else // If root is not full, call insertNonFull for root
            root->insertNonFull(data);
    }
}

// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse()
{
    // There are n keys and n+1 children, traverse through n keys
    // and first n children
    int i;
    for (i = 0; i < numberOfKeys; i++)
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if (isLeaf == false)
            pointerToChild[i]->traverse();
        cout << " " << keys[i];
    }

    // Print the subtree rooted with last child
    if (isLeaf == false)
        pointerToChild[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode *BTreeNode::search(int k)
{
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < numberOfKeys && k > keys[i])
        i++;

    // If the found key is equal to k, return this node
    if (keys[i] == k)
        return this;

    // If key is not found here and this is a leaf node
    if (isLeaf == true)
        return NULL;

    // Go to the appropriate child
    return pointerToChild[i]->search(k);
}

int main()
{
    int arr[] = {8, 5, 7, 6, 1, 4, 2, 3, 9, 10};

    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
        insert(arr[i]);
    }

    cout << "\nTraversal of the constructed tree is: \n";
    root->traverse();

    int k = 2;
    (root->search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";

    return 0;
}

////////////////split child for both even and odd order 

// void BTreeNode::splitChild(int indexOfY, BTreeNode *y)
// {
//     int t = (order + 1) / 2; // This is the middle index calculation

//     // Create a new node which is going to store (t-1) keys of y
//     BTreeNode *newNode = new BTreeNode(y->order);
//     newNode->isLeaf = y->isLeaf;
//     newNode->numberOfKeys = y->numberOfKeys - t;

//     // Copy the last (t-1) keys of y to newNode
//     for (int j = 0; j < newNode->numberOfKeys; j++)
//         newNode->keys[j] = y->keys[j + t];

//     // Copy the last t children of y to newNode
//     if (!y->isLeaf)
//     {
//         for (int j = 0; j < t; j++)
//             newNode->pointerToChild[j] = y->pointerToChild[j + t];
//     }

//     // Reduce the number of keys in y
//     y->numberOfKeys = t - 1;

//     // Since this node is going to have a new child,
//     // create space of new child
//     for (int j = numberOfKeys; j >= indexOfY + 1; j--)
//         pointerToChild[j + 1] = pointerToChild[j];

//     // Link the new child to this node
//     pointerToChild[indexOfY + 1] = newNode;

//     // A key of y will move to this node. Find the location of
//     // new key and move all greater keys one space ahead
//     for (int j = numberOfKeys - 1; j >= indexOfY; j--)
//         keys[j + 1] = keys[j];

//     // Copy the middle key of y to this node
//     keys[indexOfY] = y->keys[t - 1];

//     // Increment count of keys in this node
//     numberOfKeys++;
// }




/////////////////////
// void BTreeNode::traverse(int depth) {
//     // Print spaces for indentation according to the depth of the node
//     for (int i = 0; i < depth; i++) {
//         cout << "          ";
//     }

//     // Print the current node's keys
//     for (int i = 0; i < numberOfKeys; i++) {
//         cout << keys[i] << " ";
//     }
//     cout << endl;

//     // Recur for all child nodes
//     for (int i = 0; i <= numberOfKeys; i++) {
//         if (!isLeaf) {
//             pointerToChild[i]->traverse(depth + 1);
//         }
//     }
// }
// root->traverse(0); call in main function



/////////////////////////////////
//test//////////////////////
// #include <iostream>
// using namespace std;
// #define Const_order 3

// class BTreeNode {
//     public:
//     int *keys; 
//     int numberOfKeys;
//     int order; 
//     BTreeNode **pointerToChild; 
//     bool isLeaf;
//     BTreeNode(int orderValue) {
//         isLeaf = true;
//         order = orderValue;
//         numberOfKeys = 0;
//         keys = new int[order - 1];
//         pointerToChild = new BTreeNode *[order];
//     }
//     void splitChild(int indexOfY, BTreeNode *y);
//     void insertNonFull(int data);
//     void traverse(int depth);
//     BTreeNode *search(int k);
// };
// BTreeNode *root = nullptr;
// void BTreeNode::splitChild(int indexOfY, BTreeNode *y)
// {
//     BTreeNode *newNode = new BTreeNode(y->order);
//     newNode->isLeaf = y->isLeaf;
//     newNode->numberOfKeys = (y->order / 2) - 1;
//     for (int j = 0; j < (y->order / 2); j++)// -1
//         newNode->keys[j] = y->keys[j+(y->order / 2)];
//     if (!y->isLeaf)
//     {
//         for (int j = 0; j < (y->order / 2); j++)
//             newNode->pointerToChild[j] = y->pointerToChild[j+(y->order / 2)];
//     }
//     y->numberOfKeys = (y->order / 2) - 1;
//     for (int j = numberOfKeys; j >= indexOfY+1; j--)
//         pointerToChild[j+1] = pointerToChild[j];
//     pointerToChild[indexOfY+1] = newNode;
//     for (int j = numberOfKeys-1; j >= indexOfY; j--)
//         keys[j+1] = keys[j];
//     keys[indexOfY] = y->keys[(y->order / 2)-1];
//     numberOfKeys++;
// }
// void BTreeNode::insertNonFull(int data)
// {
//     int i = numberOfKeys-1;
//     if (isLeaf == true)
//     {
//         while (i >= 0 && keys[i] > data)
//         {
//             keys[i+1] = keys[i];
//             i--;
//         }
//         keys[i+1] = data;
//         numberOfKeys = numberOfKeys+1;
//     }
//     else 
//     {
//         while (i >= 0 && keys[i] > data)
//             i--;
//         if (pointerToChild[i+1]->numberOfKeys == order-1)
//         {
//             splitChild(i+1, pointerToChild[i+1]);

//             if (keys[i+1] < data)
//                 i++;
//         }
//         pointerToChild[i+1]->insertNonFull(data);
//     }
// }
// void insert(int data) {

//     if (root == nullptr) {
//         root = new BTreeNode(Const_order);
//         root->keys[0]= data;
//         root->numberOfKeys= 1;
//     }
//     else {
//         if (root->numberOfKeys==root->order-1) { 
//             BTreeNode *newRoot = new BTreeNode(root->order);

//             newRoot->pointerToChild[0] = root;
//             newRoot->isLeaf = false;
            
//             newRoot->splitChild(0, root);

//             int i = 0;
//             if (newRoot->keys[0] < data)
//                 i++;
//             newRoot->pointerToChild[i]->insertNonFull(data);

//             root = newRoot;
//         }
//         else 
//             root->insertNonFull(data);
//     }
// }
// int main()
// {
//     int arr[] = {8, 5, 7, 6};
//     for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
//         insert(arr[i]);
//     }return 0;
// }