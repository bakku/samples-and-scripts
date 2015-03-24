package exercise04;

public class IncrementThread extends Thread {
	static int globalValue = 0;
	
	public void run() {
		incrementValue();
	}
	
	// Lost Update Problem
	public static void incrementValue() {
		for (int i = 0; i < 1000; i++) {
			globalValue++;
		}
	}
	
	// No Lost Update Problem
//	public synchronized static void incrementValue() {
//		for (int i = 0; i < 1000; i++) {
//			globalValue++;
//		}
//	}
}
