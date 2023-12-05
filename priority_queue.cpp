#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to maintain the heap property by swapping elements
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    // Function to insert an element into the heap
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to get the maximum element (root of the max heap)
    int top() {
        if (!heap.empty()) {
            return heap[0];
        } else {
            cerr << "Heap is empty." << endl;
            return -1; // or throw an exception
        }
    }

    // Function to remove the maximum element from the heap
    void pop() {
        if (!heap.empty()) {
            heap[0] = heap.back();
            heap.pop_back();
            // Perform heapify to restore the heap property
            // (sink the root element to its correct position)
            int index = 0;
            while (true) {
                int leftChild = 2 * index + 1;
                int rightChild = 2 * index + 2;
                int largest = index;

                if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
                    largest = leftChild;
                }

                if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
                    largest = rightChild;
                }

                if (largest != index) {
                    swap(heap[index], heap[largest]);
                    index = largest;
                } 
                
                else {
                    break;
                }
            }
        } else {
            cerr << "Heap is empty. Cannot pop." << endl;
            // or throw an exception
        }
    }

    // Function to check if the heap is empty
    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap maxHeap;

    // Insert elements into the max heap
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.push(8);
    maxHeap.push(1);

    // Print the maximum element
    cout << "Max Element: " << maxHeap.top() << endl;

    // Remove the maximum element
    maxHeap.pop();

    // Print the maximum element after removal
    cout << "Max Element after pop: " << maxHeap.top() << endl;

    return 0;
}
