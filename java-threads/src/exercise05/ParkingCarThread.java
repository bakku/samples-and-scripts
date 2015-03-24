package exercise05;

import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

public class ParkingCarThread implements Runnable {
	private Semaphore sem;
	private Car car;
	private int patience; // the patience of the driver, after waiting for this time he will drive away
	private int parkingLimit;
	
	public ParkingCarThread(Semaphore sem, Car car, int patience, int parkingLimit) {
		this.sem = sem;
		this.car = car;
		this.patience = patience;
		this.parkingLimit = parkingLimit;
	}
	
	public void parkCar() throws InterruptedException {
		boolean acquired = sem.tryAcquire(patience, TimeUnit.MILLISECONDS);
		
		if (acquired) {
			System.out.println(car.getType() + " is in the carpark now.");
			Thread.sleep(parkingLimit);
			System.out.println(car.getType() + " leaves the carpark now.");
			sem.release();
		}
		// driver has waited to long!
		else {
			System.out.println(car.getType() + " has waited too long. He will leave now.");
		}
	}

	@Override
	public void run() {
		try {
			parkCar();
		} 
		catch (InterruptedException e) {
			System.out.println("Exception in ParkingCarThread!");
		}
	}
}
