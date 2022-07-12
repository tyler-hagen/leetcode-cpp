#include <queue>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    bool operator==(const TreeNode& rhs) const
    {   
        return ((this->val == rhs.val)
            && ((this->left == nullptr && rhs.left == nullptr) || (this->left != nullptr && rhs.left != nullptr && *(this->left) == *(rhs.left)))
            && ((this->right == nullptr && rhs.right == nullptr) || (this->right != nullptr && rhs.right != nullptr && *(this->right) == *(rhs.right)))
        );
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root->left != nullptr && (root->left->val >= root->val ))
            return false;
        if(root->right != nullptr && (root->right->val <= root->val))
            return false;
        return isValidBST(root->left, root->val, INT64_MIN) && isValidBST(root->right, INT64_MAX, root->val);
    }
    
    bool isValidBST(TreeNode* root, long long maxValue, long long minValue)
    {
        if(root == nullptr)
            return true;
        if(root->left != nullptr && (root->left->val >= root->val || root->left->val >= maxValue || root->left->val <= minValue))
            return false;
        if(root->right != nullptr && (root->right->val <= root->val || root->right->val >= maxValue || root->right->val <= minValue))
            return false;
        
        int minAllowed = root->val > minValue ? root->val  : minValue;
        int maxAllowed = root->val < maxValue ? root->val  : maxValue;
        return isValidBST(root->left, maxAllowed, minValue) && isValidBST(root->right, maxValue, minAllowed);
    }
};

// INT32_MIN == null
TreeNode* generateTreeFromVector(const vector<long long>& input)
{
    if(input.size() == 0)
        return nullptr;

    TreeNode* root = new TreeNode(input[0]);
    queue<TreeNode*> q;
    q.push(root);
    auto i = std::next(input.begin());
    do
    {
        q.front()->left = (*i == INT64_MIN) ? nullptr : new TreeNode(*i);
        if(q.front()->left != nullptr)
            q.push(q.front()->left);
        
        if(++i == input.end())
            break;
        
        q.front()->right = (*i == INT64_MIN) ? nullptr : new TreeNode(*i);
        if(q.front()->right != nullptr)
            q.push(q.front()->right);

        q.pop();

        i++;
    }
    while(i != input.end());

    return root;
}