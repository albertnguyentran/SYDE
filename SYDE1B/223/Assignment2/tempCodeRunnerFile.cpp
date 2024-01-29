void traverseUniqueInOrder(Classmate* root) {
    if (root == nullptr) {
        return;
    }

    traverseUniqueInOrder(root->left);

    if (root->names.empty() && !root->left && !root->right) {
        cout << "Shoe Size: " << fixed << setprecision(2) << root->shoeSize
             << ", Name: " << root->firstName << endl;
    }

    traverseUniqueInOrder(root->right);
}