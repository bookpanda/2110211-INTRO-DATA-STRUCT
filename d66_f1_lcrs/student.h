// You may include library here
void recur(node* n, int lvl, int &maxlvl) {
  if(!n) return;
  if(lvl > maxlvl) {
    maxlvl = lvl;
  }
  recur(n->left_child, lvl+1, maxlvl);
  recur(n->right_sibling, lvl, maxlvl);
}

int depth(node *n)
{
  // Write Code Here
  if(!n) return -1;
  int ans = 0;
  recur(n, 0, ans);
  return ans;
}