/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        // use # to mark null
        buildString(sb, root);
        return sb.toString();
    }

    private void buildString(StringBuilder sb, TreeNode node) {
        if (node == null) {
            sb.append("#,");
            return;
        }

        sb.append(node.val).append(',');
        buildString(sb, node.left);
        buildString(sb, node.right);
    }


    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        // 1, 2, #, #, 3, 4, #, #  
        Queue<String> queue = new LinkedList<>(Arrays.asList(data.split(",")));
        return buildTree(queue);
    }

    private TreeNode buildTree(Queue<String> queue) {
        String s = queue.poll();
        if ("#".equals(s)) {
            return null;
        }

        TreeNode node = new TreeNode(Integer.parseInt(s));
        node.left = buildTree(queue);
        node.right = buildTree(queue);

        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
