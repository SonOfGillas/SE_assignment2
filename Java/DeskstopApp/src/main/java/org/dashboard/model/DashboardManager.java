package org.dashboard.model;

import org.json.simple.*;
import org.json.simple.parser.JSONParser;
import jssc.CommChannel;
import jssc.SerialCommChannel;

public class DashboardManager {
    private final UpdateView updateView;
    private  boolean  mantainence = false;
    private boolean error = false;
    private String CarWashed;
    private String WashingMachineState;
    private String Temperature;


    public DashboardManager(UpdateView updateView) {
        this.updateView = updateView;
        Thread newThread = new Thread(this::dashboardLoop);
        newThread.start();
    }

    public void setMantainenceDone(){
        this.mantainence = true;
    }

    private void dashboardLoop(){
        try {
            CommChannel channel = new SerialCommChannel("COM3",9600);
            JSONParser parser = new JSONParser();

            System.out.println("Waiting Arduino for rebooting...");
            Thread.sleep(4000);
            System.out.println("Ready.");

            while (true){
                System.out.println("Request Data");
                channel.sendMsg("RequestData");
                String msg = channel.receiveMsg();
                System.out.println("Received: "+msg);
                try {
                    JSONObject json = (JSONObject) parser.parse(msg);
                    this.CarWashed = (String) json.get("CarWashed");
                    this.WashingMachineState = (String) json.get("WashingMachineState");
                    this.Temperature = (String) json.get("Temperature");
                    if(this.WashingMachineState.equals("Error") && !this.error){
                        this.error = true;
                        this.mantainence = false;
                    }
                    javafx.application.Platform.runLater(this.updateView::update);
                } catch (Exception e){
                    System.out.println("Parsing Message Error");
                }
                if(error){
                    if(mantainence){
                        System.out.println("Send: MantainenceDone");
                        channel.sendMsg("MantainenceDone");
                        mantainence = false;
                        error = false;
                    }
                }
                Thread.sleep(500);
            }

        } catch (Exception e){
            System.out.println(e.toString());
        }
    }

    public boolean errorDetected() {
        return error;
    }

    public String getCarWashed() {
        return CarWashed;
    }

    public String getWashingMachineState() {
        return WashingMachineState;
    }

    public String getTemperature() {
        return Temperature;
    }

}
