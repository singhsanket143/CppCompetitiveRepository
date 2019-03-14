package assignments.asgn8b;

import java.util.ArrayList;
import java.util.Scanner;

public class Q5 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		int N = scn.nextInt();
		System.out.println(countNQueens(new boolean[N][N], 0));
		printNQueens(new boolean[N][N], 0, "");
		System.out.println(getNQueens(new boolean[N][N], 0));
	}
	
	public static int countNQueens(boolean[][] board, int row) {
		if (row == board.length) {
			return 1;
		}

		int count = 0;
		for (int col = 0; col < board[row].length; col++) {
			if (isItSafe(board, row, col)) {
				board[row][col] = true;
				count += countNQueens(board, row + 1);
				board[row][col] = false;
			}
		}

		return count;
	}

	public static ArrayList<String> getNQueens(boolean[][] board, int row) {
		if (row == board.length) {
			ArrayList<String> baseResult = new ArrayList<>();

			baseResult.add("\n");

			return baseResult;
		}

		ArrayList<String> myResult = new ArrayList<>();
		
		for (int col = 0; col < board[row].length; col++) {
			if (isItSafe(board, row, col)) {
				board[row][col] = true;
				
				ArrayList<String> recResult = getNQueens(board, row + 1);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add("{" + (row + 1) + "-" + (col + 1) + "}; " + recResult.get(i));
				}
				
				board[row][col] = false;
			}
		}

		return myResult;
	}

	public static void printNQueens(boolean[][] board, int row, String path){
		if (row == board.length) {
			System.out.println(path);
			return;
		}

		for (int col = 0; col < board[row].length; col++) {
			if (isItSafe(board, row, col)) {
				board[row][col] = true;
				printNQueens(board, row + 1, path + "{" + (row + 1) + "-" + (col + 1) + "}; ");
				board[row][col] = false;
			}
		}
	}
	
	private static boolean isItSafe(boolean[][] board, int row, int col) {
		for(int i = row; i >= 0; i--){
			if(board[i][col]){
				return false;
			}
		}
		
		for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
			if(board[i][j]){
				return false;
			}
		}
		
		for(int i = row, j = col; i >= 0 && j < board[0].length; i--, j++){
			if(board[i][j]){
				return false;
			}
		}
		
		return true;
	}


}
