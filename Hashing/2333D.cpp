#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int taille;
        cin >> taille; // Read size of the array
        vector<int> vect(taille);
        for (int i = 0; i < taille; i++) {
            cin >> vect[i];
        }

        unordered_map<int, int> prefix_sum_index; // Track the last index of prefix sums
        int sum = 0;
        int nbr = 0; // Count of beautiful segments
        int last_end_index = -1; // To track the end index of the last beautiful segment

        for (int i = 0; i < taille; i++) {
            sum += vect[i];

            // Check if the current prefix sum is zero
            if (sum == 0) {
                nbr++;
                last_end_index = i; // Update the end index of the last beautiful segment
                sum = 0; 
                prefix_sum_index.clear(); 
            } else {
                if (prefix_sum_index.find(sum) != prefix_sum_index.end()) {
                    int previous_index = prefix_sum_index[sum];
                    if (previous_index >= last_end_index) {
                        nbr++;
                        last_end_index = i; 
                        sum = 0; 
                        prefix_sum_index.clear(); 
                    }
                }
            }

            prefix_sum_index[sum] = i;
        }

        cout << nbr << endl; 
    }
    return 0;
}
