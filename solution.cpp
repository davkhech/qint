#include "solution.h"

#include <algorithm>
#include <stack>
#include <unordered_map>


/**
    Helper function that performs a depth first search and keeps maximum distances of vertexes from root.
**/
void dfs(Node* root, std::unordered_map<Node*, int>& ordering){
    Node* current_node;
    std::stack<Node*> s;

    ordering[root] = 0;
    s.push(root);

    while (!s.empty()) {
        current_node = s.top();
        s.pop();
        int next_order = ordering[current_node] + 1;

        for (auto& child: current_node -> get_children()) {
            s.push(child);

            if (ordering.find(child) == ordering.end()) {
                ordering[child] = next_order;
            }
            ordering[child] = std::max(next_order, ordering[child]);
        }
    }
}


void find_independent_groups(Node* root, std::vector<std::vector<Node*>>& groups){
    std::unordered_map<Node*, int> ordering;
    dfs(root, ordering);

    auto max_value = std::max_element(
        ordering.begin(), ordering.end(), 
        [](const std::pair<Node*, int>& p1, const std::pair<Node*, int>& p2) { 
            return p1.second < p2.second; 
        });

    groups.resize((max_value -> second) + 1);

    for (auto& entry: ordering) {
        groups[entry.second].push_back(entry.first);
    }
    std::reverse(groups.begin(), groups.end());
}
