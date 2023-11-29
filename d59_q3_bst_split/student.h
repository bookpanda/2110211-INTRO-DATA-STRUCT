#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> ans;

  node* now = mRoot;
  node* n1 = NULL;
  node* n2 = NULL;
  mRoot = NULL;
  ans.mRoot = NULL;
  while(now) {
    if(mLess(now->data.first, val)) { //old tree
      if(mRoot==NULL) {
        mRoot = now;
        mRoot->parent = NULL;
      } else if(mLess(n1->data.first, now->data.first)) { //n1<now, now is right child
        n1->right = now;
        now->parent = n1;
      }
      n1 = now;
      now = now->right;
      n1->right = NULL; //maintain left, but always sus right
    } else { //new tree
      if(ans.mRoot==NULL) {
        ans.mRoot = now;
        ans.mRoot->parent = NULL;
      } else if(mLess(now->data.first, n2->data.first)) { //now<n2, now is left child
        n2->left = now;
        now->parent = n2;
      }
      n2 = now;
      now = now->left;
      n2->left = NULL; //maintain right, but always sus left
    }
  }
  return ans;
}

#endif
