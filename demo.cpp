#include "node.h"
#include "solution.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * **/

int main() {
    int N, M;
    cout << "Enter number of verticies and edges\n";
    cin >> N >> M;

    vector<Node*> nodes;
    nodes.reserve(N);

    for (unsigned i = 0; i < N; ++i) {
        nodes.emplace_back(new Node(i));
    }

    int x, y;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        nodes[x] -> insert_child(nodes[y]);
    }

    vector<vector<Node*>> groups;
    find_independent_groups(nodes[0], groups);

    for (int i = 0; i < groups.size(); ++i) {
        cout << i << " -> ";
        for (auto& v: groups[i]) {
            cout << v -> get_id() << " ";
        }
        cout << endl;
    }

    return 0;
}