#pragma once
#include <bits/stdc++.h>

/**
    Node class represents our vertexes of graph.
    It has id as an identifier, and list of children nodes.
**/
class Node {

public:
    Node (): id(0){}
    Node (unsigned id): id(id){}
    Node (unsigned id, const std::vector<Node*>& children): id(id), children(children){}

    const unsigned get_id() {
        return id;
    }

    void insert_child(Node* child) {
        children.push_back(child);
    }

    const std::vector<Node*> get_children() {
        return children;
    }

    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << node.id;
        return os;
    }

private:
    std::vector<Node*> children;
    unsigned id;
};
