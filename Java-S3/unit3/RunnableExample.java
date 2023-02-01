public class RunnableExample implements Runnable {
  public void run() {
    for (int i = 1; i <= 100; i++) {
      System.out.println("Thread Running: " + i);
    }
  }

  public static void main(String[] args) {
    RunnableExample runnable = new RunnableExample();
    Thread thread = new Thread(runnable);
    thread.start();

    for (int i = 1; i <= 100; i++) {
      System.out.println("Main Thread Running: " + i);
    }
  }
}
