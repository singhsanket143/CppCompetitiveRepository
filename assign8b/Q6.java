
import java.util.ArrayList;
import java.util.Scanner;

public class Q6 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int N = scn.nextInt();
		System.out.println(countNKnights(new boolean[N][N], 0, 0, 0));
		// printNKnights(new boolean[N][N], 0, 0, 0, "");
		// System.out.println(getNKnights(new boolean[N][N], 0, 0, 0));
	}

	public static int countNKnights(boolean[][] board, int placed, int sr, int sc) {
		if (placed == board.length) {
			return 1;
		}

		int count = 0;

		for (int row = sr; row < board.length; row++) {
			for (int col = (row == sr? sc: 0); col < board.length; col++) {
				if (board[row][col] == false && isItSafe(board, row, col)) {
					board[row][col] = true;
					count += countNKnights(board, placed + 1, row, col + 1);
					board[row][col] = false;
				}
			}
		}

		return count;
	}

	public static void printNKnights(boolean[][] board, int placed, int sr, int sc, String osf) {
		if (placed == board.length) {
			System.out.println(osf);
			return;
		}

		for (int row = sr; row < board.length; row++) {
			for (int col = (row == sr? sc: 0); col < board.length; col++) {
				if (board[row][col] == false && isItSafe(board, row, col)) {
					board[row][col] = true;
					printNKnights(board, placed + 1, row, col + 1, osf + "{" + row + "-" + col + "}; ");
					board[row][col] = false;
				}
			}
		}
	}

	public static ArrayList<String> getNKnights(boolean[][] board, int placed, int sr, int sc){
		if (placed == board.length) {
			ArrayList<String> baseResult = new ArrayList<>();

			baseResult.add("\n");

			return baseResult;
		}
		
		ArrayList<String> myResult = new ArrayList<>(), recResult = null;
		
		for (int row = sr; row < board.length; row++) {
			for (int col = (row == sr? sc: 0); col < board.length; col++) {
				if (board[row][col] == false && isItSafe(board, row, col)) {
					board[row][col] = true;
					recResult = getNKnights(board, placed + 1, row, col + 1);
					
					for(int i = 0; i < recResult.size(); i++){
						myResult.add("{" + row + "-" + col + "}; " + recResult.get(i));
					}
					
					board[row][col] = false;
				}
			}
		}
		
		return myResult;
	}
	
	private static boolean isItSafe(boolean[][] board, int row, int col) {
		if (isValidPosition(row - 2, col - 1, board.length) && board[row - 2][col - 1]) {
			return false;
		} else if (isValidPosition(row - 2, col + 1, board.length) && board[row - 2][col + 1]) {
			return false;
		} else if (isValidPosition(row - 1, col - 2, board.length) && board[row - 1][col - 2]) {
			return false;
		} else if (isValidPosition(row - 1, col + 2, board.length) && board[row - 1][col + 2]) {
			return false;
		} else if (isValidPosition(row + 1, col - 2, board.length) && board[row + 1][col - 2]) {
			return false;
		} else if (isValidPosition(row + 1, col + 2, board.length) && board[row + 1][col + 2]) {
			return false;
		} else if (isValidPosition(row + 2, col - 1, board.length) && board[row + 2][col - 1]) {
			return false;
		} else if (isValidPosition(row + 2, col + 1, board.length) && board[row + 2][col + 1]) {
			return false;
		}

		return true;
	}

	public static boolean isValidPosition(int row, int col, int N) {
		return row >= 0 && row < N && col >= 0 && col < N;
	}
}
