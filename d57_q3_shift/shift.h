void shift(int k) {
	// TODO: Add your code here
	int sz = mSize;
	k = k % sz;
	if(k<0) k = (k+sz) % sz;

	// if(k==0) return;

	node* n = mHeader;
	for(int i=0;i<=k;i++) n = n->next;
	//n = new first node



	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;
	mHeader->prev = n->prev;
	n->prev->next = mHeader;

	n->prev = mHeader;
	mHeader->next = n;
}
