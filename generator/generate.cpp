#include "testlib.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
using namespace std;

void generateTest(int n, int m, int c) {
    vector<string> grid(n, string(m, '.'));
    vector<int> positions(n * m);
    iota(positions.begin(), positions.end(), 0);
    shuffle(positions.begin(), positions.end(), rnd);
    
    for (int i = 0; i < min(c, n*m); i++) {
        int pos = positions[i];
        grid[pos / m][pos % m] = 'C';
    }
    
    cout << n << " " << m << "\n";
    for (string& row : grid) {
        cout << row << "\n";
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int test_count = 100;
    
    // Edge cases (10 tests)
    generateTest(1, 1, 1);        // 1x1 with 1C (edge case)
    generateTest(1, 1000, 1);     // Thin horizontal grid
    generateTest(1000, 1, 1);     // Thin vertical grid
    
    generateTest(1000, 1000, 1);      // Sparse giant grid
    generateTest(1000, 1000, 100000); // Dense giant grid (10% filled)
    generateTest(1000, 1000, 500000); // Half-filled giant grid
    
    generateTest(100, 100, 100);       // Medium grid, moderate capybaras
    generateTest(200, 200, 1);         // Single capybara
    generateTest(500, 500, 250000);    // Dense capybaras (50%)
    generateTest(1000, 1000, 0);       // No capybaras (edge case)
    
    // Random cases (90 tests)
    for (int t = 10; t < test_count; t++) {
        int n = rnd.next(1, 1000);
        int m = rnd.next(1, 1000);
        int max_c = max(1, n*m - 1);
        int c;
        
        if (t < 30) 
            c = rnd.next(1, max(1, n*m / 10));      // Sparse
        else if (t < 80) 
            c = rnd.next(n*m / 10, n*m / 2);       // Medium density
        else 
            c = rnd.next(n*m / 2, max_c);           // Dense
        
        generateTest(n, m, c);
    }
    
    return 0;
}
