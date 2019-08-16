
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class videoconference {

	public static class Trie {
		private class Node {
			Character data;
			boolean isTerminal;
			HashMap<Character, Node> Children;

			Node(Character data, boolean isTerminal) {
				this.data = data;
				this.isTerminal = isTerminal;
				this.Children = new HashMap<>();
			}
		}

		private Node root;

		private int numwords;

		Trie() {
			this.root = new Node('\0', false);
			this.numwords = 0;
		}

		public int numwords() {
			return this.numwords;
		}

		public boolean isEmpty() {
			return this.numwords == 0;
		}

		public void addword(String word) {
			this.addword(this.root, word);
		}

		private void addword(Node Parent, String word) {
			if (word.length() == 0) {
				if (Parent.isTerminal) {

				} else {
					Parent.isTerminal = true;
					this.numwords++;
				}
				return;
			}
			Character ch = word.charAt(0);
			String ros = word.substring(1);
			Node child = Parent.Children.get(ch);
			if (child == null) {
				child = new Node(ch, false);
				Parent.Children.put(ch, child);
			}
			this.addword(child, ros);

		}

		

		public String longestMatchingrefix(String pattern) {
			return this.longestMatchingrefix(this.root, pattern, "");
		}

		private String longestMatchingrefix(Node parent, String pattern, String result) {
			if (pattern.length() == 0) {
				return result;
			}
			Character ch = pattern.charAt(0);
			String ros = pattern.substring(1);
			Node child = parent.Children.get(ch);
			if (child == null) {
				return result+ch;
			}
			return this.longestMatchingrefix(child, ros, result + ch);
		}

		public String longestCommonPrefix() {
			return this.longestCommonPrefix(this.root);
		}

		private String longestCommonPrefix(Node parent) {
			Node curr = parent;
			String result = "";
			while (curr.Children.size() == 1) {
				for (int i = 0; i < 26; i++) {
					Node temp = curr.Children.get((char) ('a' + i));
					if (temp == null) {
						continue;
					} else {
						curr = temp;
						result += curr.data;
						break;
					}
				}
			}
			return result;
		}

		

		public static void main(String[] args) {

			Scanner scn = new Scanner(System.in);
			int n = scn.nextInt();
			String arr[] = new String[n];
			for (int i = 0; i < n; i++) {
				arr[i] = scn.next();
			}
			Trie trie = new Trie();
			HashMap<String, Integer> map = new HashMap<>();
			for(int i=0;i<n;i++) {
				if(!map.containsKey(arr[i])) {
					map.put(arr[i], 1);
				} else {
					map.put(arr[i], map.get(arr[i])+1);
				}
				String res = trie.longestMatchingrefix(arr[i]);
				if(res.equals(arr[i]) && map.get(arr[i]) > 1) {
					System.out.println(res +" "+map.get(arr[i]));
				} else {
					System.out.println(res);
				}
				
				trie.addword(arr[i]);
			}

		}

	}
}
