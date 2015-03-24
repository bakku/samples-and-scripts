/*
 * changes a 2D-array using different two different types of data decomposition
 */

package exercise03;

public class Main {
	
	public static char[][] initializeArray(int n) {
		char array[][] = new char[n][n];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				array[i][j] = 'A';
			}
		}
		
		return array;
	}
	
	public static char[][] initializeArray() {
		return initializeArray(10000);
	}
	
	public static void changeArrayNormal() {
		char[][] data = initializeArray();
		
		long time1 = System.nanoTime();
		for (int i = 0; i < data.length; i++) {
			for (int j = 0; j < data[i].length; j++) {
				data[i][j] = 'Z';
			}
		}
		
		long time2 = System.nanoTime();
		
		System.out.println((time2 - time1) + " ns");
	}
	
	/* 
	 * using 4 threads
	 * divides all the rows into 4 parts
	 * each thread is responsible for one row part of the array
	 */
	public static void changeArrayRows() {
		char[][] data = initializeArray();
		Thread t[] = new Thread[4];
		long time1 = System.nanoTime();
		
		for (int i = 0; i < 4; i++) {
			t[i] = new ThreadRow(data, (i * data.length/4), (i+1) * data.length/4);
			t[i].start();
		}
		
		try {
			for (Thread threads : t)
				threads.join();
		}
		catch (Exception e) { 
			System.out.println(e);
		}
		
		long time2 = System.nanoTime();
		
		System.out.println((time2 - time1) + " ns");
	}
	
	/* using 4 threads
	 * divides the 2D array into 4 blocks
	 * every thread is responsible for one block of the 2D array
	 */
	public static void changeArrayBlocks() {
		char[][] data = initializeArray();
		Thread t[] = new Thread[4];
		long time1 = System.nanoTime();

		t[0] = new ThreadBlocks(data, 0, data.length/2, 0, data[0].length/2); // Upper Left 
		t[1] = new ThreadBlocks(data, 0, data.length/2, data[0].length/2, data[0].length); // Upper Right
		t[2] = new ThreadBlocks(data, data.length/2, data.length, 0, data[0].length/2); // Lower Left
		t[3] = new ThreadBlocks(data, data.length/2, data.length, data[0].length/2, data[0].length); // Lower Right
		
		for (Thread threads : t) {
			threads.start();
		}
		
		try {
			for (Thread threads : t)
				threads.join();
			
			long time2 = System.nanoTime();
			
			System.out.println((time2 - time1) + " ns");
		}
		catch (Exception e) { 
			System.out.println(e);
		}
	}
	
	public static void main(String[] args) {
		System.out.println("Normal: ");
		changeArrayNormal();
		System.out.println("Data Decomposition (Rows) and 4 Threads:");
		changeArrayRows();
		System.out.println("Data Decomposition (Blocks) and 4 Threads:");
		changeArrayBlocks();
	}
}
