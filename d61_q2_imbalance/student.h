// Your code here
int dfs(node* n, int &max, int &ans) {
    if(n == NULL) return -1;
    int left = dfs(n->left, max, ans);
    int right = dfs(n->right, max, ans);
    int dif = std::abs(left-right);
    // std::cout << "node " << n->data.first << "   dif = " << dif << "\n";
    if(dif > max){
        max = dif;
        ans = n->data.first;
    } else if(dif == max) {
        ans = std::min(ans, n->data.first);
    }
    return 1+std::max(left, right);
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int max=0;
    KeyT ans=9999;
    dfs(mRoot, max, ans);    

    return ans;
}
