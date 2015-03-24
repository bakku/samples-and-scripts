package exercise03;

public class ThreadRow extends Thread {
	private char[][] data;
	private int start;
	private int end;
	
	public ThreadRow(char[][] data, int start, int end) {
		super();
		this.data = data;
		this.start = start;
		this.end = end;
	}
	
	public void run()
	{	
		for (int i = start; i < end; i++) {
			for (int j = 0; j < data[i].length; j++) {
				data[i][j] = 'Z';
			}
		}
	}


}
