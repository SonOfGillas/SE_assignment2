package org.dashboard;

import javafx.application.Application;
import org.dashboard.view.MainApplication;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println("Program Started!");

        Application.launch(MainApplication.class, args);
    }
}