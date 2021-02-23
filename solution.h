#include <bits/stdc++.h>

/*
    Node class represents our vertexes of graph.
    It has id as an identifier, and list of children nodes.
*/
class Solution {
    void dfs(Node* root, std::unordered_map<Node*, int>& ordering);

public:
    void find_independent_groups(Node* root, std::vector<std::vector<Node*>>& groups);
};


