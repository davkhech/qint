#include <bits/stdc++.h>

/*
    Node class represents our vertexes of graph.
    It has id as an identifier, and list of children nodes.
*/
class Node {
    unsigned id;
    std::vector<Node*> children;

public:
    Node (){}
    Node (unsigned id): id(id){}

    const unsigned get_id() {
        return id;
    }

    void insert_child(Node* child) {
        children.push_back(child);
    }

    const std::vector<Node*> get_children(){
        return children;
    }

    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << node.id;
        return os;
    }
};
