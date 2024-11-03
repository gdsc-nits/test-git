

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count1543(const vector<int>& layer) {
    int count = 0;
    int len = layer.size();
    if(layer[len-1] == 1 && layer[0] == 5 && layer[1] == 4 && layer[2] == 3) count++;
    if(layer[len-2] == 1 && layer[len-1] == 5 && layer[0] == 4 && layer[1] == 3) count++;
    if(layer[len-3] == 1 && layer[len-2] == 5 && layer[len-1] == 4 && layer[0] == 3) count++;
    for (int i = 0; i <= len - 4; i++) {
        if (layer[i] == 1 && layer[i + 1] == 5 && layer[i + 2] == 4 && layer[i + 3] == 3) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < m; j++) {
                mat[i][j] = row[j] - '0';
            }
        }

        int totalCount = 0;
        int top = 0, left = 0, bottom = n - 1, right = m - 1;

        while (top <= bottom && left <= right) {
            vector<int> layer;

            for (int j = left; j <= right; j++) layer.push_back(mat[top][j]);
            for (int i = top + 1; i <= bottom; i++) layer.push_back(mat[i][right]);
            if (top < bottom) {
                for (int j = right - 1; j >= left; j--) layer.push_back(mat[bottom][j]);
            }
            if (left < right) {
                for (int i = bottom - 1; i > top; i--) layer.push_back(mat[i][left]);
            }
            cout<<endl;
            // for(auto i:layer) cout << i << " ";
            cout << endl;
            cout << endl;

            totalCount += count1543(layer);

            top++;
            left++;
            bottom--;
            right--;
        }

        cout << totalCount << endl;
    }

    return 0;
}
