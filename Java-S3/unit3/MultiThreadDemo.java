class MultiThread implements Runnable {
  Thread t;

  MultiThread(String name) {
    t = new Thread(this, name);
    System.out.println("Child thread: " + t);
    t.start();
  }

  public void run() {
    try {
      for (int i = 5; i > 0; i--) {
        System.out.println(t.getName() + ": " + i);
        Thread.sleep(500);
      }
    } catch (InterruptedException e) {
      System.out.println(t.getName() + " interrupted.");
    }
    System.out.println("Exiting " + t.getName() + " thread.");
  }
}

class MultiThreadDemo {
  public static void main(String args[]) {
    new MultiThread("Thread 1");
    new MultiThread("Thread 2");
    new MultiThread("Thread 3");

    try {
      for (int i = 5; i > 0; i--) {
        System.out.println("Main Thread: " + i);
        Thread.sleep(1000);
      }
    } catch (InterruptedException e) {
      System.out.println("Main thread interrupted.");
    }
    System.out.println("Main thread exiting.");
  }
}
