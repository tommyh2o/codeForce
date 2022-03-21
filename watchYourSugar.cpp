#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int numChoc;
    int limit;
    cin >> numChoc;
    cin >> limit;
    int* sugarPerChoc = new int [numChoc];

    for (int i = 0; i < numChoc; ++i) {
        cin >> sugarPerChoc[i];
    }

    sort (sugarPerChoc, sugarPerChoc + numChoc);

    int answer = 0;
    int count = 0;

    while (count < limit) {
        count += sugarPerChoc[answer];
        if (count <= limit) {
            answer++;
        }
    }

    cout << answer;
}