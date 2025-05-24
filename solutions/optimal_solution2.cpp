#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    vector<string> grid(n);
    for (int i=0; i<n; i++) {
        cin>>grid[i];
    }
    
    // Find all rows and columns that have at least one capybara
    set<int> capybaraRows, capybaraCols;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j]=='C') {
                capybaraRows.insert(i);
                capybaraCols.insert(j);
            }
        }
    }
    
    int validPositions=0;
    
    // Check each empty cell
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j]=='.') {
                // Check if this position shares a row or column with any capybara
                if (capybaraRows.count(i) || capybaraCols.count(j)) {
                    validPositions++;
                }
            }
        }
    }
    
    cout<<validPositions<<"\n";
    
    return 0;
}
