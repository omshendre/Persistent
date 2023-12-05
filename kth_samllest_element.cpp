#include <iostream>
#include <queue> 
#include <vector>

using namespace std;

int kthSmallestElement(vector<int>& nums, int k) {
    // Create a min-heap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    // Insert elements into the min-heap
    for (int i = 0;i<nums.size();i++) {
        minHeap.push(nums[i]);
    }

    // Extract the Kth smallest element
    for (int i = 0; i < k - 1; ++i) {
        minHeap.pop();
    }

    return minHeap.top();
}

int main() {
    vector<int> nums ; // Example array
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(5);
    int k = 3; // Kth value
    // 1 2 2 3 4 5
    int result = kthSmallestElement(nums, k);

    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
