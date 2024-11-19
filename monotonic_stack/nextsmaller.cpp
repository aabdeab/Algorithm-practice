// complexity O(n)
//espace O(n)


#include <iostream>
#include <stack>
#include <vector>

using namespace std ;

// function for finding next smaller element of every element in array 

vector<int> findNextSmallerElement(const std::vector<int>& arr) {

// declaring vector for storing next smaller element
	vector<int> result(arr.size(), -1); 

// declaring a stack
	stack<int> st; 

// iterating through array 
	for (int i = 0; i < arr.size(); ++i) {
	
	// checking for next smaller element
		while (!st.empty() && arr[i] < arr[st.top()]) {
		
		// pushing the next smaller element
			result[st.top()] = arr[i];
		
			st.pop();
		}

		// pushing elements of array in stack
		st.push(i);
	}

	return result;
}

// main function
int main() {

// array in which we have to find next smaller element
	vector<int> arr = {4, 8, 2, 1, 6, 10, 5};

// function calling
	vector<int> result = findNextSmallerElement(arr);

	
	cout << "Original Array is: ";
	for (int num : arr) {
		cout << num << " ";
	}

	cout << "\n Next Smaller Elements: ";
	for (int num : result) {
		cout << (num == -1 ? -1 : num) << " ";
	}

	return 0;
}
