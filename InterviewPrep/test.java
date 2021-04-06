/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
static class Vertex {
        public int[] next;
        public boolean leaf;
        public int p;
        public char ch;
        public int link;
        public int[] go;


        Vertex() {
            this.p = -1;
            this.ch = '\0';
            next = new int[26];
            go = new int[26];
            Arrays.fill(go, -1);
            Arrays.fill(next, -1);
        }

        Vertex(int p, char ch) {
            this.p = p;
            this.ch = ch;
            next = new int[26];
            go = new int[26];
            Arrays.fill(go, -1);
            Arrays.fill(next, -1);
        }
    }
    public static ArrayList<Vertex> trie  = new ArrayList<>();
    
    public static void addString(String s) {
        int v = 0;
        for(int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int c = ch - 'a';
            if(trie.get(v).next[c] == -1) {
                trie.get(v).next[c] = trie.size();
                trie.add(new Vertex(v, ch));
            }
            v = trie.get(v).next[c];
        }
        System.out.println("."+trie.get(v).ch);
        trie.get(v).leaf = true;
    }

    public static int get_link(int v) {
        if(trie.get(v).link == -1) {
            if(v == 0 || trie.get(v).p == 0) {
                trie.get(v).link = 0;
            } else {
                trie.get(v).link = go(get_link(trie.get(v).p), trie.get(v).ch);
            }
        }
        return trie.get(v).link;
    }

    public static int go(int v, char ch) {
        int c = ch- 'a';
        if(trie.get(v).go[c] == -1) { 
           if(trie.get(v).next[c] != -1) {
                trie.get(v).go[c] = trie.get(v).next[c];
           } else {
                trie.get(v).go[c] = v == 0 ? 0 : go(get_link(v), ch);
           }
        }
        return trie.get(v).go[c];
    }

    public static int AhoCorasick(String[] arr, String word) {
        int ans = 0;
        trie.add(new Vertex());
        for(String s: arr) {
            addString(s);
        }
        int v = 0;
        for(int i=0;i<word.length();i++) {
            int x = go(v, word.charAt(i));
            System.out.println(trie.get(x).ch+ " "+trie.get(x).leaf);
            if(trie.get(x).leaf == true) ans++;
            v = x;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String word = scn.next();
        int n = scn.nextInt();
        String[] arr = new String[n];
        for(int i =0 ; i < n; i++) {
            arr[i] = scn.next();
        }
        System.out.println(AhoCorasick(arr, word));
    }
}
