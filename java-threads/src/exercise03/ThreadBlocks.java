package exercise03;

public class ThreadBlocks extends Thread {
	private char[][] data;
	private int startRow;
	private int endRow;
	private int startIndex;
	private int endIndex;
	
	public ThreadBlocks(char[][] data, int startRow, int endRow,
			int startIndex, int endIndex) {
		super();
		this.data = data;
		this.startRow = startRow;
		this.endRow = endRow;
		this.startIndex = startIndex;
		this.endIndex = endIndex;
	}
	
	public void run() {
		for (int i = startRow; i < endRow; i++) {
			for (int j = startIndex; j < endIndex; j++) {
				data[i][j] = 'Z';
			}
		}
	}
}
