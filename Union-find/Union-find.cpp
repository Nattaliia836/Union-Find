#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class UnionFind
{
public:

    UnionFind(vector<int> arrayWay) {
        
        int N = (int)sqrt(arrayWay.size());

        //Fill the vector so that each element contains the root itself
        //For example, the first element with ID 0 will have a value of root 0
        for (int i = 0; i < arrayWay.size(); i++) {     
            id.push_back(i);
        }
        
        /*
        Each element can be connected to the next in the array and to the element below it. 
        Next - will have an index of 1 more. The bottom will have an index of N more, where N is the volume of elements in the row
        The last element in the row should only connect to the bottom element 
        */
        for (int i = 0; i < arrayWay.size() - N; i++) {
            if (arrayWay[i] && arrayWay[i + N]) Union(i, i + N);
            if ((i + 1) % N != 0) {
                if (arrayWay[i] && arrayWay[i + 1]) Union(i, i + 1);
            }
        }

        //Each element in the bottom row can only be connected to the next elements
        for (int i = arrayWay.size() - N; i < arrayWay.size() - 1; i++) {
            if (arrayWay[i] && arrayWay[i + 1]) Union(i, i + 1);
        }
    }

    bool Connected()
    {
        return Root(0) == Root(id.size() - 1);
    }

private:

    void Union(int p, int q)
    {
        int i = Root(p);
        int j = Root(q);
        id[i] = j;
    }

    int Root(int i)
    {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    vector<int> id = {};    //It is a vector that will contain the root of each element 
};

void arrayCheck(const vector<int>& arrayWay) {

    //Check 1. Array size. It should be from 2x2 to 50x50 
    if (arrayWay.size() < pow(2, 2) || arrayWay.size() > pow(50, 2)) {                       
        throw invalid_argument("The size of the array does not match the condition.");
    }

    //Check 2. Dimension the array.The array must be square
    if ((int)sqrt(arrayWay.size()) != sqrt(arrayWay.size())) {
        throw invalid_argument("The array is not square.");
    }

    //Check 3. Array elements. All elements of the array must be either 0 or 1
    for (const auto& element : arrayWay) {
        if (element != 1 && element != 0) {
            throw invalid_argument("The array has an element that does not match the condition.");
        }
    }
}

bool isWay(const vector<int>& arrayWay) {

    //Check the correctness of the array 
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
    try {
        vector<int> arrayWay = {
                1, 0, 0, 0, 0,
                1, 1, 0, 0, 0,
                0, 1, 0, 0, 0,
                0, 1, 0, 0, 0,
                0, 1, 1, 1, 1
        };
        isWay(arrayWay);
    }
    catch(exception& ex) {
        cerr << "Exception happens: " << ex.what();
    }
    return 0;
}
