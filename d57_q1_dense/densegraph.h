#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <bits/stdc++.h>
using namespace std;
class DenseGraph{
public:
    DenseGraph() : DenseGraph(3) {
        // Your code here
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
        al.resize(n);
        for(int i=0;i<n;i++) {
            al[i].resize(n);
        }
    }

    DenseGraph(const DenseGraph& G) : n(G.n), al(G.al) {
        // Your code here
    }

    void AddEdge(int a, int b) {
        // Your code here
        al[a][b] = 1;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        al[a][b] = 0;
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return al[a][b];
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph ans(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans.al[j][i] = al[i][j];
            }
        }

        return ans;
    }

protected:
    int n;
    // Your code here
    vector<vector<int> > al;

};
#endif // __DENSE_GRAPH_H__
