#include <iostream>
#include <vector>
using namespace std;

// Global variables
int N; // Number of people
vector<vector<int>> statements; // statements[i][j] = 1 if i says j is truthful, -1 if i says j is a liar
vector<int> truth; // truth[i] = 1 if i is truthful, 0 if i is a liar

// Check if the current configuration of truthfulness is valid
bool isValidConfiguration() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (statements[i][j] != 0) {
                // If person i is truthful
                if (truth[i] == 1) {
                    if (statements[i][j] == 1 && truth[j] == 0) return false; // i says j is truthful but j is a liar
                    if (statements[i][j] == -1 && truth[j] == 1) return false; // i says j is a liar but j is truthful
                }
                // If person i is a liar
                else {
                    if (statements[i][j] == 1 && truth[j] == 1) return false; // i lies, says j is truthful, but j is truthful
                    if (statements[i][j] == -1 && truth[j] == 0) return false; // i lies, says j is a liar, but j is a liar
                }
            }
        }
    }
    return true;
}

// Backtracking to find a valid truth/lie assignment
bool solve(int person) {
    if (person == N) {
        return isValidConfiguration();
    }
    
    // Try assuming person is truthful
    truth[person] = 1;
    if (solve(person + 1)) return true;
    
    // Try assuming person is a liar
    truth[person] = 0;
    if (solve(person + 1)) return true;
    
    return false;
}

int main() {
    cout << "Enter the number of people: ";
    cin >> N;
    
    statements.resize(N, vector<int>(N));
    truth.resize(N);
    
    cout << "Enter the statements matrix (1: truthful, -1: liar, 0: no statement):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> statements[i][j];
        }
    }
    
    if (solve(0)) {
        cout << "A valid solution was found:\n";
        for (int i = 0; i < N; i++) {
            cout << "Person " << i + 1 << " is " << (truth[i] ? "Truthful" : "Liar") << endl;
        }
    } else {
        cout << "No valid solution exists.\n";
    }
    
    return 0;
}
