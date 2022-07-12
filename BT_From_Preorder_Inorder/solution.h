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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderValueKeys;
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderValueKeys.emplace(inorder[i], i);
        }
        auto node = buildTree(inorderValueKeys, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

        
        return node;
    }
    
    TreeNode* buildTree(const unordered_map<int, int>& inorderValueKeys, const vector<int>& preorder, int preOrderBegin, int preOrderEnd, const vector<int> inorder, int inOrderBegin, int inOrderEnd)
    {
        if(preOrderBegin > preOrderEnd) // need a base case here.
            return nullptr;
        TreeNode* node = new TreeNode(preorder[preOrderBegin]);
        auto middleInorderIdx = inorderValueKeys.find(preorder[preOrderBegin])->second;
        
        node->left = buildTree(inorderValueKeys, preorder,preOrderBegin+1, preOrderBegin + (middleInorderIdx - inOrderBegin), inorder, inOrderBegin, middleInorderIdx - 1);
        node->right = buildTree(inorderValueKeys, preorder, preOrderBegin + (middleInorderIdx - inOrderBegin) + 1, preOrderEnd, inorder, middleInorderIdx + 1, inOrderEnd);
            
        return node;
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