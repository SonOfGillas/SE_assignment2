package org.dashboard;

import jssc.SerialCommChannel;
import jssc.SerialPortList;
import jssc.CommChannel;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println("Program Started!");
        /* detect serial ports */
        String[] portNames = SerialPortList.getPortNames();
        for (int i = 0; i < portNames.length; i++){
            System.out.println(portNames[i]);
        }

        CommChannel channel = new SerialCommChannel("COM3",9600);
        // CommChannel channel = new SerialCommChannel("/dev/cu.usbmodem1411",9600);
        // CommChannel channel = new SerialCommChannel("/dev/cu.isi00-DevB",9600);

        /* attesa necessaria per fare in modo che Arduino completi il reboot */
        System.out.println("Waiting Arduino for rebooting...");
        Thread.sleep(4000);
        System.out.println("Ready.");


        while (true){
            System.out.println("Sending ping");
            channel.sendMsg("ping");
            String msg = channel.receiveMsg();
            System.out.println("Received: "+msg);
            Thread.sleep(500);
        }
    }
}