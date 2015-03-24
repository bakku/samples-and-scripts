package exercise05;

import java.util.concurrent.Semaphore;

public class CarPark {
	private Semaphore sem;
	private int parkingLimit; // amount of time it is allowed to park
	
	public CarPark(int amountSpaces, int parkingLimit) {
		sem = new Semaphore(amountSpaces);
		this.parkingLimit = parkingLimit;
	}
	
	public void parkNewCar(Car car, int amountOfTime) {
		System.out.println(car.getType() + " wants to park! " +  sem.availablePermits() + " spaces are available.");
		Thread t = new Thread(new ParkingCarThread(sem, car, amountOfTime, parkingLimit));
		t.start();
	}
}
