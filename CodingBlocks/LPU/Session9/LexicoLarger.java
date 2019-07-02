import java.util.*;

class LexicoLarger {
	public static void lexicoHstring(String str, String osf, boolean bool) {
		if (str.length() == 0) {
			System.out.println(osf);
			return;
		}
		for (int i = 0; i < str.length(); i++) {
			if (bool) {
				char ch = str.charAt(i);
				String ros = str.substring(0, i) + str.substring(i + 1);
				lexicoHstring(ros, osf + ch, bool);
			} else {
				if (str.charAt(i) >= str.charAt(0)) {
					char ch = str.charAt(i);
					String ros = str.substring(0, i) + str.substring(i + 1);
					lexicoHstring(ros, osf + ch, bool || ch > str.charAt(0));
				}
			}
		}
	}
	public static void main(String[] args) {
		
		 lexicoHstring("bcad", "", false);
	}
}