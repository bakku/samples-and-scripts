package exercise05;

public class Main {
	public static void main(String[] args) {
		/* 5 parking spaces.
		 * A car can only park for 1000 milliseconds */
		CarPark carpark = new CarPark(5, 1000);
		
		String types[] = { "Mercedes", "Toyota", "BMW", "Audi", "VW", "Porsche", "Nissan", 
				"Sean", "Fiat", "Ford", "Lamborghini", "Suzuki", "Hyundai", "Mitsubishi"
		};
		Car[] cars = new Car[types.length];
		
		for (int i = 0; i < types.length; i++) {
			cars[i] = new Car(types[i]);
		}
		
		for (int i = 0; i < cars.length; i++) {
			/* new car which wants to park
			 * each driver only wants to wait for 1 second */
			carpark.parkNewCar(cars[i], 1000); 
			
			/* waiting a little for the next car to park */
			try {
				Thread.sleep((int)(Math.random() * 300 + 1));
			} 
			
			catch (InterruptedException e) {
				System.out.println("Exception in main Sleep");
			}
		}
	}
}
