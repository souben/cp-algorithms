import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
import java.util.HashMap;


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
 
public class InOrderTraversal {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        if(root == null) return ans;
        ior(root, ans);
        return ans;
    }
    
    
    private void ior(TreeNode root, List<Integer> ans){
        if( root.left != null) ior(root.left, ans);
        ans.add(root.val);
        if( root.right != null) ior(root.right, ans);
    }
    
    private void ioi(TreeNode root, List<Integer> ans){
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        HashMap<TreeNode, Integer> map = new HashMap<TreeNode, Integer>();  
        while(!s.isEmpty()){
            TreeNode n = s.pop();
            if( map.get(n) != null ){
                ans.add(n.val);
                continue;
            }
            map.put(n , 1);
            if( n.right != null ) s.push(n.right);
            s.push(n);
            if( n.left != null ) s.push(n.left);
        }
    }
}
