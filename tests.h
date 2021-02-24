#include <cxxtest/TestSuite.h>
#include "node.h"
#include "solution.h"

class Mytest: public CxxTest::TestSuite {

public:

    bool areEqual(const std::vector<std::vector<Node*>>& g, const std::vector<std::vector<unsigned>>& r) {

        if (g.size() != r.size()) {
            return false;
        }

        for (int i = 0; i < g.size(); ++i) {
            if (g[i].size() != r[i].size()) {
                return false;
            }

            for (int j = 0; j < g[i].size(); ++j) {
                if (g[i][j] -> get_id() != r[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    template<int T>
    Node* createTree(int n_nodes, const std::array<std::pair<unsigned, unsigned>, T>& connections) {

        std::vector<Node*> nodes;
        nodes.reserve(n_nodes);
        for (unsigned i = 0; i < n_nodes; ++i) {
            nodes.push_back(new Node(i));
        }

        for (auto& connection: connections) {
            nodes[connection.first] -> insert_child(nodes[connection.second]);
        }

        return nodes[0];
    }

    void testFirstDAG(){

        constexpr std::array<std::pair<unsigned, unsigned>, 8> connections {{
            {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {2, 5}, {4, 3}, {4, 5}
        }};
        std::vector<std::vector<unsigned>> result = {{3, 5}, {4}, {2, 1}, {0}};

        std::vector<std::vector<Node*>> groups;
        find_independent_groups(createTree<8>(6, connections), groups);

        TS_ASSERT(areEqual(groups, result));
    }

    void testSecondDAG(){

        constexpr std::array<std::pair<unsigned, unsigned>, 8> connections {{
            {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 3}, {2, 3}, {2, 4}, {3, 4}
        }};
        std::vector<std::vector<unsigned>> result = {{4}, {3}, {2, 1}, {0}};

        std::vector<std::vector<Node*>> groups;
        find_independent_groups(createTree<8>(5, connections), groups);

        TS_ASSERT(areEqual(groups, result));
    }

    void testThirdDAG(){

        constexpr std::array<std::pair<unsigned, unsigned>, 8> connections {{
            {0, 1}, {0, 2}, {0, 3}, {0, 4}, {2, 5}, {2, 3}, {3, 6}, {4, 3}
        }};
        std::vector<std::vector<unsigned>> result = {{6}, {5, 3}, {1, 2, 4}, {0}};

        std::vector<std::vector<Node*>> groups;
        find_independent_groups(createTree<8>(7, connections), groups);

        TS_ASSERT(areEqual(groups, result));
    }

    void testFourthDAG(){

        constexpr std::array<std::pair<unsigned, unsigned>, 9> connections {{
            {0, 1}, {0, 2}, {1, 3}, {3, 4}, {3, 6}, {2, 5}, {2, 4}, {4, 6}, {5, 6}
        }};
        std::vector<std::vector<unsigned>> result = {{6}, {4}, {3, 5}, {1, 2}, {0}};

        std::vector<std::vector<Node*>> groups;
        find_independent_groups(createTree<9>(7, connections), groups);

        TS_ASSERT(areEqual(groups, result));
    }

};
