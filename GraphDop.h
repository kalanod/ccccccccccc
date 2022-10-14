//
// Created by yaidf on 14.10.2022.
//

#ifndef LAB2_GRAPHDOP_H
#define LAB2_GRAPHDOP_H
#include "vector"
#include "string"
using namespace std;

class GraphDop {
private:
    int size;
    vector<int> visited;
    vector<string> DataList;
    int i = 0;
    ofstream out;
    int type = 0;
public:
    GraphDop();
    GraphDop(int);

    int hash(int value);


    bool insert(int value);

    int ssize();

    void find();
    void dfs(int, int, int);
    void erase(int value);

};


#endif //LAB2_GRAPHDOP_H
