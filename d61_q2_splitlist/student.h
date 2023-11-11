void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int sz = mSize/2;
    int pos = mSize-sz;
    iterator it = begin();
    for(int i=0;i<pos;i++) {
        it++;
    }

    node* n = it.ptr;
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    list1.mHeader->prev = n->prev;
    n->prev->next = list1.mHeader;

    n->prev = list2.mHeader->prev;
    list2.mHeader->prev->next = n;
    list2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = list2.mHeader;

    mSize = 0;
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    list1.mSize = pos;
    list2.mSize = sz;
    
    return;
};
