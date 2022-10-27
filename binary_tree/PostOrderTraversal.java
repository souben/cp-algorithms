import java.util.*;
// Definition for a binary tree node.
 class TreeNode {
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

 public class PostOrderTraversal {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans =  new ArrayList<Integer>();
        if(root == null) return ans;
        por(root, ans);
        return ans;
    }
    
    private void por(TreeNode root, List<Integer> ans){
        if(root.left != null ) poi(root.left, ans);
        if(root.right != null) poi(root.right, ans);
        ans.add(root.val);
    }
    
    private void poi(TreeNode root, List<Integer> ans){
        HashMap<TreeNode, Integer> vis = new HashMap<TreeNode, Integer>();
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        while(!s.isEmpty()){
            TreeNode n = s.pop();
            if(vis.get(n) != null){
                ans.add(n.val);
                continue;
            }
            vis.put(n, 1);
            s.push(n);
            if(n.right != null ) s.push(n.right);
            if(n.left != null ) s.push(n.left);
        }
    }
}
























