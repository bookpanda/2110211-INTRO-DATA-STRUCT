template <typename T,typename Comp = std::less<T> >
class priority_queue {
    protected:
        T *mData; size_t mCap; size_t mSize; Comp mLess; // เพิ่ม data member ได้
        // ให้ถือว่าฟังก์ชัน expand() ของคลาสนี้ทำงานได้ถูกต้องเสมอ นิสิตไม่จำเป็นต้องแก้ไขฟังก์ชันดังกล่าว
        void fixUp(size_t idx) {
            T tmp = mData[idx];
            while (idx > 0) {
                size_t p = (idx - 1) / 2;
                if ( mLess(tmp,mData[p]) ) break;
                mData[idx] = mData[p];
                idx = p;
            }
            mData[idx] = tmp;
        }
        void fixDown(size_t idx) {
            T tmp = mData[idx];
            size_t c;
            while ((c = 2 * idx + 1) < mSize) {
                if (c + 1 < mSize && mLess(mData[c],mData[c + 1]) ) c++;
                if ( mLess(mData[c],tmp) ) break;
                mData[idx] = mData[c];
                idx = c;
            }
            mData[idx] = tmp;
        }
    public:
        // ให้ถือว่า constructor, destructor, empty(), size() ของคลาสนี้ทำงานได้ถูกต้องเสมอ นิสิตไม่จำเป็นต้องแก้ไขฟังก์ชันดังกล่าว
        const T& top() { return mData[0]; }
        void push(const T& element) {
            if (mSize + 1 > mCap)
                expand(mCap * 2);
            mData[mSize] = element;
            mSize++;
            fixUp(mSize-1);
        }
        void pop() {
            mData[0] = mData[mSize-1];
            mSize--;
            fixDown(0);
        }
        // เติม code ตรงนี้ ถ้าที่ไม่พอให้เขียนไว้ด้านหลังของหน้า 9 เท่านั้น
        bool contain(const T& value) {
            return pos.find(value);
        }
        void change(const T& old_value, const T& new_value) {
            if (contain(old_value)) {
                size_t tmp = pos[old_value];
                mData[tmp] = new_value;
                pos.erase(old_value);
                pos[new_value] = tmp;
                fixUp(tmp);
                fixDown(tmp);
            }
        }
};