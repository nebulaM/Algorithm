/**
  * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
  * Solution obtained from
  * https://discuss.leetcode.com/topic/8398/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
  */
int numTrees(int n) {
    //http://stackoverflow.com/questions/3082914/c-compile-error-variable-sized-object-may-not-be-initialized
    //error "Variable-sized object may not be initialized" when use a[n+1]={0}; use memset instead
    int G[n+1];
    memset( G, 0, (n+1)*sizeof(int) );
    //BASE CASE: BST w/ 0 or 1 node only has 1 unique structure
    G[0]=1;
    G[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            //F(i, n) = G(i-1) * G(n-i)	1 <= i <= n
            //where i is the root and n is total number of node
            //G(i-1) contains the number of unique left subtree and G(n-i) is for right subtree
            //G(n) = F(1, n) + F(2, n) + ... + F(n, n)
            //G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)
            G[i]+=G[j]*G[i-j-1];
        }
    }
    return G[n];
}
