void shift(int k) {
	// TODO: Add your code here
	int m = mSize;
	k %= m;
	if(k<0) k = (k+m)%m;

	iterator it = begin();
	while(k--) it++;

	node* st = it.ptr;
	//connect last to first directly
	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;

	mHeader->prev = st->prev;
	st->prev->next = mHeader;

	st->prev = mHeader;
	mHeader->next = st;




}
