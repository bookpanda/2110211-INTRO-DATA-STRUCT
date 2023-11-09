#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* now = mRoot;
  node* n1 = NULL;
  mRoot = NULL;
  node* n2 = NULL;
  result.mRoot = NULL;

  while(now != NULL) {
    if(mLess(now->data.first, val)) {//old tree
      if(n1 == NULL) {
        mRoot = now;
        mRoot->parent = NULL;
      } else if(mLess(n1->data.first, now->data.first)) {
        n1->right = now;
        now->parent = n1;
      }
      //  else { //still why attach left
      //   n1->left = now;
      //   now->parent = n1;
      // }

      n1 = now;
      now = now->right;
      n1->right = NULL;
    } else { //new tree
      if(n2 == NULL) {
        result.mRoot = now;
        result.mRoot->parent = NULL;
      } else if(mLess(now->data.first, n2->data.first)) {
        n2->left = now;
        now->parent = n2;
      }
      //  else { //still why attach right
      //   n2->right = now;
      //   now->parent = n2;
      // }

      n2 = now; //move to now
      now = now->left;
      n2->left = NULL; //cut left tree of now n2
    }
  } 

  return result;
}

#endif
