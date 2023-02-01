class TicketCuttingThread implements Runnable {
  private int seatNumber;
  
  public TicketCuttingThread(int seatNumber) {
    this.seatNumber = seatNumber;
  }

  @Override
  public void run() {
    System.out.println("Cut the ticket: " + seatNumber);
  }
}

class SeatNumberThread implements Runnable {
  private int seatNumber;
  
  public SeatNumberThread(int seatNumber) {
    this.seatNumber = seatNumber;
  }

  @Override
  public void run() {
    System.out.println("Show your seat number: " + seatNumber);
  }
}

public class Event {
  public static void main(String[] args) {
    for (int i = 1; i <= 50; i++) {
      Thread cutTicketThread = new Thread(new TicketCuttingThread(i));
      Thread showSeatNumberThread = new Thread(new SeatNumberThread(i));
      cutTicketThread.start();
      showSeatNumberThread.start();
    }
  }
}
