import java.util.*;
  
  public class LongestPalindromeInLL {
  
      // -----------------------------------------------------
      // This is a functional problem. Only this function has to be written.
      // This function takes as input the head of the linked list.
      // It should return the length of maximum palindrome.
      public static int maxPalindrome(Node head) {
          Node prev = null;
          Node curr = head;
          int result = Integer.MIN_VALUE;
          while(curr != null) {
            Node next = curr.next;
            curr.next = prev;

            result = Math.max(result, 2*common(prev, next) + 1);
            result = Math.max(result, 2*common(curr, next));

            prev = curr;
            curr = next;
          }
          return result;
      }
  
      public static int common(Node first, Node sec) {
          int count = 0;
          while (first != null && sec != null && first.data == sec.data) {
              count++;
              first = first.next;
              sec = sec.next;
          }
          return count;
      }
  
      // -----------------------------------------------------
  
      public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          int n1 = sc.nextInt();
          int a1 = sc.nextInt();
          head1 = insert(head1, a1);
  
          for (int i = 1; i < n1; i++) {
              int a = sc.nextInt();
              head1 = insert(head1, a);
          }
  
          System.out.println(maxPalindrome(head1));
      }
  
      // Class declaration for a Node of the Linked List
      static class Node {
          int data;
          Node next;
  
          public Node(int data) {
              this.data = data;
              this.next = null;
          }
  
      }
  
      static Node head1;
  
      static Node head2;
  
      static Node head3;
  
      /*
       * Input Parameters: head: head of the linked list in which a new node is to
       * be inserted. data: the data value of the node which is to be inserted.
       * 
       * Return Value: head of the linked list in which the node is inserted
       */
      public static Node insert(Node head, int data) {
  
          if (head == null) {
              return new Node(data);
          }
  
          head.next = insert(head.next, data);
          return head;
      }
  
      /*
       * Input Parameters: head: head of the linked list in which is to be
       * displayed.
       * 
       * Return Value: null
       */
      public static void display(Node head) {
          for (Node node = head; node != null; node = node.next) {
              System.out.print(node.data + " ");
          }
          System.out.println();
      }
  
  }