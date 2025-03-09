#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int b_val;
        cin >> b_val;
        
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        
        vector<int> flipped(n);
        for (int i = 0; i < n; ++i) {
            flipped[i] = b_val - a[i];
        }
        
        bool prev_x = true, prev_y = true;
        for (int i = 1; i < n; ++i) {
            bool curr_x = false, curr_y = false;
            int x_prev = a[i-1], y_prev = flipped[i-1];
            int x_curr = a[i], y_curr = flipped[i];
            
            if (prev_x) {
                if (x_curr >= x_prev) curr_x = true;
                if (y_curr >= x_prev) curr_y = true;
            }
            if (prev_y) {
                if (x_curr >= y_prev) curr_x = true;
                if (y_curr >= y_prev) curr_y = true;
            }
            
            prev_x = curr_x;
            prev_y = curr_y;
            
            if (!prev_x && !prev_y) break;
        }
        
        if (prev_x || prev_y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}