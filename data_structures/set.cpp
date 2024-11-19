#include <iostream>
#include <set>
using namespace std;

int main() {
    // Define a set with custom comparator for descending order
    set<int> mySet;

    // Insert elements into the set
    mySet.insert(5);
    mySet.insert(10000);
    mySet.insert(10);
    mySet.insert(1);
    mySet.insert(7);
    

    // Display the sorted set
    cout << "Set elements in descending order: ";
    for (int element : mySet) {
        cout << element << " ";
    }
    return 0;
}
