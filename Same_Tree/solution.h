using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr || q == nullptr)
            return false;
        
        if(p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


// HELPER FUNCTIONS --- move??? 
void generateTree(TreeNode* root, const vector<int>& input, int idx)
{
    root->val = input[idx];
    int leftChildIdx = idx * 2 + 1;
    int rightChildIdx = idx * 2 + 2;
    if(leftChildIdx < input.size() && input[leftChildIdx] != INT32_MIN)
    {
        root->left = new TreeNode;
        generateTree(root->left, input, leftChildIdx);
    }
    if(rightChildIdx < input.size() && input[rightChildIdx] != INT32_MIN)
    {
        root->right = new TreeNode;
        generateTree(root->right, input, rightChildIdx);
    }
}

// INT32_MIN == null
TreeNode* generateTreeFromVector(const vector<int>& input)
{
    if(input.size() == 0)
        return nullptr;

    TreeNode* root = new TreeNode;
    generateTree(root, input, 0);

    return root;
}