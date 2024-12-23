#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
    int *arr;
    int capacity;
    int current_size;

    public:

    MaxHeap(int totalSize) { 
        current_size = 0; 
        capacity = totalSize; 
        arr = new int[totalSize]; 
    }

    int getParent(int index) {
        return (index-1)/2;
    }

    int getLeftChild(int index) 
    { 
        return (2 * index + 1); 
    }

    int getRightChild(int index) 
    { 
        return (2 * index + 2); 
    }

    int getMaxElement() 
    { 
        return arr[0]; 
    } 

    int getCurrentSize() 
    { 
        return current_size; 
    }

    int peek() {
        if (current_size <= 0)
            return INT_MIN;

        return arr[0];
    }

    // mentain heap property of subtree
    // taking given index as root
    void Heapify(int index) {
        int leftChild = getLeftChild(index); 
        int rightChild = getRightChild(index); 
        int largest = index; 
        if (leftChild < current_size && arr[leftChild] > arr[index]) 
            largest = leftChild; 
        if (rightChild < current_size && arr[rightChild] > arr[largest]) 
            largest = rightChild; 
        if (largest != index) { 
            swap(arr[index], arr[largest]); 
            Heapify(largest); 
        }
    }

    // removes and return maximum 
    // element from the heap
    int extractMax() {
        // Checking whether the heap array 
        // is empty or not. 
        if (current_size <= 0) 
            return INT_MIN; 
        if (current_size == 1) { 
            current_size--; 
            return arr[0]; 
        } 
  
        // Storing the maximum element 
        // to remove it. 
        int root = arr[0]; 
        arr[0] = arr[current_size - 1]; 
        current_size--; 
  
        // To restore the property 
        // of the Max heap. 
        Heapify(0); 
  
        return root; 
    }

    // Increases the value of the key 
    // given by index to some new value. 
    // in min heap its decreaseKey
    void increaseKey(int index, int newVal) {
        arr[index] = newVal; 
        while (index != 0 && arr[getParent(index)] < arr[index]) { 
            swap(arr[index], arr[getParent(index)]); 
            index = getParent(index); 
        }
    }

    // Deletes a key at given index. 
    void deleteKey(int index) {
        // It increases the value of the key 
        // to infinity and then removes 
        // the maximum value. 
        increaseKey(index, INT_MAX); 
        extractMax(); 
    }
  
    // Inserts a new key in the Max Heap. 
    void insertKey(int data) {

        if (current_size == capacity) { 
            cout << "\nOverflow: Could not insertKey\n"; 
            return; 
        } 

        // The new key is initially 
        // inserted at the end. 
        current_size++; 
        int index = current_size - 1; 
        arr[index] = data;

        // this is heapifying
        while (index != 0 && arr[getParent(index)] < arr[index]) { 
            swap(arr[index], arr[getParent(index)]); 
            index = getParent(index); 
        }
    }
};

int main() 
{ 
    MaxHeap heap1(15); 
  
    heap1.insertKey(3); 
    heap1.insertKey(10); 
    heap1.insertKey(12); 
    heap1.insertKey(8); 
    heap1.insertKey(2); 
    heap1.insertKey(14); 
  
    cout << "The current size of the heap is "
         << heap1.getCurrentSize() << "\n"; 
  
    // Deleting key at index 2. 
    heap1.deleteKey(2); 
  
  
    // Inserting 2 new keys into the heap. 
    heap1.insertKey(15); 
    heap1.insertKey(5); 
    
    cout << "The current maximum element is " << heap1.extractMax() 
         << "\n"; 
  
    return 0; 
}