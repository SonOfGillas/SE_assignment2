package org.dashboard.view;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import static org.dashboard.view.ViewState.HEIGHT;
import static org.dashboard.view.ViewState.WIDTH;

import java.io.IOException;


public class MenuGUI implements Showable {
    
    private final Stage stage;
    private Scene scene;
    
    public MenuGUI(final Stage stage) {
        this.stage = stage;  
        this.loadFXML();
    }
    
    /**
     * This method loads the file FXML with all graphics
     */
    private void loadFXML() {
        
        this.stage.setMinWidth(WIDTH.getMinValue());
        this.stage.setMinHeight(HEIGHT.getMinValue());
        
        try {
            final Parent root = FXMLLoader.load(ClassLoader.getSystemResource("layout/MenuScene.fxml"));
            this.scene = new Scene(root, WIDTH.getValue(), HEIGHT.getValue());
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }

    /**
     * {@inheritDoc}
     */
    public Scene getScene() {
        return this.scene;
    }

}
