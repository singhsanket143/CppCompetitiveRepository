import java.util.*;
 
 public class ConnectedComponentsLL {
 
     // -----------------------------------------------------
     // This is a functional problem. Only this function has to be written.
     // This function takes as input the head of the linked list and array G.
     // It should return the number of connected components in G.
     public static int numComponents(Node n, int[] G) {
         // write your code here
         HashMap<Integer, Boolean> mp = new HashMap<>();
         for(int i=0;i<G.length;i++) {
             mp.put(G[i], true);
         }
         Node temp = n;
         boolean check=false;
         int c=0;
         while(temp!=null) {
             if(mp.containsKey(temp.data) && (temp.next==null || !mp.containsKey(temp.next.data))) {
                 c++;
                 
             } 
             temp=temp.next;
         }
         return c;
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
 
         int n2 = sc.nextInt();
         int[] arr = new int[n2];
 
         for (int i = 0; i < n2; i++) {
             arr[i] = sc.nextInt();
         }
         
         System.out.println(numComponents(head1, arr));
 
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