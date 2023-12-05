namespace CP {
    template <typename KeyT,typename MappedT, typename CompareT = std::less<KeyT> >
    class map_bst {
        protected:
            class node { // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
            protected:
            ValueT data; node *left; node *right; node *parent;
            };
            // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่, สามารถเพิ่มเติมฟังก์ชันอื่น ๆ ไว้ตรงนี้ได้
            void process(node* n, int lvl, int &total) {
                if(!n) return;
                total += lvl;
                process(mRoot->left, lvl+1, total);
                process(mRoot->right, lvl+1, total);
            }
        public:
            size_t sum_node_depth() {
                // your code here
                int total = 0;
                process(mRoot, 0, total);
                return total;
            }
    };
}