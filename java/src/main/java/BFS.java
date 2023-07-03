import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class BFS {
    class Node {
        int val;
        Node next;
    }

    public int bfs(Node root, Node target) {
        Queue<Node> queue = new LinkedList<>();
        Set<Node> seen = new HashSet<>();
        int step = 0;

        queue.offer(root);
        seen.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                Node cur = queue.poll();
                assert cur != null;
                if (cur.val == target.val) {
                    return step;
                }

                if (cur.next != null && !seen.contains(cur.next)) {
                    seen.add(cur.next);
                    queue.add(cur.next);
                }
            }
            step++;
        }
        return -1;
    }
}
