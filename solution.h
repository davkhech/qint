#pragma once
#include <bits/stdc++.h>
#include "node.h"

/**
    Finds indepentent groups in a DAG.
    It calculates the distances from root node and groups by the distances.
**/
void find_independent_groups(Node* root, std::vector<std::vector<Node*>>& groups);
