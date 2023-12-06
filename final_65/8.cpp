template <typename KeyT,typename MappedT,typename CompareT = std::less<KeyT> >
class map_avl {
    protected:
        node *mRoot; CompareT mLess; size_t mSize;
        class node {
            friend class map_bst; 
                protected: ValueT data; node *left; node *right; node *parent; int height; int count;
            }
    // มีฟังก์ชันอื่น ๆ ตามปรกติ แต่มิได้เขียนไว้เพื่อประหยัดพื้นที่
    public:
        // เติม code ตรงนี้
        void process(node* n, ValueT a, int total) {
            if(!n) return;
            if(mLess(n->data.first,a)) {
                total++;
            }
            process(n->left);
            process(n->right);
        }

        int countLessThan(ValueT a) {
            // เติม code ตรงนี้
            int total=0;
            process(mRoot, a, total);
            return total;
        }
}

// เติม code ตรงนี้
int countLessThan(node* r, ValueT a) {
if (!r) return 0;
if (r->height == 0) return (mLess(r->data,a) ? 1:0);
if (mLess(a, r->data)) return countLessThan(r->left, a);
int c = (r->left ? r->left->count : 0);
if (mLess(r->data, a)) {
c+=1 + countLessThan(r->right, a);
}
return c;
}
int countLessThan(ValueT a) {
// เติม code ตรงนี้
return countLessThan(mRoot, a);
}
