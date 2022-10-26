
// Definition for a binary tree node.
public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
}



class PreOrderTraversal {

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        if(root == null) return ans;
        //ptr(root, ans);
        pti(root, ans);
        return ans;
    }
    
    private void pti(TreeNode r, List<Integer> ans){
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(r);
        while(!s.empty()){
            TreeNode a = s.pop();
            ans.add(a.val);
            if( a.right != null ) s.push(a.right);
            if( a.left != null )  s.push(a.left);
        }
    }
    
    private void ptr(TreeNode root, List<Integer> ans){
        ans.add(root.val);
        if(root.left != null) ptr(root.left, ans);
        if(root.right!= null) ptr(root.right, ans);
    }
}
