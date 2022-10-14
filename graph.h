//
// Created by yaidf on 11.10.2022.
//

#ifndef LAB2_GRAPH_H
#define LAB2_GRAPH_H
#include "vector"
#include "string"
using namespace std;

class graph {
private:
    int size;
    vector<int> visited;
    vector<string> DataList;
    int i = 0;
    ofstream out;
    int type = 0;
public:
    graph();
    graph(int);

    int hash(int value);


    bool insert(int value);

    int ssize();

    void find();
    void dfs(int, int);
    void erase(int value);

};


#endif //LAB2_GRAPH_H
