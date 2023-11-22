import java.util.LinkedList;

public class DeepestLeavesSum {
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

    public int deepestLeavesSum(TreeNode root) {
        // Bfs - queue

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int level_sum = 0;

        while (!queue.isEmpty()) {
            level_sum = 0;

            int size = queue.size();
            for (int i = 0; i < size; i++) {

                TreeNode curr = queue.poll();
                level_sum += curr.val;

                if (curr.left != null) queue.offer(curr.left);
                if (curr.right != null) queue.offer(curr.right);
            }
        }
        return level_sum;
    }
}

