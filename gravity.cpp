#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int columns;
    cin >> columns;
    int box [100];
    for (int i = 0; i < columns; i++) {
        cin >> box[i];
    }
    sort (box, box + columns);
    for (int i = 0; i < columns; i++) {
        printf("%d ", box[i]);
    }
}