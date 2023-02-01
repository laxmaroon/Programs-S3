class GeneratePrime {
  public synchronized void generatePrimenumbers() {
    for (int i = 1; i <= 50; i++) {
      boolean isPrime = true;
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) {
        System.out.println(i + " is a prime number");
      }
    }
  }
}

class PrimeThread extends Thread {
  private GeneratePrime generatePrime;

  public PrimeThread(GeneratePrime generatePrime) {
    this.generatePrime = generatePrime;
  }

  @Override
  public void run() {
    generatePrime.generatePrimenumbers();
  }
}

public class PrimeNos {
  public static void main(String[] args) {
    GeneratePrime generatePrime = new GeneratePrime();
    PrimeThread primeThread1 = new PrimeThread(generatePrime);
    PrimeThread primeThread2 = new PrimeThread(generatePrime);
    primeThread1.start();
    primeThread2.start();
  }
}
