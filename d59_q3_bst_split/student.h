#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* tmp = mRoot;
  while(tmp != NULL) {
    if(tmp->data.first < val) {
      tmp = tmp->right;
    } else {
      if(tmp->parent!=NULL)
      tmp->parent->right = NULL;
      break;
    }
  }
  std::cout << "tmp: " << tmp->data.first << "\n";
  std::cout << "parent: " << tmp->parent->data.first << "\n";

  node* tmp2 = tmp;
  while(tmp2 != NULL) {
    if(tmp2->data.first >= val) {
      tmp2 = tmp2->left;
    } else {
      if(tmp2->parent!=NULL)
      tmp2->parent->left = NULL;
      tmp2->parent = tmp->parent;
      break;
    }
  }
  std::cout << "tmp2: " << tmp2->data.first << "\n";
  std::cout << "parent: " << tmp2->parent->data.first << "\n";

  result.mRoot = tmp;
  result.mRoot->parent = NULL;
  // result.mRoot->left = NULL;


  return result;
}

#endif
