void shift(int k) {
	// TODO: Add your code here
	int n = mSize;
	k %= n;
	std::cout << "k = " << k << "\n";
	if(k==0) return;
	if(k < 0)
        k = (k+n) % n;
	node* p = mHeader;
	for(int i=0;i<k;i++) {
		p = p->next;
	}

	node* st = mHeader->next;
	node* ed = mHeader->prev;
	st->prev = ed;
	ed->next = st;
	mHeader->next = p->next;
	mHeader->prev = p;
	p->next->prev = mHeader;
	p->next = mHeader;

}
