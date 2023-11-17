void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int sz = mSize/2;
    int pos = mSize-sz;
    iterator it = begin();
    for(int i=0;i<pos;i++) {
        it++;
    } 

    node* n = it.ptr;
    //back of old list1
    mHeader->next->prev = list1.mHeader->prev;
    list1.mHeader->prev->next = mHeader->next;
    //mHeader of list1
    n->prev->next = list1.mHeader;
    list1.mHeader->prev = n->prev;

    //back of old list2
    n->prev = list2.mHeader->prev;
    list2.mHeader->prev->next = n;
    //mHeader of list2
    mHeader->prev->next = list2.mHeader;
    list2.mHeader->prev = mHeader->prev;

    list1.mSize = pos;
    list2.mSize = sz;
    mSize = 0;
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    return;  
};
