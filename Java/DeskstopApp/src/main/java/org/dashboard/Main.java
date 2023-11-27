package org.dashboard;

import javafx.application.Application;
import jssc.CommChannel;
import jssc.SerialCommChannel;
import org.dashboard.view.MainApplication;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println("Program Started!");

        Application.launch(MainApplication.class, args);

        /*
        CommChannel channel = new SerialCommChannel("COM3",9600);
        JSONParser parser = new JSONParser();

        System.out.println("Waiting Arduino for rebooting...");
        Thread.sleep(4000);
        System.out.println("Ready.");

        while (true) {
            System.out.println("Request Data");
            channel.sendMsg("RequestData");
            String msg = channel.receiveMsg();
            System.out.println("Received: " + msg);
        }
         */
    }
}