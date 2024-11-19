#include <iostream>
#include <tuple>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

// Function to find the maximum crossing subarray
tuple<int, int, int> find_maximum_crossing_subarray(vector<int>& arr, int min, int mid, int max) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;

    // Calculate left part
    for (int i = mid; i >= min; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid + 1;

    // Calculate right part
    for (int i = mid + 1; i <= max; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    return make_tuple(max_left, max_right, left_sum + right_sum);
}

// Recursive function to find the maximum subarray
tuple<int, int, int> Find_maximum_subarray(vector<int>& arr, int min, int max) {
    if (min == max) {
        // Base case: Only one element
        return make_tuple(min, max, arr[min]);
    } else {
        int mid = (min + max) / 2;
        int min_left, max_left, sum_left;
        int min_right, max_right, sum_right;
        int min_cross, max_cross, sum_cross;
        tie(min_left, max_left, sum_left) = Find_maximum_subarray(arr, min, mid);
        tie(min_right, max_right, sum_right) = Find_maximum_subarray(arr, mid + 1, max);
        tie(min_cross, max_cross, sum_cross) = find_maximum_crossing_subarray(arr, min, mid, max);
        if (sum_left >= sum_right && sum_left >= sum_cross) {
            return make_tuple(min_left, max_left, sum_left);
        } else if (sum_right >= sum_left && sum_right >= sum_cross) {
            return make_tuple(min_right, max_right, sum_right);
        } else {
            return make_tuple(min_cross, max_cross, sum_cross);
        }
    }
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Find the maximum subarray using the recursive function
    auto result = Find_maximum_subarray(arr, 0, arr.size() - 1);

    // Output the results
    cout << "Left index: " << get<0>(result) << endl;
    cout << "Right index: " << get<1>(result) << endl;
    cout << "Sum: " << get<2>(result) << endl;

    return 0;
}
