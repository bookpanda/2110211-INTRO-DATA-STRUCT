#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if(!n->left && !n->right) return 0;
  int ans = INT_MAX;
  if(n->left) {
    ans = std::min(ans, shallowest_leaf(n->left));
  }
  if(n->right) {
    ans = std::min(ans, shallowest_leaf(n->right));
  }
  return ans+1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
  if(mSize == 0) return -1;
  return shallowest_leaf(mRoot);
}


#endif
