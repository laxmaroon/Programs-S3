public class SleepExample {
  public static void main(String[] args) {
    System.out.println("Starting Main Thread");

    try {
      Thread.sleep(6000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    System.out.println("Main Thread Woken Up");
  }
}
