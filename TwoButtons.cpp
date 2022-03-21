#include <iostream>
using namespace std;

int main () {
    int n;
    int m;
    int counter = 0;
    cin >> n;
    cin >> m;
    while (n != m) {
        if (m > n) {
            if (m % 2 == 0) {
                m = m/2;
                counter++;
            } else {
                m++;
                counter++;
            }
        } else if (n > m) {
            m++;
            counter++;
        }
    }
    cout << counter;
    return 0;
}