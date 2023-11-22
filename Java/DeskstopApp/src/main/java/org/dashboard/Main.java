package org.dashboard;

import javafx.application.Application;
import jssc.CommChannel;
import jssc.SerialCommChannel;
import org.dashboard.view.MainApplication;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println("Program Started!");

        //Application.launch(MainApplication.class, args);

        CommChannel channel = new SerialCommChannel("COM3",9600);

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