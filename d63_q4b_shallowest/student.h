#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  int a = 99999999;
  if(n->left==NULL && n->right==NULL) return 0;
  if(n!=NULL && n->left!=NULL) {
    a = std::min(a, 1+shallowest_leaf(n->left));
  }
  if(n!=NULL && n->right!=NULL) {
    a = std::min(a, 1+shallowest_leaf(n->right));
  }
  // std::cout << "\nn = " << n->data.first << "\n";
  return a;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
  if(mSize==0) return -1;
  if(mSize==1) return 0;
  return shallowest_leaf(mRoot);
}


#endif
