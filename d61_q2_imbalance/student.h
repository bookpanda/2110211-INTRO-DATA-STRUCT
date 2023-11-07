// Your code here
int dfs(node* n, KeyT &a, int &dif) {
    if(n==NULL) return -1;
    int left = dfs(n->left, a, dif);
    int right = dfs(n->right, a, dif);
    int diff = std::abs(left-right);
    // std::cout << "node " << n->data.first << "\n";
    // std::cout << "left " << left << "  right " << right << "  dif " << diff << "\n";
    if(diff > dif || (diff == dif && n->data.first < a)) {
        dif = diff;
        a = n->data.first;
    }
    return 1+ std::max(left, right);
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int min=-99999;
    KeyT ans=-1;
    dfs(mRoot, ans, min);

    return ans;
}
