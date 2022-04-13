#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int diameter;
    int dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return diameter;
    }
};

void test(TreeNode *root, int expected){
    int actual = (new Solution())->diameterOfBinaryTree(root);
    bool result = expected == actual;
    cout <<"result:"<< result <<", "<< expected<< ", " << actual << endl;
}

int main()
{
    TreeNode root1(
        1,
        new TreeNode(
            2,
            new TreeNode(4),
            new TreeNode(5)
            ),
        new TreeNode(3)
        );

    test(&root1, 3);

    TreeNode root2(
        1,
        new TreeNode(2),
        nullptr
    );
    test(&root2, 1);
    return 0;
}

/*
Runtime: 4 ms, faster than 97.45% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 20.4 MB, less than 25.79% of C++ online submissions for Diameter of Binary Tree.
*/