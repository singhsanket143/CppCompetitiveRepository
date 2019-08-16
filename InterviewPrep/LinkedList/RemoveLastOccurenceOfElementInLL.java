import java.util.*;
  
  public class RemoveLastOccurenceOfElementInLL {
  
      // -----------------------------------------------------
      // This is a functional problem. Only this function has to be written.
      // This function takes as input the head of the linked list and key.
      // It should return the head of the modified list.
      
      public static Node func(Node head, int key) {
          // write your code here
        Node temp = head;
        Node rem = head;
        while(temp!=null && temp.next!=null) {
          if(temp.next.data == key) {
            rem = temp;
          }
          temp = temp.next;
        }
        if(rem == head && rem.data == key) {
          head = rem.next;
          rem.next = null;
          return head;
        }
        if(rem!=null && rem.next!=null && rem.data == key) {
          Node test = rem.next;
          rem.next = rem.next.next;
          test.next = null;
        }
        return head;

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
  
          int k = sc.nextInt();
          head1 = func(head1, k);
          display(head1);
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