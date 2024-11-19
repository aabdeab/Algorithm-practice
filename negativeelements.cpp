// C++ program for the above approach
#include<bits/stdc++.h>
using namespace std;

// Function to count the number of
// negative elements in every window
// of size K
void countNegative(vector<int> arr, int k)
{
	
	// Initialize the window pointers
	int i = 0;
	int j = 0;

	// Store the count of negative numbers
	int count = 0;
	int n = arr.size();

	// Traverse the array, arr[]
	while (j < n) 
	{
		
		// Increase the count
		// if element is less than 0
		if (arr[j] < 0) 
		{
			count++;
		}

		// If size of the window equal to k
		if (j - i + 1 == k) 
		{
			cout << count << " ";

			// If the first element of
			// the window is less than 0,
			// decrement count by 1
			if (arr[i] < 0) 
			{
				count--;
			}
			i++;
		}
		j++;
	}
}

// Driver Code
int main()
{
	
	// Given Input
	vector<int> arr{ -1, 2, -2, 3, 5, -7, -5 };
	int k = 3;

	// Function Call
	countNegative(arr, k);
}
	
// This code is contributed by bgangwar59
