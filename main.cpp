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

int main() {
    cout << "Test" << endl;
    return 0;
}
