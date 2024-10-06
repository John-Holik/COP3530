#include <iostream>

// the tree node struct
struct TreeNode  {
    int info;
    TreeNode *left, *right;
};

// the binary search tree class
// this is a very minimal implementation
// for example we should have destructor
// also we could have "search", delete etc.
class BinSearchTree {
public:
    bool insert(int newInt);
    void traverseNodes(TreeNode* root);
    void traverseNodes();
    int  findMax();
    int  findMax(TreeNode* root);
private:
    TreeNode* root = nullptr;
};

// insert into the BST following the logic to go left or right
bool BinSearchTree::insert(int newInt){
    TreeNode* p = root;
    TreeNode* q = nullptr;

    while (p != nullptr) {
        if (p->info == newInt) {
            return false;
        }
        q = p;
        if (newInt < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    // new node
    TreeNode* v = new TreeNode;
    v->info = newInt;
    if (q == nullptr) {
        std::cout << "Insert at root " << v->info << std::endl;
        root = v;
    }
    else if (newInt < q->info) {
        std::cout << "Insert " << v->info << " left to " << q->info << std::endl;
        q->left = v;
    }
    else{
        std::cout << "Insert " << v->info << " right to " << q->info << std::endl;
        q->right = v;
    }
    return true;
}

// findMax
int BinSearchTree::findMax(){
    findMax(root);
}
int BinSearchTree::findMax(TreeNode* root){
    if(root == nullptr)
        return -1; // error code

    int temp = root->info; // Store the info of root to a temp var, in case root is the max

    int rMax = findMax(root->right); // check the right nodes
    int lMax = findMax(root->left); // check the left nodes

    // check for max values and update as needed
    if(rMax > temp)
        temp = rMax;
    if(lMax > temp)
        temp = lMax;


    return temp; // return max
}



// traversal
void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private
}

void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr)
        return;
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);
}

////////////////////////////////////////////

int main() {
    BinSearchTree st = BinSearchTree(); // the tree object
    st.insert(8);  //the root
    // where will each of this go in the BST?
    st.insert(3);
    st.insert(11);
    st.insert(9);
    st.insert(10);
    st.insert(14);

    // now traverse
    std::cout << "inorder traversal:  ";
    st.traverseNodes();
    std::cout <<"\n";
    // now find max
    std::cout << "Max value: ";
    std::cout << st.findMax();
}
