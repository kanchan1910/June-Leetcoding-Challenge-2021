
class Solution {
public:
    
    unordered_map<int, int>m;
    TreeNode* fun(vector<int>& preorder, int& index, int l, int r)
    {
       // base case 
        if(l > r)
        {
            return NULL;
        }
        
        int val = preorder[index];
        index++;
        // forming the node
        TreeNode* node = new TreeNode(val);
        node->left = fun(preorder, index, l, m[val] - 1);
        node->right = fun(preorder, index, m[val] + 1, r);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int index = 0;
        // doing the work of searching the index in the inorder traversal
        for(int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return fun(preorder, index, 0, inorder.size() - 1);
    }
};

//             i
//  [3,9,20,15,7]
// (9,0) (3,1) (15,2) (20,3) (7,4)
//             lr       
//  [9,3,15,20,7]
 
//       val = 20
    
//       3
//     9   20 
//  NULL  15  7
//      NULL
      
// // preorder
// // [3,9,20,15,7]

// // inorder
// // [9,3,15,20,7]


    
// //     3 
// // 9     20
// //     15   7



// // preorder
// // [3,9,20]

// // inorder
// // [9,3,20]


// //     3
// 9      20
