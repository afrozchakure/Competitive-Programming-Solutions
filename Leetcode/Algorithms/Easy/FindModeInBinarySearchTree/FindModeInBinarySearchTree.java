import java.util.ArrayList;
import java.util.List;

public class FindTheModeinBST {

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    Integer prev = null;
    int count = 1;
    int max = 0;

    public int[] findMode(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        helper(root, result);


        int[] list = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            list[i] = result.get(i);
        }
        return list;
    }

    void helper(TreeNode root, List<Integer> list) {
        if (root == null)
            return;
        helper(root.left, list);

        if (prev != null) {
            if (prev == root.val) {
                count++;
            } else
                count = 1;
        }

        if (count > max) {
            max = count;
            list.clear();
            list.add(root.val);
        } else if (count == max) {
            list.add(root.val);
        }

        prev = root.val;
        helper(root.right, list);
    }
}
