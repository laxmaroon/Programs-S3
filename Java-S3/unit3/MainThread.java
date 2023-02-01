public class MainThread {
  public static void main(String[] args) {
    Thread mainThread = Thread.currentThread();
    System.out.println("Before Change - Thread Name: " + mainThread.getName());
    System.out.println("Before Change - Thread Priority: " + mainThread.getPriority());
    System.out.println("Before Change - Thread Group: " + mainThread.getThreadGroup().getName());

    mainThread.setName("Modified Main Thread");
    mainThread.setPriority(Thread.MAX_PRIORITY);

    System.out.println("After Change - Thread Name: " + mainThread.getName());
    System.out.println("After Change - Thread Priority: " + mainThread.getPriority());
    System.out.println("After Change - Thread Group: " + mainThread.getThreadGroup().getName());

    for (int i = 1; i <= 100; i++) {
      System.out.println(i);
    }
  }
}
