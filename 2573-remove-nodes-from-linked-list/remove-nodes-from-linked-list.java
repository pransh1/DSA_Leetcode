/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        head.next = removeNodes(head.next);
        if(head != null && head.val < head.next.val){
            return head.next;
        }
        return head;
    }
}

// class Solution {
//     public ListNode removeNodes(ListNode head) {
//         Stack<ListNode> st = new Stack<>();
//         while(head != null) {
//             while(!st.isEmpty() && st.peek().val < head.val) {
//                 st.pop();
//             }
//             st.push(head);
//             head = head.next;
//         }

//         ListNode newHead = null;

//         while(!st.isEmpty()) {
//             ListNode node = st.pop();
//             node.next = newHead;
//             newHead = node;
//         }
//         return newHead;
//     }
// }