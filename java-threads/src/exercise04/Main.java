/*
 * checks the case that many threads use one resource at the same time
 */

package exercise04;

import java.util.*;

public class Main {
	public static void updateGlobalVal(int amountThreads) {
		System.out.print(amountThreads + " Thread: ");
		List<Thread> threads = new LinkedList<Thread>();
		
		for (int i = 0; i < amountThreads; i++) {
			threads.add(new IncrementThread());
		}
		
		for (Thread t : threads)
			t.start();
		
		try {
			for (Thread t : threads)
				t.join();
			
			System.out.println(IncrementThread.globalValue + "\n");
		} 
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws InterruptedException {
		updateGlobalVal(500);
	}

}
