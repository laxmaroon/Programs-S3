class MyThread extends Thread {
   public void run() {
      for (int i = 0; i < 5; i++) {
         System.out.println("Thread running: " + i);
         try {
            Thread.sleep(500);
         } catch (InterruptedException e) {
            e.printStackTrace();
         }
      }
   }
}

class IsAliveDemo {
   public static void main(String[] args) {
      MyThread mt = new MyThread();
      mt.start();
      while (mt.isAlive()) {
         System.out.println("Thread is still running");
         try {
            Thread.sleep(1000);
         } catch (InterruptedException e) {
            e.printStackTrace();
         }
      }
      System.out.println("Thread has completed");
   }
}
