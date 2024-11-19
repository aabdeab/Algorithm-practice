#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    int n;
    cin >> n; // number of test cases
    while (n--) {
        int x, y, MEX = -1;
        cin >> y >> x; // y: size of array, x: the given number
        set<int> s;

        // Input the array elements into the set
        while (y--) {
            int a;
            cin >> a;
            s.insert(a);
        }

        // Case 1: If the minimum element is greater than 0, MEX is 0
        if (*s.begin() > 0) {
            MEX = 0;
        } else {
            // Find the first gap in the set
            auto it = s.begin();
            while (it != s.end()) {
                auto next_it = next(it);
                if (next_it == s.end() || *next_it - *it > 1) {
                    MEX = *it + 1;
                    break;
                }
                it = next_it;
            }
        }

        if (MEX == -1) {
            int last = *s.rbegin();
            int remainder = (last + 1) % x;
            bool found = false;
            for (int k = 0;; ++k) {
                int val = remainder + x * k;
                if (s.find(val) != s.end()) {
                    MEX = last + 1;
                    break;
                } else {
                    MEX = last + 2;
                    found = true;
                    break;
                }
            }
        }

        cout << MEX << "\n"; // Output the MEX
    }

    return 0;
}
