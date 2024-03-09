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

    unordered_map<int,pair<int,char>>Parent;

    void FindNode(TreeNode* node){

        TreeNode* leftNode = node->left;
        TreeNode* rightNode = node->right;
        if(leftNode != nullptr) {
            Parent[leftNode->val] = {node->val, 'L'};
            FindNode(leftNode);
        }
        if(rightNode != nullptr){
            Parent[rightNode->val] = {node->val, 'R'};
            FindNode(rightNode);
        }
    }


    vector<pair<int,char>> FindPath(int initialValue, int rootValue){
        vector<pair<int,char>>path;
        if(initialValue == rootValue){
            path.push_back({initialValue,'0'});
            return path;
        }

        int currentParent = initialValue;
        path.push_back({currentParent, '0'});
        while(true){
            path.push_back(Parent[currentParent]);
            currentParent = Parent[currentParent].first;
            if(currentParent == rootValue)break;
        }
        reverse(path.begin(), path.end());
        return path;
    }


    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "";
        int rootValue = root->val;
        //memset(Parent, {-1,'0'}, sizeof(Parent));
        FindNode(root);
        vector<pair<int,char>> pathA= FindPath(startValue, rootValue);
        vector<pair<int,char>> pathB = FindPath(destValue, rootValue);

        string path_a = "", path_b = "";

        int ancestor;
        for(int i = 0; i < pathA.size() && i < pathB.size(); i++){
            if(pathA[i].first != pathB[i].first)break;
            ancestor = i;
        }
        for(int i = ancestor; i < pathA.size(); i++){
            if(pathA[i].first == startValue)break;
            path_a.push_back('U');
        }

        for(int i = ancestor; i < pathB.size(); i++){
            if(pathB[i].first == destValue)break;
            path_b.push_back(pathB[i].second);
        }

        return path_a+path_b;
    }
};
