#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<unsigned char> preberiPodatke(const char* pot) {
    ifstream in(pot);
	
    if (!in) {
    cout << "Napaka pri odpiranju datoteke\n";
    return A;
    }

    vector<unsigned char> A;
    int temp;

    while (in >> temp) {
        A.push_back((unsigned char)temp);
    }

    in.close();
    return A;
}


void binarniRadixSort(vector<unsigned char>& A) {
    if (A.empty()) {
        return;
    }
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


int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "Napaka pri argumentih\n";
        return 1;
    }

    vector<unsigned char> A = preberiPodatke(argv[1]);

    binarniRadixSort(A);

    ofstream out("out.txt");

    if (A.empty()) {
        cout << "Ni podatkov za zapis\n";
    }

    for (int i = 0; i < A.size(); i++) {
        out << (int)A[i];
        if (i != A.size() - 1) {
            out << " ";
        }
    }

    out.close();

    return 0;
}
