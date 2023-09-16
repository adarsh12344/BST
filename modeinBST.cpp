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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int>mpp;
    void solve(TreeNode* root)     //here we are storing the frequency of each element in the map
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left);
        mpp[root->val]++;
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int>ans;
        int maxi = 0 ;
        for(auto &it:mpp)
        {
            maxi = max(maxi,it.second);   //here we are finding the maximum frequency of the element
        }
        for(auto &it:mpp)
        {
            if(it.second==maxi)
            {   
                ans.push_back(it.first);    //here we are pushing the element with maximum frequency
            }
        }
        return ans;
       
    
    }
};