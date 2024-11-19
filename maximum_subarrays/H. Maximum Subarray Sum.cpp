#include <iostream>
#include <tuple>
#include <vector>
#include <climits>

using namespace std;

tuple<int, int, long long> find_maximum_crossing_subarray(vector<int>& arr, int min, int mid, int max) {
    long long left_sum = LLONG_MIN; // Use long long for large sums
    long long sum = 0;
    int max_left = mid;

    for (int i = mid; i >= min; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    long long right_sum = LLONG_MIN;
    sum = 0;
    int max_right = mid + 1;

    for (int i = mid + 1; i <= max; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    return make_tuple(max_left, max_right, left_sum + right_sum);
}

tuple<int, int, long long> Find_maximum_subarray(vector<int>& arr, int min, int max) {
    if (min == max) {
        return make_tuple(min, max, arr[min]);
    } else {
        int mid = (min + max) / 2;
        int min_left, max_left;
        long long sum_left;
        int min_right, max_right;
        long long sum_right;
        int min_cross, max_cross;
        long long sum_cross;

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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto result = Find_maximum_subarray(arr, 0, arr.size() - 1);
    cout << get<2>(result) << endl;

    return 0;
}
