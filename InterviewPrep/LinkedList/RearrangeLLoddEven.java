import java.util.*;
 
 public class RearrangeLLoddEven {
 
     // -----------------------------------------------------
     // This is a functional problem. Only this function has to be written.
     // This function takes as input the head of the linked list.
     // It should return the head of the modified linked list.
     public static Node oddEvenList(Node head) {
        // write your code here
        if(head == null || head.next==null || head.next.next == null) return head;
        Node last = head;
        int i = 1;
        Node stop = last;
        while(last.next!=null) {
            stop = last;
            last = last.next;
        } 
        
        Node temp = head;
        while(temp.next!=stop) {
            if(i%2 != 0) {
                Node target = temp.next;
                temp.next = target.next;
                last.next = target;
                target.next = null;
                last = last.next;
            } else {
                temp = temp.next;
            }
            i++;
        }
        if(i%2!=0 ){
        } else {
            temp = temp.next;
        }
        Node target = temp.next;
        temp.next = target.next;
        last.next = target;
        target.next = null;
        last = last.next;
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
 
         head1 = oddEvenList(head1);
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
     }
 
 }