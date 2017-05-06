/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

package leetcode;

import java.util.Scanner;

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

public class Solution {
	public static ListNode addTwoNumbers(ListNode l1 , ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode cur = head;
        int extra = 0;
        while(l1 != null || l2 != null || extra != 0){
        	int sum = ((l1 != null) ? l1.val : 0) + ((l2 != null) ? l2.val : 0) + extra;
        	extra = sum / 10;
        	cur.next = new ListNode(sum % 10);
        	cur = cur.next;
        	if(l1 != null) l1 = l1.next;
        	if(l2 != null) l2 = l2.next;
        }
        return head.next;
    }

	public static ListNode createList() {
		ListNode head = new ListNode(0);
		ListNode cur = head;
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNextInt()) {
			int x = scanner.nextInt();
			ListNode temp = new ListNode(x);
			cur.next = temp;
			cur = cur.next;
		}
		return head.next;
	}

	public static void printList(ListNode head) {
		ListNode p = head;
		while(p != null) {
			System.out.print(p.val+"\t");
			p = p.next;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode l1 = createList();
		ListNode l2 = createList();
		ListNode head = addTwoNumbers(l1, l2);
		printList(head);
	}

}
