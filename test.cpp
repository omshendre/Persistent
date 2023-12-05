
#include <iostream>

using namespace std;

// function to sort the array
void printOrder(int arr[], int n, int k)
{
	// Sort first k elements in ascending order
	sort(arr, arr + k);

	// Sort remaining n-k elements in descending order
	sort(arr + k, arr + n, greater<int>());
}

// Driver code
int main()
{
	int arr[] = {4, 2, 7, 1, 9, 6, 3, 8, 5};
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);

	printOrder(arr, n, k);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
    cout<<endl;
	return 0;
}
