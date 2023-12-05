namespace CP {
    template <typename T>
    class list {
        protected:
        class node {
        public:
        T data; node *prev; node *next;
        // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
        };
        node *mHeader; size_t mSize;
        // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่
        public:
        T& operator[] (const int i) {
            // your code here
            node* n = mHeader;
            for(int j=0;j<=i;j++) {
                n = n->next;
            }
            return n->data;
        }
    }
};