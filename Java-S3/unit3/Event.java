class TicketCuttingThread implements Runnable {
   int seat = 1;
   public void run() {
      while (seat <= 50) {
         System.out.println("Cut the ticket: " + seat);
         seat++;
         try {
            Thread.sleep(100);
         } catch (InterruptedException e) {
            System.out.println(e);
         }
      }
   }
}

class SeatNumberThread implements Runnable {
   int seat = 1;
   public void run() {
      while (seat <= 50) {
         System.out.println("Show your seat number: " + seat);
         seat++;
         try {
            Thread.sleep(100);
         } catch (InterruptedException e) {
            System.out.println(e);
         }
      }
   }
}

public class Event {
   public static void main(String[] args) {
      TicketCuttingThread ticketCutting = new TicketCuttingThread();
      SeatNumberThread seatNumber = new SeatNumberThread();
      Thread t1 = new Thread(ticketCutting);
      Thread t2 = new Thread(seatNumber);
      t1.start();
      t2.start();
   }
}
