import java.util.*;

public class SplitCircularListIn2Halves {

  // -----------------------------------------------------
  // This is a functional problem. Only this function has to be written.
  // This function takes as input the head of the linked list.
  // It should return an array of heads of the split lists.
  // (Head of first list at 0th index and second at index 1).
  public static Node[] splitList(Node head) {
    // write your code here
    if(head.next == null) {
        Node arr[] = new Node[2];
        arr[0] = head;
        arr[1] = head;
        return arr;
    }
    Node slow = head, fast = head;
    while(fast.next!=head && fast.next.next!=head) {
      slow = slow.next;
      fast = fast.next.next;
    }
    Node second = slow.next;
    slow.next = head;
    if(fast.next == head) {
      fast.next = second;
    } else if(fast.next.next == head) {
      fast.next.next = second;
    }
    Node arr[] = new Node[2];
    arr[0] = head;
    arr[1] = second;
    return arr;
  }

  // -----------------------------------------------------

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n1 = sc.nextInt();
    int a1 = sc.nextInt();
    head1 = addLast(head1, a1);

    for (int i = 1; i < n1; i++) {
      int a = sc.nextInt();
      head1 = addLast(head1, a);
    }

    Node[] arr = splitList(head1);


    if (checkCyclic(arr[0]) && checkCyclic(arr[1])) {
      display(arr[0]);
      display(arr[1]);
    } else {
      System.out.println(-1);
    }

  }

  // Class declaration for a Node of the Linked List
  static class Node {
    int data;
    Node next;

    public Node(int data, Node next) {
      this.data = data;
      this.next = next;
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
  public static Node addLast(Node head, int data) {
    if (head == null) {
      Node nn = new Node(data, null);
      nn.next = nn;
      return nn;
    }

    Node curr = head;

    // go to tail
    while (curr.next != head) {
      curr = curr.next;
    }

    // add new node to next to tail and make new node's
    // next as head to maintain cyclic nature of linked list
    curr.next = new Node(data, head);
    return head;
  }

  public static boolean checkCyclic(Node head) {
    if (head == null) {
      return true;
    }

    Node curr = head;

    boolean result = false;
    while (curr.next != null && curr.next != head) {
      curr = curr.next;
    }
    if (curr.next == head) {
      result = true;
    }

    return result;
  }

  /*
   * Input Parameters: head: head of the cyclic linked list in which is to be
   * displayed.
   *
   * Return Value: null
   */
  public static void display(Node head) {

    if (head == null) {
      return;
    }

    Node curr = head;
    System.out.print(curr.data + " ");
    curr = curr.next;

    while (curr != head) {
      System.out.print(curr.data + " ");
      curr = curr.next;
    }

    System.out.println();
  }

}