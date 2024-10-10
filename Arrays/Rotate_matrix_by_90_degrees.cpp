#include <iostream>
#include <vector>
using namespace std;

// Function to rotate the matrix by 90 degrees clockwise
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Step 1: Transpose the matrix (swap matrix[i][j] with matrix[j][i])
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << "Matrix after 90-degree rotation:" << endl;
    printMatrix(matrix);

    return 0;
}
