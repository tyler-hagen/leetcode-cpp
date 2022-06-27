using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    friend bool operator==(const TreeNode& lhs, const TreeNode& rhs)
    {   
        cout << "woo!!!!" << endl;
        return true;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr; 
        return nullptr;       
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