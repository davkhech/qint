#include <bits/stdc++.h>

using namespace std;


/*
    Node class represents our vertexes of graph.
    It has id as an identifier, and list of children nodes.
*/
class Node {
    unsigned id;
    vector<Node*> children;

public:
    Node (){}
    Node (unsigned id): id(id) {}

    const unsigned get_id() {
        return id;
    }

    void insert_child(Node* child) {
        children.push_back(child);
    }

    const vector<Node*> get_children(){
        return children;
    }

    friend ostream& operator<<(ostream& os, const Node& node) {
        os << node.id;
        return os;
    }
};

/*
    Performs a depth first search and keeps maximum distance of vertexes from root.
*/
void dfs(Node* root, unordered_map<Node*, int>& ordering){
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
void find_independent_groups(Node* root, vector<vector<Node*>>& groups){
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

void print_groups(const vector<vector<Node*>>& groups) {
    for (int i = 0; i < groups.size(); ++i) {
        cout << i << " -> ";
        for (auto& v: groups[i]) {
            cout << *v << " ";
        }
        cout << endl;
    }
}

void test1() {
    vector<vector<Node*>> groups;

    Node* root = new Node();
    Node* v1 = new Node(1);
    Node* v2 = new Node(2);
    Node* v3 = new Node(3);
    Node* v4 = new Node(4);
    Node* v5 = new Node(5);
    root -> insert_child(v1);
    root -> insert_child(v2);
    v1 -> insert_child(v3);
    v1 -> insert_child(v4);
    v2 -> insert_child(v4);
    v2 -> insert_child(v5);
    v4 -> insert_child(v3);
    v4 -> insert_child(v5);

    find_independent_groups(root, groups);
    print_groups(groups);
}

void test2() {
    vector<vector<Node*>> groups;

    Node* root = new Node();
    Node* v1 = new Node(1);
    Node* v2 = new Node(2);
    Node* v3 = new Node(3);
    Node* v4 = new Node(4);
    root -> insert_child(v1);
    root -> insert_child(v2);
    root -> insert_child(v3);
    root -> insert_child(v4);
    v1 -> insert_child(v3);
    v2 -> insert_child(v3);
    v2 -> insert_child(v4);
    v3 -> insert_child(v4);

    find_independent_groups(root, groups);
    print_groups(groups);
}

void test3() {
    vector<vector<Node*>> groups;

    Node* root = new Node();
    Node* v1 = new Node(1);
    Node* v2 = new Node(2);
    Node* v3 = new Node(3);
    Node* v4 = new Node(4);
    Node* v5 = new Node(5);
    Node* v6 = new Node(6);
    root -> insert_child(v1);
    root -> insert_child(v2);
    root -> insert_child(v3);
    root -> insert_child(v4);
    v2 -> insert_child(v5);
    v2 -> insert_child(v3);
    v3 -> insert_child(v6);
    v4 -> insert_child(v3);

    find_independent_groups(root, groups);
    print_groups(groups);
}

void test4() {
    vector<vector<Node*>> groups;

    Node* root = new Node();
    Node* v1 = new Node(1);
    Node* v2 = new Node(2);
    Node* v3 = new Node(3);
    Node* v4 = new Node(4);
    Node* v5 = new Node(5);
    Node* v6 = new Node(6);
    root -> insert_child(v1);
    root -> insert_child(v2);
    v1 -> insert_child(v3);
    v3 -> insert_child(v4);
    v3 -> insert_child(v6);
    v2 -> insert_child(v5);
    v2 -> insert_child(v4);
    v4 -> insert_child(v6);
    v5 -> insert_child(v6);

    find_independent_groups(root, groups);
    print_groups(groups);
}

int main() {
    test1();
    test2();
    test3();
    test4();

    return 0;
}
