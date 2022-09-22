#pragma once
#include <vector>

class UnionFind
{
public:

    UnionFind(std::vector<int> arrayWay);

    bool Connected();

private:

    void Union(int p, int q);

    int Root(int i);

    std::vector<int> id = {};
};
