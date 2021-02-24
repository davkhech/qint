#include "node.h"
#include "solution.h"

#include <iostream>
#include <vector>

/**
 * Demo program to see how vertices are grouped. Insert graph from console.
 * **/

int main() {
    std::cout << "Enter number of verticies and edges\n";

    int N, M;
    std::cin >> N >> M;

    std::vector<Node*> nodes;
    nodes.reserve(N);
    for (unsigned i = 0; i < N; ++i) {
        nodes.push_back(new Node(i));
    }

    std::cout << "Enter M pairs of numbers, to connect the vertices i and j\n";
    int x, y;
    for (int i = 0; i < M; ++i) {
        std::cin >> x >> y;
        nodes[x] -> insert_child(nodes[y]);
    }

    std::vector<std::vector<Node*>> groups;
    find_independent_groups(nodes[0], groups);

    std::cout << "Result:\n";
    for (int i = 0; i < groups.size(); ++i) {
        std::cout << i << " -> ";
        for (auto& v: groups[i]) {
            std::cout << v -> get_id() << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}