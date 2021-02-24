#pragma once
#include <vector>

/**
    Node class represents our vertices of graph.
    It has id as an identifier, and list of children nodes.
**/
class Node {

public:
    Node (): children()
           , id(0)
    {}

    Node (unsigned id): id(id)
    {}

    Node (unsigned id, const std::vector<Node*>& children): children(children)
                                                          , id(id)
    {}

    const unsigned get_id() const;

    void insert_child(Node* child);

    const std::vector<Node*> get_children() const;

private:
    std::vector<Node*> children;
    unsigned id;
};

inline const unsigned Node::get_id() const {
    return id;
}

inline void Node::insert_child(Node* child) {
    children.push_back(child);
}

inline const std::vector<Node*> Node::get_children() const {
    return children;
}
