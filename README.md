# qint

Given a directed acyclic graph, we need to group independent vertices.
We can assume that it describes some computation, and we need to find which parts we can do in parallel, and for which verticies we need to wait until its dependencies are resolved.

We also assume that weights of edges is 1 i.e. every piece of computation takes a 1 unit of time to finish.

In order to solve this problem, we use the depth first search approach. We traverse from the root node and find the maximum number of steps needed to reach the given vertex.
For example, in this graph 

                        R --> v1 --> v2
                          \ v3 -----/
we reach to v2 both from v1 and v3, but its distance from root is 2.
So, after the traversal, we group by the vertices by the computed distance.

To run the tests - `make test`

The tests are written in tests.h, the cxxtest is our testing engine.
The description of vertices is in node.h. The solution is in solution.h and solution.cpp.

Additionally we have demo.cpp, which allows us to find groups of vertices for DAGs provided from console.
Run `make` and `./runner`.
At first provide the number of vertices and number of edges, then provide pair of numbers `i, j` which means that vertex `j` depends from vertex `i`. Afterwards it will print the group number and vertices in that group.
