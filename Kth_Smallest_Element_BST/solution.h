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

    int currentSmallestNode = 1;
    int kthSmallest(TreeNode* root, int k) 
    {
        if(root == nullptr)
            return -1;
        if(root->left == nullptr)
        {
            if(currentSmallestNode++ == k)
            {
                return root->val;
            }
            return kthSmallest(root->right, k);
            
        }

        int leftkthSmallest = kthSmallest(root->left, k);
        if(leftkthSmallest != -1)
            return leftkthSmallest;
        if(currentSmallestNode++ == k)
        {
            return root->val;
        }
        return kthSmallest(root->right, k);
    }
};

// INT32_MIN == null
TreeNode* generateTreeFromVector(const vector<int>& input)
{
    if(input.size() == 0)
        return nullptr;

    TreeNode* root = new TreeNode(input[0]);
    queue<TreeNode*> q;
    q.push(root);
    auto i = std::next(input.begin());
    do
    {
        q.front()->left = (*i == INT32_MIN) ? nullptr : new TreeNode(*i);
        if(q.front()->left != nullptr)
            q.push(q.front()->left);
        
        if(++i == input.end())
            break;
        
        q.front()->right = (*i == INT32_MIN) ? nullptr : new TreeNode(*i);
        if(q.front()->right != nullptr)
            q.push(q.front()->right);

        q.pop();

        i++;
    }
    while(i != input.end());

    return root;
}