class OddThread implements Runnable {
private int sum = 0;

@Override
public void run() {
for (int i = 1; i <= 10; i += 2) {
sum += i;
try {
Thread.sleep(100);
} catch (InterruptedException e) {
e.printStackTrace();
}
}
}

public int getSum() {
return sum;
}
}

class EvenThread implements Runnable {
private int sum = 0;

@Override
public void run() {
for (int i = 2; i <= 10; i += 2) {
sum += i;
try {
Thread.sleep(100);
} catch (InterruptedException e) {
e.printStackTrace();
}
}
}

public int getSum() {
return sum;
}
}

public class Main {
public static void main(String[] args) {
OddThread oddThread = new OddThread();
EvenThread evenThread = new EvenThread();

Thread t1 = new Thread(oddThread);
Thread t2 = new Thread(evenThread);

t1.start();
t2.start();

try {
t1.join();
t2.join();
} catch (InterruptedException e) {
e.printStackTrace();
}

int totalSum = oddThread.getSum() + evenThread.getSum();
System.out.println("Total Sum: " + totalSum);
}
}