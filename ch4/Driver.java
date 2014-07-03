/**
 * This program creates a separate thread by implementing the Runnable interface.
 *
 * Figure 4.12
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */


class Sum
{
	private int sum;

	public int get() {
		return sum;
	}

	public void set(int sum) {
		this.sum = sum;
	}
}

class Summation implements Runnable
{
	private int upper;
	private Sum sumValue;

	public Summation(int upper, Sum sumValue) {
		if (upper < 0)
			throw new IllegalArgumentException();

		this.upper = upper;
		this.sumValue = sumValue;
	}

	public void run() {
		int sum = 0;

		for (int i = 0; i <= upper; i++)
			sum += i;

		sumValue.set(sum);
	}
}

public class Driver
{
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Usage Driver <integer>");
			System.exit(0);
		}

		Sum sumObject = new Sum();
		int upper = Integer.parseInt(args[0]);
		
		Thread worker = new Thread(new Summation(upper, sumObject));
		worker.start();
		try {
			worker.join();
		} catch (InterruptedException ie) { }
		System.out.println("The sum of " + upper + " is " + sumObject.get());
	}
}
