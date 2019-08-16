package Lecture31;
import java.util.*;
import java.util.Set;

public class HCoder {

	private HashMap<Character, String> encoder;
	private HashMap<String, Character> decoder;

	public HCoder(String feeder) {// Step 1 create a frequency map
		HashMap<Character, Integer> freqMap = new HashMap<>();
		for (int i = 0; i < feeder.length(); i++) {
			Character ch = feeder.charAt(i);
			if (freqMap.containsKey(ch)) {
				int ov = freqMap.get(ch);
				freqMap.put(ch, ov + 1);

			} else {
				freqMap.put(ch, 1);
			}
		}

		// create a min heap of trees
		Heap<Node> minHeap = new Heap<>(true);
		Set<Map.Entry<Character, Integer>> fmEntries = freqMap.entrySet();
		for (Map.Entry<Character, Integer> fmEntry : fmEntries) {
			Node bt = new Node(fmEntry.getKey(), fmEntry.getValue());
			minHeap.add(bt);
		}

		// remove two, add one until size = 1
		while (minHeap.size() != 1) {
			Node minOne = minHeap.remove();
			Node minTwo = minHeap.remove();

			Node tobeadded = new Node(minOne, minTwo);
			minHeap.add(tobeadded);
		}

		// retrive the full tree
		Node finalTree = minHeap.remove();
		this.encoder = new HashMap<>();
		this.decoder = new HashMap<>();
		this.initEncoderDecoder(finalTree, "");

	}

	private void initEncoderDecoder(Node node, String osf) {
		if (node == null)
			return;
		if (node.left == null && node.right == null) {
			this.encoder.put(node.data, osf);
			decoder.put(osf, node.data);
		}
		this.initEncoderDecoder(node.left, osf + "0");
		this.initEncoderDecoder(node.right, osf + "1");
	}

	public String encode(String source) {
		String rv = " ";
		for (int i = 0; i < source.length(); i++) {
			String coded = encoder.get(source.charAt(i));
			rv += coded;

		}
		return rv;
	}

	public String decode(String Codedstring) {
		String rv = "";
		String key = "";
		for (int i = 0; i < Codedstring.length(); i++) {
			key += Codedstring.charAt(i);
			if (decoder.containsKey(key)) {
				rv += decoder.get(key);
				key = "";
			}
		}
		return rv;
	}

	public class Node implements Comparable<Node> {
		Character data;
		int cost;
		Node left;
		Node right;

		Node(Character data, int cost) {
			this.data = data;
			this.cost = cost;
			this.left = left;
			this.right = right;
		}

		Node(Node left, Node right) {
			this.data = '\0';
			this.cost = left.cost + right.cost;
			this.left = left;
			this.right = right;
		}

		public int compareTo(Node other) {
			return this.cost - other.cost;
		}

	}

}