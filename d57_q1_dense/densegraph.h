#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
#include<set>
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
    }

    DenseGraph(const DenseGraph& G) : n(G.n), al(G.al) {
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

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph ans(n);
        for(int i=0;i<n;i++) {
            for(auto x: al[i]) {
                ans.al[x].insert(i);
            }
        }
        return ans;
    }

protected:
    int n;
    vector<set<int> > al;
    // Your code here

};
#endif // __DENSE_GRAPH_H__
