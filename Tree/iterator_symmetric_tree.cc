class solution{
	bool isSymmetric(TreeNode *root){
		if(root == NULL)
			return true;
		TreeNode *walker = NULL;
		int layer_size = 0;
		deque<TreeNode *> tree_deque;
		tree_deque.push_back(root->left);
		tree_deque.push_back(root->right);
		while(!tree_deque.empty()){
			layer_size = tree_deque.size();
			for(int i = 0; i < layer_size / 2; i++){
				if(tree_deque[i] == NULL ^ tree_deque[layer_size - 1 - i] == NULL) 
					return false;
				if(tree_deque[i] != NULL && tree_deque[layer_size - 1 - i] != NULL 
					&& tree_deque[i]->val != tree_deque[layer_size - 1 - i]->val )
					return false;
			}
			for(int i = 0; i < layer_size; i++){
				walker = tree_deque.front();
				tree_deque.pop_front();
				if(walker != NULL){
					tree_deque.push_back(walker->left);
					tree_deque.push_back(walker->right);
				}
			}
		}
		return true;
	}
};