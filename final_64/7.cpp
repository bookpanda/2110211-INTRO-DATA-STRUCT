namespace CP {
    template <typename T,typename Comp = std::less<T> >
    class priority_queue {
        protected:
            T *mData; size_t mCap; size_t mSize; Comp mLess;
            // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่, สามารถเพิ่มเติมฟังก์ชันอื่น ๆ ไว้ตรงนี้ได้
        public:
            bool swap_value(T &v1, T &v2) {
                // your code here
                int i1, i2;
                for(int i=0;i<mSize;i++) {
                    if(mData[i] == i1) i1 = i;
                    if(mData[i] == i2) i2 = i;
                }
                if(mData[(i1-1)/2] < mData[i2] || mData[(i1*2)+1] > mData[i2] || mData[(i1*2)+2] > mData[i2]) return false;
                if(mData[(i2-1)/2] < mData[i1] || mData[(i2*2)+1] > mData[i1] || mData[(i2*2)+2] > mData[i1]) return false;

                std::swap(mData[i1], mData[i2]);
                return true;
            }
    }
}