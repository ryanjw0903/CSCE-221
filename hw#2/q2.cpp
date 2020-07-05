int BinaryNode::size(BinaryNode *t) { 

    if (t == nullptr) 
        return 0;
    if(t->left != nullptr && t->right != nullptr)
        return 1 + size(t->left) + size(t->right);

    if(t->left != nullptr && t->right == nullptr)
         return 0 + size(t->left)

    if(t->left == nullptr && t->right != nullptr)
         return 0 + size(t->right)
    else
        return 0;
}