#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelfN(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    int leftProduct = 1;
    int rightProduct = 1;

    for (int i = 0; i < n; ++i) {
        result[i] *= leftProduct;
        leftProduct *= nums[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}

int main() {
    vector<int> nums; 
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    vector<int> result = productExceptSelfN(nums);

    cout << "Result: ";
    for(int i = 0;i<nums.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
