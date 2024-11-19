#include <iostream>
#include <cmath>
using namespace std;

long long binary_search(long long left, long long right, long long c) {
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sqrtMid = static_cast<long long>(sqrt(mid)); // Calcul de la racine carrée
        long long difference = mid - sqrtMid;

        if (difference == c) {
            return mid;
        } else if (difference > c) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left; // Retourne left si pas trouvé exactement
}

int main() {
    long long  n;
    cin >> n; // Nombre de cas de test
    while (n--) {
        long long c;
        cin >> c; // Entrée du nombre c

        // Calcul des bornes selon les formules données
        long long left = static_cast<long long>(pow((1 + sqrt(4 * c - 3)) / 2, 2)) + 1;
        long long right = static_cast<long long>(pow((1 + sqrt(4 * c + 1)) / 2, 2));

        // Vérifier que les bornes sont valides
        if (left < 0) left = 0;
        if (right < left) right = left + 1;

        // Appel de la recherche binaire pour trouver le minimum d
        //long long result = binary_search(left, right, c);
        long long result;
        for(long long i=left;i<=right;i++){
            if(i-static_cast<long long>(floor(sqrt(i)))==c){
                result=i;
                break;
            }
        }
        cout << result << endl;
    }

    return 0;
}
