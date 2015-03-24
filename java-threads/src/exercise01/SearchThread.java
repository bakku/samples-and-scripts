package exercise01;

import java.lang.Thread;

public class SearchThread extends Thread {
	private int[] data;
	private int element;
	private int start;
	private int end;
	private boolean found;
	
	public SearchThread(int[] data, int element, int start, int end)
	{
		this.data = data;
		this.element = element;
		this.start = start;
		this.end = end;
		this.found = false;
	}
	
	public boolean isFound() {
		return found;
	}
	
	public void run() {
		for (int i = start; i < end && !found; i++) {
			if (data[i] == element) {
				found = true;
			}
		}
	}
}
