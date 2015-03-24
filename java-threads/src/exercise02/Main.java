/*
 * searches the max value in an array
 * compares the search using threads and using a normal way
 */

package exercise02;

import java.util.concurrent.*;
import java.util.*;

public class Main {
	public static int[] initializeArray(int n) {
		int[] array = new int[n];

		for (int i = 0; i < n; i++) {
			array[i] = (int)(Math.random() * n + 1);
		}

		return array;
	}
	
	public static int findMaxNormal(int arraySize) {
		int array[] = initializeArray(arraySize);
		int tempMax = 0;
		
		long time1 = System.nanoTime();
		
		for (int i : array) {
			if (tempMax < i) {
				tempMax = i;
			}
		}
		
		long time2 = System.nanoTime();
		
		System.out.println((time2 - time1) + " ns");
		return tempMax;
		
	}
	
	public static int findThreaded(int arraySize, int amountThreads) {
		int data[] = initializeArray(arraySize);
		int answers[] = new int[amountThreads];
		
		long time1 = System.nanoTime();
		
		ExecutorService s = Executors.newFixedThreadPool(amountThreads);
		List<Future> futures = new LinkedList<Future>();
		
		// submits a new worker to the ThreadPool
		// which get added to the future list
		
		for (int i = 0; i < amountThreads; i++) {
			futures.add(s.submit(new FindMaxWorker(data, (i * arraySize/amountThreads), ((i+1) * arraySize/amountThreads))));
		}
		
		try {
			for (int i = 0; i < amountThreads; i++) {
				answers[i] = (int) futures.get(i).get();
			}
			
			s.shutdown();
			
			int tempMax = 0;
			for (int i : answers) {
				if (tempMax < i) {
					tempMax = i;
				}
			}
			
			long time2 = System.nanoTime();
			
			System.out.println(amountThreads + " Threads: " + (time2 - time1) + " ns");
			System.out.println();
			return tempMax;
		} 
		catch (InterruptedException e) {
			e.printStackTrace();
		} 
		catch (ExecutionException e) {
			e.printStackTrace();
		}
		
		return 0;
	}
	
	public static void main(String[] args) {
		System.out.println("Testing threaded solution for 100000000 elements using different amounts of threads:");
		
		for (int i = 1; i <= 20; i++)
			findThreaded(100000000, i);
		
		System.out.println("------------------------------------");
		System.out.println();
		System.out.println("Comparing threaded solution with normal solution using 4 threads: ");
		
		for (int i = 100; i <= 100000000; i*=10) {
			System.out.println(i + " elements:");
			findMaxNormal(i);
			findThreaded(i, 4);
		}
	}

}
