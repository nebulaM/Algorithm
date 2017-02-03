/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
  * For example:
  * Given binary tree [1,null,2,3]
  * return [1,3,2]
  */
 
/**
 * PRE: *returnSize=0
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *list=malloc(sizeof(int)*(*returnSize));
    inorderTraversalHelper(root,list,returnSize);
    return list;
}

void inorderTraversalHelper(struct TreeNode* root, int* list, int *n){
    if(!root){
        return;
    }
    inorderTraversalHelper(root->left,list,n);
    if(root->val){
	//++(*n) returns (*n)+1 and then inc (*n) by 1
	//(*n)++ returns (*n) and then inc (*n) by 1
	//*n++ inc the pointer location by 1, not modify the content pointed by this pointer
        int size=++(*n);
	//do not forget size parameter in realloc
        list=(int *)realloc(list,sizeof(int)*(size));
        list[size-1]=root->val;
    }
    inorderTraversalHelper(root->right,list,n);
}
