#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<unsigned char> preberiPodatke(const char* pot) {
    ifstream in(pot);
    vector<unsigned char> A;
    int temp;

    while (in >> temp) {
        A.push_back((unsigned char)temp);
    }

    in.close();
    return A;
}


void binarniRadixSort(vector<unsigned char>& A) {

    int n = A.size();

    vector<unsigned char> B(n);
    vector<int> D(n);
    int C[2];

    for (int k = 0; k < 8; k++) {

        for (int i = 0; i < n; i++) {
            D[i] = (A[i] >> k) & 1;
        }

        C[0] = 0;
        C[1] = 0;

        for (int i = 0; i < n; i++) {
            C[D[i]]++;
        }

        C[1] = C[1] + C[0];

        for (int i = n - 1; i >= 0; i--) {
            B[C[D[i]] - 1] = A[i];
            C[D[i]]--;
        }

        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }
    }
}

int main() {
    cout << "Test" << endl;
    return 0;
}
