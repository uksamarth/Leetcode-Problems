/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int minLevel = INT_MAX;
        int maxSum = INT_MIN;
        int level = 1;

        while(!q.empty()) {
            int s = q.size();
            int sum = 0;
            while(s--) {
                auto f = q.front();
                q.pop();
                sum += f->val; 
                if(f->left) {
                    q.push(f->left);
                }
                if(f->right) {
                    q.push(f->right);
                }
            } 
            //cout << sum << " " << level <<  endl;
            if(sum > maxSum) {
                maxSum = sum;
                minLevel = level;
            }
            if(sum == maxSum) {
                minLevel = min(minLevel, level);
            }
            level++;
        }

        return minLevel;
        
    }
};