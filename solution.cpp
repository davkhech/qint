#include "node.h"
#include "solution.h"
using namespace std;

/*
    Performs a depth first search and keeps maximum distance of vertexes from root.
*/
void Solution::dfs(Node* root, unordered_map<Node*, int>& ordering){
    Node* current_node;
    stack<Node*> s;

    ordering[root] = 0;
    s.push(root);

    while (s.size()) {
        current_node = s.top();
        s.pop();
        int next_order = ordering[current_node] + 1;

        for (auto& child: current_node -> get_children()) {
            s.push(child);

            if (ordering.find(child) == ordering.end()) {
                ordering[child] = next_order;
            }
            ordering[child] = max(next_order, ordering[child]);
        }
    }
}

/*
    Finds indepentent groups in a DAG.
    It calculates the distances from root node and groups by the distances.
*/
void Solution::find_independent_groups(Node* root, vector<vector<Node*>>& groups){
    unordered_map<Node*, int> ordering;
    dfs(root, ordering);

    auto max_value = max_element(ordering.begin(), ordering.end(), 
                                [](const pair<Node*, int>& p1, const pair<Node*, int>& p2) { 
                                    return p1.second < p2.second; 
                                });
    int n_groups = (max_value -> second) + 1;
    groups.resize(n_groups);

    for (auto& entry: ordering) {
        groups[entry.second].push_back(entry.first);
    }
    reverse(groups.begin(), groups.end());
}
