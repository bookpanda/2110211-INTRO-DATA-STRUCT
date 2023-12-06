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

            void recur(int st, int ed) {
                if(st > ed) return;
                int mid = (st+mid) / 2;
                insert(v[mid]);
                recur(st, mid-1);
                recur(mid+1, ed);
            }

        public:
            void make_balance() { // your code here
                vector<MappedT> v;
                inorder(mRoot, v);
                //v is sorted asc
                int sz = v.size();
                recur(0, sz-1);
            }
    };
}