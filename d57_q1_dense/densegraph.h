#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <bits/stdc++.h>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        // Your code here
        for(int i=0;i<2;i++) {
            nodes.insert(0);
            al[i];
        }
    }

    DenseGraph(int n_in) {
        // Your code here
        for(int i=0;i<n_in;i++) {
            nodes.insert(i);
            al[i];
        }
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        nodes = G.nodes;
        al = G.al;
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
        if(al.find(a) == al.end()) return false;
        return al.at(a).count(b) > 0;
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph ans;
        ans.n = nodes.size();
        for(auto x: nodes) {
            ans.nodes.insert(x);
            ans.al[x];
        }
        for(auto x: al) {
            for(auto y: x.second) {
                ans.al.at(y).insert(x.first);
            }
        }
        return ans;
    }

protected:
    int n;
    // Your code here
    set<int> nodes;
    map<int, set<int> > al;

};
#endif // __DENSE_GRAPH_H__
