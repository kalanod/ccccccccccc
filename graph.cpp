//
// Created by yaidf on 11.10.2022.
//

#include "graph.h"
#include <vector>
#include <string>

graph::graph() {
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
    out.open("C:\\Users\\yaidf\\CLionProjects\\LAB2\\res.txt"); // окрываем файл для записи
}


void graph::find() {
    for (int it = 0; it < i; it++) {

        dfs(it, 0);
        out << endl;
        for (int h = 0; h < i; h++) visited[h] = 0;
    }
}

void graph::dfs(int a, int key) {

    if (key) {
        out << a + 1 << " ";
        visited[a] = 1;
    }

    for (int it = 0; it < i; it++) {
        if (DataList[a][it] != '0' && visited[it] != 1) {
            dfs(it, 1);
        }
    }
}