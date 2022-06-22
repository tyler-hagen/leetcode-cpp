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
    int maxPath;
    int maxPathSum(TreeNode* root) 
    {
        maxPath = INT32_MIN;
        maxPathImpl(root);  
        return maxPath;
    }

    int maxPathImpl(TreeNode* root)
    {
        int maxSumNotTwoChildren;
        if(root->left == nullptr && root->right == nullptr)
        {
            maxSumNotTwoChildren = root->val;
            maxPath = maxSumNotTwoChildren > maxPath ? maxSumNotTwoChildren : maxPath;
        }
        else if(root->left == nullptr)
        {
            int rightMaxSum = maxPathImpl(root->right);

            maxSumNotTwoChildren = std::max({root->val, root->val + rightMaxSum}); 
            maxPath = maxSumNotTwoChildren > maxPath ? maxSumNotTwoChildren : maxPath;
        }
        else if(root->right == nullptr)
        {
            int leftMaxSum = maxPathImpl(root->left);

            maxSumNotTwoChildren = std::max({root->val, root->val + leftMaxSum}); 
            maxPath = maxSumNotTwoChildren > maxPath ? maxSumNotTwoChildren : maxPath;

        }
        else
        {
            int leftMaxSum = maxPathImpl(root->left);
            int rightMaxSum = maxPathImpl(root->right);

            // could be val, val + left, or val + right.
            int maxSumTwoChildren = std::max({root->val, root->val + leftMaxSum, root->val + rightMaxSum, root->val + leftMaxSum + rightMaxSum});
            maxPath = maxSumTwoChildren > maxPath ? maxSumTwoChildren : maxPath;

            maxSumNotTwoChildren = std::max({root->val, root->val + leftMaxSum, root->val + rightMaxSum});
        }

        return maxSumNotTwoChildren;     
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