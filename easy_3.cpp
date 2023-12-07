#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; ++j) {
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
        }

        result.push_back(row);
    }

    return result;
}

void printPascalsTriangle(const vector<vector<int>>& triangle) {
   cout<<"[";
    for (const vector<int>& row : triangle) {
        cout << "[";
        for (int num : row) {
            cout << num << ",";
        }
        cout << "], ";
    }
    cout<<"]";
    cout << endl;
}

int main() {
    int numRows = 5;
    vector<vector<int>> pascalsTriangle = generate(numRows);

    cout << "Output: ";
    printPascalsTriangle(pascalsTriangle);

    return 0;
}
