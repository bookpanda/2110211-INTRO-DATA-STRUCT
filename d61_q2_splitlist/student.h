void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    size_t sz = mSize/2;
    size_t pos1 = mSize-sz;
    iterator it = begin();
        
    for(int i=0;i<pos1;i++) it++;
    node* p = it.ptr;

    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    list1.mHeader->prev = p->prev;
    p->prev->next = list1.mHeader;
    
    p->prev = list2.mHeader->prev;
    list2.mHeader->prev->next = p;
    list2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = list2.mHeader;

    mSize = 0;
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    list1.mSize = pos1;
    list2.mSize = sz;

    return;
};
