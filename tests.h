#include <cxxtest/TestSuite.h>
#include "node.h"
#include "solution.h"

class Mytest: public CxxTest::TestSuite {

public:
    void testFirstDAG(){
        std::vector<std::vector<Node*>> groups;

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

        TS_ASSERT_EQUALS(groups[0][0] -> get_id(), 3);
        TS_ASSERT_EQUALS(groups[0][1] -> get_id(), 5);
        TS_ASSERT_EQUALS(groups[1][0] -> get_id(), 4);
        TS_ASSERT_EQUALS(groups[2][0] -> get_id(), 2);
        TS_ASSERT_EQUALS(groups[2][1] -> get_id(), 1);
        TS_ASSERT_EQUALS(groups[3][0] -> get_id(), 0);
    }

    void testSecondDAG(){
        std::vector<std::vector<Node*>> groups;

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

        TS_ASSERT_EQUALS(groups[0][0] -> get_id(), 4);
        TS_ASSERT_EQUALS(groups[1][0] -> get_id(), 3);
        TS_ASSERT_EQUALS(groups[2][0] -> get_id(), 2);
        TS_ASSERT_EQUALS(groups[2][1] -> get_id(), 1);
        TS_ASSERT_EQUALS(groups[3][0] -> get_id(), 0);
    }

    void testThirdDAG(){
        std::vector<std::vector<Node*>> groups;

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

        TS_ASSERT_EQUALS(groups[0][0] -> get_id(), 6);
        TS_ASSERT_EQUALS(groups[1][0] -> get_id(), 5);
        TS_ASSERT_EQUALS(groups[1][1] -> get_id(), 3);
        TS_ASSERT_EQUALS(groups[2][0] -> get_id(), 1);
        TS_ASSERT_EQUALS(groups[2][1] -> get_id(), 2);
        TS_ASSERT_EQUALS(groups[2][2] -> get_id(), 4);
        TS_ASSERT_EQUALS(groups[3][0] -> get_id(), 0);
    }

    void testFourthDAG(){
        std::vector<std::vector<Node*>> groups;

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

        TS_ASSERT_EQUALS(groups[0][0] -> get_id(), 6);
        TS_ASSERT_EQUALS(groups[1][0] -> get_id(), 4);
        TS_ASSERT_EQUALS(groups[2][0] -> get_id(), 3);
        TS_ASSERT_EQUALS(groups[2][1] -> get_id(), 5);
        TS_ASSERT_EQUALS(groups[3][0] -> get_id(), 1);
        TS_ASSERT_EQUALS(groups[3][1] -> get_id(), 2);
        TS_ASSERT_EQUALS(groups[4][0] -> get_id(), 0);
    }

};
