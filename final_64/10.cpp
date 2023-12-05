namespace CP {
    template <typename KeyT,
    typename MappedT,
    typename HasherT = std::hash<KeyT>,
    typename EqualT = std::equal_to<KeyT>,
    typename NextAddressT = LinearProbing >
    class unordered_map {
        protected:
            std::vector<BucketT> mBuckets;
            size_t mSize;
            HasherT mHasher;
            EqualT mEqual;
            float mMaxLoadFactor;
            size_t mUsed;
            NextAddressT mNextAddress;
            // มีฟังก์ชันและข้อมูลอื่น ๆ ตามปรกติ แต่มิได้แสดงไว้เพื่อประหยัดพื้นที่, สามารถเพิ่มเติมฟังก์ชันอื่น ๆ ไว้ตรงนี้ได้
        public:
            size_t get_prob_count(KeyT &k) {
                //your code here
                size_t homePos = hash_to_bucket(k);
                size_t pos = homePos;
                size_t col_count = 0;
                while (!mBuckets[pos].empty() && !mEqual(mBuckets[pos].value.first,k)) {
                    pos = mNextAddress(homePos,++col_count,bucket_count());
                }
                return col_count;
            }
    };
};