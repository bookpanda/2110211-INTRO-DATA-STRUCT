#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	//swap not individual cells, but ranges
	if(a1 == b2) {
		std::swap(a1, b1);
		std::swap(a2, b2);
	}
	node* A1 = a1.ptr;
	node* A2 = a2.ptr;
	node* B1 = b1.ptr;
	node* B2 = b2.ptr;

	if(a2 == b1) {
		node* mid = A2;
		node* tmp = mid->prev;

		A1->prev->next = B1;
		B1->prev = A1->prev;

		B2->prev->next = A1;
		A1->prev = B2->prev;

		tmp->next = B2;
		B2->prev = tmp;
	} else {
		std::swap(A1->prev->next, B1->prev->next);
		std::swap(A1->prev, B1->prev);
		std::swap(A2->prev->next, B2->prev->next);
		std::swap(A2->prev, B2->prev);
	}
}

#endif
