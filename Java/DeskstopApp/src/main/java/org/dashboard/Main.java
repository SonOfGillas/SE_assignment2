package org.dashboard;

import javafx.application.Application;
import org.dashboard.view.MainApplication;

public class Main {
    public static void main(String[] args) {
        System.out.println("Program Started!");

        Application.launch(MainApplication.class, args);
    }
}