/*
 * searches an element in an array
 * compares the search using two threads and using one thread
 */

package exercise01;

public class Main {
	public static int[] initializeArray(int n) {
		int[] array = new int[n];
		
		for (int i = 0; i < n; i++) {
			array[i] = i+1;
		}
		
		return array;
	}
	
	public static void searchNormal(int length, int searchElement) {

		int[] data = initializeArray(length);
		
		long time1 = System.nanoTime();
		
		for (int i = 0; i < length; i++) {
			if (data[i] == searchElement) {
				break;
			}
		}
		
		long time2 = System.nanoTime();
		
		System.out.println("Normal: " + (time2 - time1) + " ns"); 
	}
	
	public static void searchThreaded(int length, int searchElement) throws InterruptedException {
		
		int[] data = initializeArray(length);
		
		long time1 = System.nanoTime();
		
		SearchThread st1 = new SearchThread(data, searchElement, 0, length/2);
		SearchThread st2 = new SearchThread(data, searchElement, length/2, length);

		st1.start();
		st2.start();
		
		st1.join();
		st2.join();
		
		long time2 = System.nanoTime();
		
		System.out.println("Threads: " + (time2 - time1) + " ns");
		System.out.println();
	}
	
	public static void main(String[] args) throws InterruptedException {
		for (int i = 100, k = 45; i <= 100000000; i*=10, k*=10) {
			System.out.println(i + " elements: ");
			searchNormal(i, k);
			searchThreaded(i, k);
		}
	}
}
