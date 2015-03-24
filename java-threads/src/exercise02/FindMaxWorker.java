package exercise02;
import java.util.concurrent.*;

public class FindMaxWorker implements Callable<Integer> {
	private int[] data;
	private int start;
	private int end;
	
	public FindMaxWorker(int[] data, int start, int end) {
		this.data = data;
		this.start = start;
		this.end = end;
	}
	
	@Override
	public Integer call() throws Exception {
		int tempMax = Integer.MIN_VALUE;
		
		for (int i = start; i < end; i ++) {
			if (tempMax < data[i]) {
				tempMax = data[i];
			}
		}
		
		return tempMax;
	}
	
}
