#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelfN2(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                result[i] *= nums[j];
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    vector<int> result = productExceptSelfN2(nums);
    cout << "Result: ";
    for(int i = 0;i<nums.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
