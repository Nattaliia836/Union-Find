#include "UnionFind.h"

using namespace std;

    UnionFind::UnionFind(vector<int> arrayWay) {

        int N = (int)sqrt(arrayWay.size());

        for (int i = 0; i < arrayWay.size(); i++) {
            id.push_back(i);
        }

        for (int i = 0; i < arrayWay.size() - N; i++) {
            if (arrayWay[i] && arrayWay[i + N]) Union(i, i + N);
            if ((i + 1) % N != 0) {
                if (arrayWay[i] && arrayWay[i + 1]) Union(i, i + 1);
            }
        }

        for (int i = arrayWay.size() - N; i < arrayWay.size() - 1; i++) {
            if (arrayWay[i] && arrayWay[i + 1]) Union(i, i + 1);
        }
    }

    bool UnionFind::Connected()
    {
        return Root(0) == Root(id.size() - 1);
    }


    void UnionFind::Union(int p, int q)
    {
        int i = Root(p);
        int j = Root(q);
        id[i] = j;
    }

    int UnionFind::Root(int i)
    {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
