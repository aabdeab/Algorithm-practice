#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> test = {1, 2, 5, 6, 8, 9, 10};
    int first = 0;
    int last = test.size() - 1;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (test[mid] == mid) {
            cout << mid << endl;
            return 0; 
        } else if (test[mid] > mid) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }

    cout << -1 << endl;
    return 0;
}
