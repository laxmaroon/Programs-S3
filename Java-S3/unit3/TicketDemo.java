class NewThread implements Runnable {
String name; // name of thread
Thread t;
NewThread(String threadname) {
name = threadname;
t = new Thread(this, name);
System.out.println("New thread: " + t);
t.start(); // Start the thread
}
// This is the entry point for thread.
public void run() {
try {
for(int i = 1; i <=50; i++) {
System.out.println(name + ": " + i);
Thread.sleep(500);
}
} catch (InterruptedException e) {
System.out.println(name + "Interrupted");
}
System.out.println(name + " exiting.");
}
}

class TicketDemo {
public static void main(String args[]) {
new NewThread("Seat No."); // start threads
new NewThread("Ticket No.");

try {
// wait for other threads to end
Thread.sleep(25500);
} catch (InterruptedException e) {
System.out.println("Main thread Interrupted");
}
System.out.println("Main thread exiting.");
}
}