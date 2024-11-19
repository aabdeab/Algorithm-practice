#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        int operations = 0;
        if (b == 1) {
            operations = a;
        } else {
            if(a ==1){
                operations =1;
            }
            else{
            while (a > 0) {
                int power = static_cast<int>(log(a) / log(b));
                a -= static_cast<int>(pow(b, power));

                operations++;
            }
        }
        }

        cout << operations << endl;
    }

    return 0;
}
