void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int st2 = mSize/2;
    if(mSize % 2 == 1) st2++;

    node* n2 = mHeader;
    for(int i=0;i<=st2;i++) n2 = n2->next;

    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;

    n2->prev->next = list1.mHeader;
    list1.mHeader->prev = n2->prev;

    list2.mHeader->prev->next = n2;
    n2->prev = list2.mHeader->prev;

    list2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = list2.mHeader;

    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    list1.mSize = mSize % 2 == 1 ? (mSize/2)+1 : mSize/2;
    list2.mSize = mSize - list1.mSize;
    mSize = 0;
};
