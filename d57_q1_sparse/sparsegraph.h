#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include<bits/stdc++.h>

using namespace std;

class SparseGraph{
public:
    SparseGraph() : SparseGraph(3) {
        // Your code here
    }

    SparseGraph(int n_in) : n(n_in), al(n_in) {
        // Your code here
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
        return al[a].count(b) > 0;
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph ans(n);
        for(int i=0;i<n;i++) {
            for(auto y: al[i]) {
                ans.al[y].insert(i);
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

