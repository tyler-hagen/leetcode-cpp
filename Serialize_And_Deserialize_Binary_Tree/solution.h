#include <queue>
#include <stack>

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        
        string ret;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front(); q.pop();
            if(node == nullptr)
            {
                ret += ",";
                continue;
            }

            ret += std::to_string(node->val);
            ret += ",";
            
            q.push(node->left);
            q.push(node->right);
        }
        
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;

        // need to change to a vector first, so we can reason about the size of the tree
        // O(n)
        vector<int> nodeVals = nodeStringToNodeVector(data);
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(*(nodeVals.begin()));
        q.push(root);
        auto i = std::next(nodeVals.begin());
        while(!q.empty())
        {
            if(*i != INT32_MIN)
            {
                q.front()->left = new TreeNode(*i); 
                q.push(q.front()->left);
            }
            i++; 

            if(*i != INT32_MIN)
            {
                q.front()->right = new TreeNode(*i); 
                q.push(q.front()->right);
            }
            i++;

            q.pop();
        }

        return root;
    }

    vector<int> nodeStringToNodeVector(const string& data)
    {
        vector<int> nodeVals;
        auto i = 0;
        while(i < data.size())
        {
            auto commaPos = data.find(",", i);
            // this is a "null" child
            if(commaPos == i)
            {
                nodeVals.push_back(INT32_MIN);
            }
            else
            {
                auto nodeVal = data.substr(i, commaPos);
                nodeVals.push_back(std::stoi(nodeVal));
            }
            i = commaPos+1;
        }

        return nodeVals;
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