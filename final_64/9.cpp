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
            // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ ยกเว้น insert, push_back, push_front
            // ห้ามเพิ่มฟังก์ชัน หรือ ข้อมูลอื่น ใดในคลาสนี้ (รมถึงใน inner class ด้วย)
        public:
            iterator push(T &data) {
                // your code here
                if(mSize == 0) {
                    node* n = new node(data, mHeader, mHeader);
                    mHeader->next = n;
                    mHeader->prev = n;
                    mSize++;
                    return iterator(n);
                }
                if(data < mHeader->next->data) {
                    node* n = new node(data, mHeader, mHeader->next);
                    mHeader->next->prev = n;
                    mHeader->next = n;
                    mSize++;
                    return iterator(n);
                }
                
                node* tmp = mHeader;
                for(int i=0;i<mSize;i++) {
                    tmp = tmp->next;
                    if(data >= tmp->data) {
                        node* n = new node(data, tmp->prev, tmp->next);
                        tmp->next->prev = n;
                        tmp->prev->next = n;
                        mSize++;
                        return iterator(n);
                    }
                }  
            }
    }
};