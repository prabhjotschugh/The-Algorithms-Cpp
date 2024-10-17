#include <iostream>
#include <vector>
using namespace std;

// Helper function to simulate whether person a knows person b
bool knows(int a, int b, vector<vector<int>>& matrix) {
    return matrix[a][b] == 1;
}

// Function to find the celebrity
int findCelebrity(int n, vector<vector<int>>& matrix) {
    // Step 1: Find the potential celebrity
    int celebrity = 0;
    for (int i = 1; i < n; i++) {
        // If celebrity knows i, then celebrity can't be the celebrity, update celebrity to i
        if (knows(celebrity, i, matrix)) {
            celebrity = i;
        }
    }

    // Step 2: Verify if the candidate is a real celebrity
    for (int i = 0; i < n; i++) {
        if (i != celebrity) {
            // Celebrity should not know anyone and everyone should know the celebrity
            if (knows(celebrity, i, matrix) || !knows(i, celebrity, matrix)) {
                return -1; // No celebrity found
            }
        }
    }

    return celebrity;
}

int main() {
    // Example: Matrix where person i knows person j
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };
    int n = matrix.size();
    
    int celebrity = findCelebrity(n, matrix);
    
    if (celebrity == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person " << celebrity << endl;
    }

    return 0;
}
