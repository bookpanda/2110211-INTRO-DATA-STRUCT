#include<bits/stdc++.h>
using namespace std;

namespace CP {
    template <typename KeyT,typename MappedT, typename CompareT = std::less<KeyT> >
    class map_bst {
        protected:
            class node {
                protected:
                    ValueT data; node *left; node *right; node *parent;
            };
            // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่, สามารถเพิ่มเติมฟังก์ชันอื่น ๆ ไว้ตรงนี้ได้
            void inorder(node* n, vector<MappedT> &v) {
                if(!n) return;
                inorder(n->left);
                v.push_back(n->data.second);
                inorder(n->right);
            }

        public:
            void make_balance() { // your code here
                vector<MappedT> v;
                inorder(v);
                //v is sorted asc
                int sz = v.size();
                queue<pair<MappedT,int> > q;
                mRoot = NULL;
                mSize = 0;
                q.push({v[(sz+1)/2], sz/2});
                while(!q.empty()) {
                    int val = q.front().first;
                    int r = q.front().second;
                    q.pop();
                    insert(val);
                    if(r/2>0 && r+(r/2) < sz) q.push({v[r+(r/2)], r/2});
                    if(r/2>0 && r-(r/2) >= 0) q.push({v[r-(r/2)], r/2});
                }
            }
    };
}