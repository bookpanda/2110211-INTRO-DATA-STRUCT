#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> ans;
  node* n = mRoot;
  node* n1 = NULL;
  node* n2 = NULL;
  mRoot = NULL;

  while(n) {
    if(mLess(n->data.first, val) ) {//old one
      if(!n1) {
        mRoot = n;
        mRoot->parent = NULL;
      } else if(mLess(n1->data.first, n->data.first)) { //n1 < n, n is right child
        n1->right = n;
        n->parent = n1;
      } //if now is n1's left child, it is already connected since we didnt cut it
      n1 = n;
      n = n->right;
      n1->right = NULL; //maintain left, but always sus right
    } else {//new one
      if(!n2) {
        ans.mRoot = n;
        ans.mRoot->parent = NULL;
      } else if(mLess(n->data.first, n2->data.first)) {// n < n2, n is left child
        n2->left = n;
        n->parent = n2;
      }
      n2 = n;
      n = n->left;
      n2->left = NULL;
    }
  }
  return ans;
}

#endif
