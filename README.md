# qint

Given a directed acyclic graph, we need to group intependent vertices.
We can assume that it discribes some computation, and we need to find which parts we can do in parallel, and for which verticies we need to wait until its dependencies are resolved.

We also assume that weights of edgies is 1 i.e. every piece of computation takes a 1 unit of time to finish.

In order to solve this problem, we use the depth first search approach. We traverse from the root node and find the maximum number of steps needed to reach the given vertex.
For example, in this graph R --> v1 --> v2
                             \ v3 -----/
we reach to v2 both from v1 and v3, but its distance from root is 2.
So, after the traversal, we group by the vertices by the computed distance.

To run the tests - `make test`

The tests are written in tests.h, the cxxtest is our testing engine.
The description of vertices is in node.h. The solution is in solution.h and solution.cpp.

The source.cpp contains all the code in one file, and just prints the ansers to console.
