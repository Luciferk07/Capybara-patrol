#include "testlib.h"
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
 
void shuffle_with_rnd(vector<int>& v) {
    for (int i = (int)v.size() - 1; i > 0; i--) {
        int j = rnd.next(0, i);
        swap(v[i], v[j]);
    }
}
 
void generateTest(int n, int m, int c) {
    vector<string> grid(n, string(m, '.'));
    vector<int> positions(n * m);
    iota(positions.begin(), positions.end(), 0);
    shuffle_with_rnd(positions);
 
    for (int i = 0; i < min(c, n * m); i++) {
        int pos = positions[i];
        grid[pos / m][pos % m] = 'C';
    }
 
    cout << n << " " << m << "\n";
    for (const string& row : grid) {
        cout << row << "\n";
    }
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int t = atoi(argv[1]); // test index to decide which test to generate
 
    if (t == 1) generateTest(1, 1, 1);
    else if (t == 2) generateTest(1, 1000, 1);
    else if (t == 3) generateTest(1000, 1, 1);
    else if (t == 4) generateTest(1000, 1000, 1);
    else if (t == 5) generateTest(1000, 1000, 100000);
    else if (t == 6) generateTest(1000, 1000, 500000);
    else if (t == 7) generateTest(100, 100, 100);
    else if (t == 8) generateTest(200, 200, 1);
    else if (t == 9) generateTest(500, 500, 250000);
    else if (t == 10) generateTest(1000, 1000, 0);
    else {
        // Random cases
        int n = rnd.next(1, 1000);
        int m = rnd.next(1, 1000);
        int maxC = max(1, n * m - 1);
        int c;
        if (t < 30)
            c = rnd.next(1, max(1, n * m / 10));
        else if (t < 80)
            c = rnd.next(n * m / 10, n * m / 2);
        else
            c = rnd.next(n * m / 2, maxC);
        generateTest(n, m, c);
    }
 
    return 0;
}
