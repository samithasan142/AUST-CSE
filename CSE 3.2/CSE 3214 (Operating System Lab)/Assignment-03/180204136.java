package firstthread;

import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

class SharedResource {
    Semaphore read = new Semaphore(3);
    Semaphore write = new Semaphore(1);
    int readerCount = 0;
    boolean writerInside = false;
}

class Reader implements Runnable {

    SharedResource sr;

    Reader(SharedResource sr) {
        this.sr = sr;
    }

    @Override
    public void run() {
        while(true){
        if (sr.write.availablePermits()==1 && sr.writerInside == false) {
            try {
                sr.read.acquire();
                sr.readerCount++;
                System.out.println("Reader "+ Thread.currentThread().getName() + " goes for reading...");
                Thread.sleep(500);
                System.out.println("Reader "+ Thread.currentThread().getName() + " leaving after reading...");
            
                sr.readerCount--;
                sr.read.release();
                Thread.sleep(2500);

            } catch (InterruptedException ex) {
                Logger.getLogger(Reader.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

    }}
}

class Writer implements Runnable {

    SharedResource sr;

    Writer(SharedResource sr) {
        this.sr = sr;
    }

    @Override
    public void run() {
        
        try {
            
            while (true) {
                Thread.sleep(400);
                //if (sr.readerCount == 0 && sr.writerInside == false) {
                System.out.print("");
                if(sr.read.availablePermits()==3 && sr.readerCount == 0){
                    
                    sr.write.acquire();
                    sr.writerInside = true;
                    System.out.println("Writer "+Thread.currentThread().getName() + " goes for writing...");
                    Thread.sleep(200);
                    System.out.println("Writer "+Thread.currentThread().getName() + " leaves after writing...");
                    sr.writerInside = false;
                    sr.write.release();
                                      
                }
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(Writer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

public class MyThread2 {

    public static void main(String args[]) {
        SharedResource c = new SharedResource ();

        Reader r1 = new Reader(c);
        Reader r2 = new Reader(c);
        Reader r3 = new Reader(c);
        
        Writer r4 = new Writer(c);
        Writer r5 = new Writer(c);

        new Thread(r1, "1").start();
        new Thread(r2, "2").start();
        new Thread(r3, "3").start();
        
        new Thread(r4, "1").start();
        new Thread(r5, "2").start();
    }
}
