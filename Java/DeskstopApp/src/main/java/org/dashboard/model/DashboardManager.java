package org.dashboard.model;

import com.google.gson.Gson;

public class DashboardManager {
    private final UpdateView updateView;
    private final Mantainence mantainence;
    private boolean error = false;
    private int CarWashed;
    private String WashingMachineState;
    private  float Temperature;


    public DashboardManager(UpdateView updateView, Mantainence mantainence) {
        this.updateView = updateView;
        this.mantainence = mantainence;
        dashboardLoop();
    }
    private void dashboardLoop(){
        Gson gson = new Gson();

        /*
        Foo foo = new Foo(1,"first");
        String jsonStr = gson.toJson(foo);
        Foo result = gson.fromJson(jsonStr, Foo.class);
        assertEquals(foo.getId(),result.getId
        */

        while (true){

        }
    }

    public boolean isError() {
        return error;
    }

    public int getCarWashed() {
        return CarWashed;
    }

    public String getWashingMachineState() {
        return WashingMachineState;
    }

    public float getTemperature() {
        return Temperature;
    }

}
