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

    void splitChild(int indexOfY, BTreeNode *y);
    void insertNonFull(int data);
    void traverse(int depth);
    BTreeNode *search(int k);

    // A function that returns the index of the first key that is greater
    // or equal to k
    int findKey(int k);

    // A wrapper function to remove the key k in subtree rooted with
    // this node.
    void remove(int k);

    // A function to remove the key present in idx-th position in
    // this node which is a leaf
    void removeFromLeaf(int idx);

    // A function to remove the key present in idx-th position in
    // this node which is a non-leaf node
    void removeFromNonLeaf(int idx);

    // A function to get the predecessor of the key- where the key
    // is present in the idx-th position in the node
    int getPred(int idx);

    // A function to get the successor of the key- where the key
    // is present in the idx-th position in the node
    int getSucc(int idx);

    // A function to fill up the child node present in the idx-th
    // position in the pointerToChild[] array if that child has less than t-1 keys
    void fill(int idx);

    // A function to borrow a key from the pointerToChild[idx-1]-th node and place
    // it in pointerToChild[idx]th node
    void borrowFromPrev(int idx);

    // A function to borrow a key from the pointerToChild[idx+1]-th node and place it
    // in pointerToChild[idx]th node
    void borrowFromNext(int idx);

    // A function to merge idx-th child of the node with (idx+1)th child of
    // the node
    void merge(int idx);
};
BTreeNode *root = nullptr;
//////////////

// A utility function that returns the index of the first key that is
// greater than or equal to k
int BTreeNode::findKey(int k)
{
    int idx=0;
    while (idx<numberOfKeys && keys[idx] < k)
        ++idx;
    return idx;
}

// A function to remove the key k from the sub-tree rooted with this node
void BTreeNode::remove(int k)
{
    int idx = findKey(k);

    // The key to be removed is present in this node
    if (idx < numberOfKeys && keys[idx] == k)
    {

        // If the node is a leaf node - removeFromLeaf is called
        // Otherwise, removeFromNonLeaf function is called
        if (isLeaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else
    {

        // If this node is a leaf node, then the key is not present in tree
        if (isLeaf)
        {
            cout<<"The key "<<k<<" is does not exist in the tree\n";
            return;
        }

        // The key to be removed is present in the sub-tree rooted with this node
        // The flag indicates whether the key is present in the sub-tree rooted
        // with the last child of this node
        bool flag = ( (idx==numberOfKeys)? true : false );

        // If the child where the key is supposed to exist has less that order keys,
        // we fill that child
        if (pointerToChild[idx]->numberOfKeys < order)
            fill(idx);

        // If the last child has been merged, it must have merged with the previous
        // child and so we recurse on the (idx-1)th child. Else, we recurse on the
        // (idx)th child which now has atleast t keys
        if (flag && idx > numberOfKeys)
            pointerToChild[idx-1]->remove(k);
        else
            pointerToChild[idx]->remove(k);
    }
    return;
}

// A function to remove the idx-th key from this node - which is a leaf node
void BTreeNode::removeFromLeaf (int idx)
{

    // Move all the keys after the idx-th pos one place backward
    for (int i=idx+1; i<numberOfKeys; ++i)
        keys[i-1] = keys[i];

    // Reduce the count of keys
    numberOfKeys--;

    return;
}

// A function to remove the idx-th key from this node - which is a non-leaf node
void BTreeNode::removeFromNonLeaf(int idx)
{

    int k = keys[idx];

    // If the child that precedes k (pointerToChild[idx]) has atleast t keys,
    // find the predecessor 'pred' of k in the subtree rooted at
    // pointerToChild[idx]. Replace k by pred. Recursively delete pred
    // in pointerToChild[idx]
    if (pointerToChild[idx]->numberOfKeys >= order)
    {
        int pred = getPred(idx);
        keys[idx] = pred;
        pointerToChild[idx]->remove(pred);
    }

    // If the child pointerToChild[idx] has less that t keys, examine pointerToChild[idx+1].
    // If pointerToChild[idx+1] has atleast order keys, find the successor 'succ' of k in
    // the subtree rooted at pointerToChild[idx+1]
    // Replace k by succ
    // Recursively delete succ in pointerToChild[idx+1]
    else if  (pointerToChild[idx+1]->numberOfKeys >= order)
    {
        int succ = getSucc(idx);
        keys[idx] = succ;
        pointerToChild[idx+1]->remove(succ);
    }

    // If both pointerToChild[idx] and pointerToChild[idx+1] has less that t keys,merge k and all of pointerToChild[idx+1]
    // into pointerToChild[idx]
    // Now pointerToChild[idx] contains 2order-1 keys
    // Free pointerToChild[idx+1] and recursively delete k from pointerToChild[idx]
    else
    {
        merge(idx);
        pointerToChild[idx]->remove(k);
    }
    return;
}

// A function to get predecessor of keys[idx]
int BTreeNode::getPred(int idx)
{
    // Keep moving to the right most node until we reach a leaf
    BTreeNode *cur=pointerToChild[idx];
    while (!cur->isLeaf)
        cur = cur->pointerToChild[cur->numberOfKeys];

    // Return the last key of the leaf
    return cur->keys[cur->numberOfKeys-1];
}

int BTreeNode::getSucc(int idx)
{

    // Keep moving the left most node starting from pointerToChild[idx+1] until we reach a leaf
    BTreeNode *cur = pointerToChild[idx+1];
    while (!cur->isLeaf)
        cur = cur->pointerToChild[0];

    // Return the first key of the leaf
    return cur->keys[0];
}

// A function to fill child pointerToChild[idx] which has less than order-1 keys
void BTreeNode::fill(int idx)
{

    // If the previous child(pointerToChild[idx-1]) has more than order-1 keys, borrow a key
    // from that child
    if (idx!=0 && pointerToChild[idx-1]->numberOfKeys>=order)
        borrowFromPrev(idx);

    // If the next child(pointerToChild[idx+1]) has more than order-1 keys, borrow a key
    // from that child
    else if (idx!=numberOfKeys && pointerToChild[idx+1]->numberOfKeys>=order)
        borrowFromNext(idx);

    // Merge pointerToChild[idx] with its sibling
    // If pointerToChild[idx] is the last child, merge it with its previous sibling
    // Otherwise merge it with its next sibling
    else
    {
        if (idx != numberOfKeys)
            merge(idx);
        else
            merge(idx-1);
    }
    return;
}

// A function to borrow a key from pointerToChild[idx-1] and insert it
// into pointerToChild[idx]
void BTreeNode::borrowFromPrev(int idx)
{

    BTreeNode *child=pointerToChild[idx];
    BTreeNode *sibling=pointerToChild[idx-1];

    // The last key from pointerToChild[idx-1] goes up to the parent and key[idx-1]
    // from parent is inserted as the first key in pointerToChild[idx]. Thus, the  loses
    // sibling one key and child gains one key

    // Moving all key in pointerToChild[idx] one step ahead
    for (int i=child->numberOfKeys-1; i>=0; --i)
        child->keys[i+1] = child->keys[i];

    // If C[idx] is not a leaf, move all its child pointers one step ahead
    if (!child->isLeaf)
    {
        for(int i=child->numberOfKeys; i>=0; --i)
            child->pointerToChild[i+1] = child->pointerToChild[i];
    }

    // Setting child's first key equal to keys[idx-1] from the current node
    child->keys[0] = keys[idx-1];

    // Moving sibling's last child as pointerToChild[idx]'s first child
    if(!child->isLeaf)
        child->pointerToChild[0] = sibling->pointerToChild[sibling->numberOfKeys];

    // Moving the key from the sibling to the parent
    // This reduces the number of keys in the sibling
    keys[idx-1] = sibling->keys[sibling->numberOfKeys-1];

    child->numberOfKeys += 1;
    sibling->numberOfKeys -= 1;

    return;
}

// A function to borrow a key from the pointerToChild[idx+1] and place
// it in pointerToChild[idx]
void BTreeNode::borrowFromNext(int idx)
{

    BTreeNode *child=pointerToChild[idx];
    BTreeNode *sibling=pointerToChild[idx+1];

    // keys[idx] is inserted as the last key in pointerToChild[idx]
    child->keys[(child->numberOfKeys)] = keys[idx];

    // Sibling's first child is inserted as the last child
    // into pointerToChild[idx]
    if (!(child->isLeaf))
        child->pointerToChild[(child->numberOfKeys)+1] = sibling->pointerToChild[0];

    //The first key from sibling is inserted into keys[idx]
    keys[idx] = sibling->keys[0];

    // Moving all keys in sibling one step behind
    for (int i=1; i<sibling->numberOfKeys; ++i)
        sibling->keys[i-1] = sibling->keys[i];

    // Moving the child pointers one step behind
    if (!sibling->isLeaf)
    {
        for(int i=1; i<=sibling->numberOfKeys; ++i)
            sibling->pointerToChild[i-1] = sibling->pointerToChild[i];
    }

    // Increasing and decreasing the key count of pointerToChild[idx] and pointerToChild[idx+1]
    // respectively
    child->numberOfKeys += 1;
    sibling->numberOfKeys -= 1;

    return;
}

// A function to merge pointerToChild[idx] with pointerToChild[idx+1]
// pointerToChild[idx+1] is freed after merging
void BTreeNode::merge(int idx)
{
    BTreeNode *child = pointerToChild[idx];
    BTreeNode *sibling = pointerToChild[idx+1];

    // Pulling a key from the current node and inserting it into (t-1)th
    // position of pointerToChild[idx]
    child->keys[order-1] = keys[idx];

    // Copying the keys from pointerToChild[idx+1] to pointerToChild[idx] at the end
    for (int i=0; i<sibling->numberOfKeys; ++i)
        child->keys[i+order] = sibling->keys[i];

    // Copying the child pointers from pointerToChild[idx+1] to pointerToChild[idx]
    if (!child->isLeaf)
    {
        for(int i=0; i<=sibling->numberOfKeys; ++i)
            child->pointerToChild[i+order] = sibling->pointerToChild[i];
    }

    // Moving all keys after idx in the current node one step before -
    // to fill the gap created by moving keys[idx] to pointerToChild[idx]
    for (int i=idx+1; i<numberOfKeys; ++i)
        keys[i-1] = keys[i];

    // Moving the child pointers after (idx+1) in the current node one
    // step before
    for (int i=idx+2; i<=numberOfKeys; ++i)
        pointerToChild[i-1] = pointerToChild[i];

    // Updating the key count of child and the current node
    child->numberOfKeys += sibling->numberOfKeys+1;
    numberOfKeys--;

    // Freeing the memory occupied by sibling
    delete(sibling);
    return;
}

//////////
void BTreeNode::splitChild(int indexOfY, BTreeNode *y)
{
    BTreeNode *newNode = new BTreeNode(y->order);
    newNode->isLeaf = y->isLeaf;
    newNode->numberOfKeys = (y->order / 2) - 1;

    for (int j = 0; j < (y->order / 2)-1; j++)
        newNode->keys[j] = y->keys[j+(y->order / 2)];

    if (!y->isLeaf)
    {
        for (int j = 0; j < (y->order / 2); j++)
            newNode->pointerToChild[j] = y->pointerToChild[j+(y->order / 2)];
    }
    y->numberOfKeys = (y->order / 2) - 1;

    for (int j = numberOfKeys; j >= indexOfY+1; j--)
        pointerToChild[j+1] = pointerToChild[j];

    pointerToChild[indexOfY+1] = newNode;

    for (int j = numberOfKeys-1; j >= indexOfY; j--)
        keys[j+1] = keys[j];

    keys[indexOfY] = y->keys[(y->order / 2)-1];

    numberOfKeys++;
}

void BTreeNode::insertNonFull(int data)
{
    int i = numberOfKeys-1;

    if (isLeaf == true)
    {
        while (i >= 0 && keys[i] > data)
        {
            keys[i+1] = keys[i];
            i--;
        }

        keys[i+1] = data;
        numberOfKeys = numberOfKeys+1;
    }
    else
    {
        while (i >= 0 && keys[i] > data)
            i--;

        if (pointerToChild[i+1]->numberOfKeys == order-1)
        {
            splitChild(i+1, pointerToChild[i+1]);

            if (keys[i+1] < data)
                i++;
        }
        pointerToChild[i+1]->insertNonFull(data);
    }
}

void insert(int data) {

    if (root == nullptr) {
        root = new BTreeNode(Const_order);
        root->keys[0]= data;
        root->numberOfKeys= 1;
    }
    else {
        if (root->numberOfKeys==root->order-1) { 
            BTreeNode *newRoot = new BTreeNode(root->order);

            newRoot->pointerToChild[0] = root;
            newRoot->isLeaf = false;

            newRoot->splitChild(0, root);

            int i = 0;
            if (newRoot->keys[0] < data)
                i++;
            newRoot->pointerToChild[i]->insertNonFull(data);

            root = newRoot;
        }
        else
            root->insertNonFull(data);
    }
}

void BTreeNode::traverse(int depth) {
    for (int i = 0; i < depth; i++) {
        cout << "          ";
    }

    for (int i = 0; i < numberOfKeys; i++) {
        cout << keys[i] << " ";
    }
    cout << endl;

    for (int i = 0; i <= numberOfKeys; i++) {
        if (!isLeaf) {
            pointerToChild[i]->traverse(depth + 1);
        }
    }
}

BTreeNode *BTreeNode::search(int k)
{
    int i = 0;
    while (i < numberOfKeys && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (isLeaf == true)
        return NULL;

    return pointerToChild[i]->search(k);
}

void remove(int k)
{
    if (root == nullptr)
    {
        cout << "The tree is empty\n";
        return;
    }

    // Call the remove function for root
    root->remove(k);

    // If the root node has 0 keys, make its first child as the new root
    //  if it has a child, otherwise set root as NULL
    if (root->numberOfKeys==0)
    {
        BTreeNode *tmp = root;
        if (root->isLeaf)
            root = NULL;
        else
            root = root->pointerToChild[0];

        // Free the old root
        delete tmp;
    }
    return;
}

int main()
{
    int arr[] = {8, 5, 7, 6, 1, 4, 2, 3, 9, 10};

    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
        insert(arr[i]);
    }

    cout << "\nTraversal of the constructed tree is: \n";
    root->traverse(0);

    remove(5);

    cout << "\nTraversal of the constructed tree is: \n";
    root->traverse(0);

    int k = 2;
    (root->search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";

    return 0;
}

