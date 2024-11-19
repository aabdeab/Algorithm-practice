#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Step 1: Calculate the initial sum
    long long initial_sum = 0;
    for (int i = 0; i < n; i++) {
        initial_sum += a[i] * b[i];
    }

    long long max_gain = 0;

    // Step 2: Iterate over all possible pairs (l, r)
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            long long original_contribution = 0;
            long long reversed_contribution = 0;

            for (int i = l; i <= r; i++) {
                original_contribution += a[i] * b[i];
                reversed_contribution += a[r - (i - l)] * b[i];
            }

            long long gain = reversed_contribution - original_contribution;
            max_gain = max(max_gain, gain);
        }
    }

    // Step 3: Calculate the maximum possible sum
    long long max_sum = initial_sum + max_gain;

    cout << max_sum << endl;

    return 0;
}
