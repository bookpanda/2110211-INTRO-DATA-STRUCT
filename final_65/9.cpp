template <typename KeyT,
    typename MappedT,
    typename HasherT = std::hash<KeyT>,
    typename EqualT = std::equal_to<KeyT> >
class unordered_map {
    protected:
        typedef std::pair<KeyT,MappedT> ValueT;
        typedef std::vector<ValueT> BucketT;
        typedef typename BucketT::iterator ValueIterator;
        typedef typename std::vector<BucketT>::iterator BucketIterator;
        std::vector<BucketT> mBuckets;
        size_t mSize;
        HasherT mHasher;
        EqualT mEqual;
        float mMaxLoadFactor;
    public:
        typedef hashtable_iterator iterator;
        MappedT& operator[](const KeyT& key) {
            size_t bucketIdx = hash_to_bucket(key);
            // ValueIterator it = find_in_bucket(mBuckets[bucketIdx],key);
            ValueIterator it = mBuckets[bucketIdx].find(key);
            if (it == mBuckets[bucketIdx].end()) { // if not found, insert the new one
                // it = insert_to_bucket(std::make_pair(key, MappedT()),bucketIdx);
                it = mBuckets[bucketIdx].insert(std::make_pair(key, MappedT()));
            }
            return it->second;
        }
        std::pair<iterator,bool> insert(const ValueT& val) {
            std::pair<iterator,bool> result;
            size_t bucketIdx = hash_to_bucket(val.first);
            // ValueIterator it = find_in_bucket(mBuckets[bucketIdx], val.first);
            ValueIterator it = mBuckets[bucketIdx].find(val.first);
            result.second = false;
            if (it == mBuckets[bucketIdx].end()) {
                // it = insert_to_bucket(val, bucketIdx );
                it = mBuckets[bucketIdx].insert(val);
                result.second = true;
            }
            result.first = outside_iterator(mBuckets.begin()+bucketIdx,
            mBuckets.begin(),
            mBuckets.end(),
            it);
            return result;
        }
        size_t erase(const KeyT &key) {
            size_t bucketIdx = hash_to_bucket(key);
            // ValueIterator it = find_in_bucket(mBuckets[bucketIdx],key);
            ValueIterator it = mBuckets[bucketIdx].find(key);
            if (it == mBuckets[bucketIdx].end()) {
                return 0;
            } else {
                mBuckets[bucketIdx] .erase(it);
                mSize--;
            return 1; // erase 1 element
            }
        }
};