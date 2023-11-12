void shift(int k) {
	// TODO: Add your code here
	// std::cout << "k = " << k << "\n";
	int sz = mSize;
	k = k%sz;
	// std::cout << "k = " << k << "\n";
	if(k<0) k = (k+mSize)%mSize;

	iterator it = begin();
	for(int i=0;i<k;i++) {
		it++;
	}
	node* n = it.ptr;
	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;
	mHeader->prev = n->prev;
	n->prev->next = mHeader; 
	n->prev = mHeader;
	mHeader->next = n;


}
