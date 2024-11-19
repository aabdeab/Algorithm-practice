#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long long merge_inversions(vector<int>& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> A(n1 + 1), B(n2 + 1);

    for (int i = 0; i < n1; i++) {
        A[i] = arr[p + i];
    }
    for (int i = 0; i < n2; i++) {
        B[i] = arr[q + 1 + i];
    }

    A[n1] = numeric_limits<int>::max();
    B[n2] = numeric_limits<int>::max();

    int i = 0, j = 0;
    long long inversions = 0; // Changer à long long ici
    for (int k = p; k <= r; k++) {
        if (A[i] <= B[j]) {
            arr[k] = A[i];
            i++;
        } else {
            arr[k] = B[j];
            j++;
            inversions += n1 - i; // Inversions pour les éléments restants dans A
        }
    }

    return inversions;
}

long long merge_count(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        long long left = merge_count(arr, p, q);
        long long right = merge_count(arr, q + 1, r);
        long long inversions = merge_inversions(arr, p, q, r) + left + right;
        return inversions;
    }
    return 0; // Assurez-vous de retourner 0 si p >= r
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;
        vector<int> arr(m);

        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }

        auto first_zero_it = find(arr.begin(), arr.end(), 0);
        int first_zero = (first_zero_it != arr.end()) ? distance(arr.begin(), first_zero_it) : -1;

        auto last_one_it = find(arr.rbegin(), arr.rend(), 1);
        int last_one = (last_one_it != arr.rend()) ? distance(arr.begin(), last_one_it.base() - 1) : -1;

        // Copie des tableaux pour éviter de modifier le tableau original
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;

        // Modification des tableaux selon les indices trouvés
        if (first_zero >= 0) {
            arr1[first_zero] = 1; // Remplace le premier 0 par 1
        }
        if (last_one >= 0) {
            arr2[last_one] = 0; // Remplace le dernier 1 par 0
        }

        // Calcul des inversions
        long long inversions = max(
            merge_count(arr, 0, arr.size() - 1),
            max(
                merge_count(arr1, 0, arr1.size() - 1),
                merge_count(arr2, 0, arr2.size() - 1)
            )
        );

        cout << inversions << endl;
    }

    return 0;
}
