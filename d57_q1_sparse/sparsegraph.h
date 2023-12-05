#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include<bits/stdc++.h>
using namespace std;
// Your code here

using namespace std;

class SparseGraph{
public:
    SparseGraph() : SparseGraph(3) {
        // Your code here
    }

    SparseGraph(int n_in) {
        // Your code here
        n = n_in;
        al.resize(n);
    }

    SparseGraph(const SparseGraph& G) : n(G.n), al(G.al) {
        // Your code here
    }

    void AddEdge(int a, int b) {
        // Your code here
        al[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        al[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return al[a].find(b) != al[a].end();
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph ans(n);
        for(int i=0;i<n;i++) {
            for(auto x: al.at(i)) {
                ans.al[x].insert(i);
            }
        }
        return ans;
    }

protected:
    // Your code here
    int n;
    vector<set<int> > al;
};
#endif // __SPARSE_GRAPH_H__

