package Medium;

import java.util.*;

public class BinaryTreeZigZagLevelOrderTraversal {

    class Node {
        public Node left;
        public Node right;
        public int data;

        public Node(int data) {
            this.data = data;
        }
    }

    int[] zigzagLevelOrderTraversal(Node root) {
        List<Integer> res = new ArrayList();

        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        boolean RtoL = false;

        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList();

            for (int i = 0; i < size; i++) {
                Node curr = q.poll();

                level.add(curr.data);
                if (curr.left != null)
                    q.offer(curr.left);
                if (curr.right != null)
                    q.offer(curr.right);

            }
            if (RtoL) {
                Collections.reverse(level);
            }
            res.addAll(level);
            RtoL = !RtoL;

        }
        int[] result = new int[res.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = res.get(i);
        }

        return result;
    }

}

