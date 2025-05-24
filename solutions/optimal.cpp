#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    
    vector<string> grid(n);
    vector<bool> hasCapybaraRow(n, false);
    vector<bool> hasCapybaraCol(m, false);
    
    for (int i=0; i<n; i++) {
        cin>>grid[i];
        for (int j=0; j<m; j++) {
            if (grid[i][j]=='C') {
                hasCapybaraRow[i] = true;
                hasCapybaraCol[j] = true;
            }
        }
    }
    
    int validPositions=0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j]=='.' &&(hasCapybaraRow[i] || hasCapybaraCol[j])) {
                validPositions++;
            }
        }
    }
    
    cout<<validPositions<<"\n";
    
    return 0;
}
