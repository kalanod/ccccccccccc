//
// Created by yaidf on 14.10.2022.
//

#include "GraphDop.h"
#include <vector>
#include <string>

GraphDop::GraphDop() {
    string line;

    ifstream in("C:\\Users\\yaidf\\CLionProjects\\LAB2\\source.txt"); // окрываем файл для чтения
    if (in.is_open()) {
        while (getline(in, line)) {
            std::cout << line << std::endl;
            DataList.push_back(line);
            i++;
        }
    }
    in.close();     // закрываем файл
    visited.resize(i);


    // поток для записи
    out.open("C:\\Users\\yaidf\\CLionProjects\\LAB2\\graph.dot"); // окрываем файл для записи
}


void GraphDop::find() {
    out << "digraph G {" << endl;
    for (int it = 0; it < i; it++) {
        for (int it2 = 0; it2 < i; it2++) {
            if (DataList[it][it2] != '0' && visited[it2] != 1) {
                out << it + 1 << " -> " << it2 + 1 << endl;
            }
        }
        for (int h = 0; h < i; h++) visited[h] = 0;
    }
    out << "}" << endl;
}

void GraphDop::dfs(int a, int key, int v) {

    if (key) {
        out << v + 1 << " -> " << a + 1 << endl;
        visited[a] = 1;
    }

    for (int it = 0; it < i; it++) {
        if (DataList[a][it] != '0' && visited[it] != 1) {
            dfs(it, 1, a);
        }
    }
}