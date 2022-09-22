#include "UnionFind.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void arrayCheck(const vector<int>& arrayWay) {

    if (arrayWay.size() < pow(2, 2) || arrayWay.size() > pow(50, 2)) {
        cout << "The size of the array does not match the condition." << endl;
    }

    if ((int)sqrt(arrayWay.size()) != sqrt(arrayWay.size())) {
        cout << "The array is not square." << endl;
    }

    for (const auto& element : arrayWay) {
        if (element != 1 && element != 0) {
            cout << "The array has an element that does not match the condition." << endl;
        }
    }
}

bool isWay(const vector<int>& arrayWay) {

    arrayCheck(arrayWay);

    UnionFind uf(arrayWay);
    if (uf.Connected()) {
        cout << "True" << endl;
        return true;
    }
    else {
        cout << "False" << endl;
        return false;
    }
}

int main()
{
    vector<int> arrayWay;
    int Exit = 0;
    while (true) {
        cout << "Enter the dimension of the matrix" << endl;
        int N = 0;
        cin >> N;
        int element = 0;
        for (int i = 0; i < N * N; ++i) {
            cin >> element;
            arrayWay.push_back(element);
        }

        isWay(arrayWay);
        cout << "If you want to exit press 1 or enter another number to repeat " << endl;
        cin >> Exit;
        if (Exit == 1) break;
    }
    
    
    return 0;
}
