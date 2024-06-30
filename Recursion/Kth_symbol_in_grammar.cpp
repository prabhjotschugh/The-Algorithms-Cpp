#include <iostream>
using namespace std;

int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    int parent = kthGrammar(N - 1, (K + 1) / 2);
    if (K % 2 == 1) {
        return parent;
    } else {
        return 1 - parent;
    }
}

int main() {
    int N = 4; // Example value for N
    int K = 5; // Example value for K
    cout << "The K-th symbol in grammar is: " << kthGrammar(N, K) << endl;
    return 0;
}
