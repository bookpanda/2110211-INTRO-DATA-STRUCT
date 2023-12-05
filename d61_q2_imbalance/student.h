// Your code here
int dfs(node* n, int &max, int &ans) {
    if(!n) return 0;
    
    int lh = dfs(n->left, max, ans);
    int rh = dfs(n->right, max, ans);
    int dif = std::abs(lh-rh);
    if(dif > max) {
        max = dif;
        ans = n->data.first;
    } else if(dif == max && n->data.first < ans) {
        ans = n->data.first;
    }
    int res = 1+std::max(lh, rh);
    return res;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int max=-1;
    int ans=-1;
    dfs(mRoot, max, ans);
    return ans;
}
