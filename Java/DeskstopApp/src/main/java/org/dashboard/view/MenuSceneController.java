package org.dashboard.view;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class MenuSceneController extends AbstractController{
    
    Stage primaryStage;
    Showable gui;
    
    @FXML
    private BorderPane root;

    
    /**
     * {@inheritDoc}
     */
    @Override
    public void initialize() {}
    
    /**
     * {@inheritDoc}
     */
    @FXML
    public void onStartGamePressed(final MouseEvent event) {
        
        this.primaryStage = (Stage)root.getScene().getWindow();
        super.setDimension(this.primaryStage.getScene().getWidth(), this.primaryStage.getScene().getHeight());
    }
    
    
    /**
     * 
     *     when is called you can check the rules
     * 
     * @param event active when is clicked a button
     */
    @FXML
    public void onRulesPressed(final MouseEvent event) {
        this.primaryStage = (Stage)root.getScene().getWindow();
        super.setDimension(this.primaryStage.getScene().getWidth(), this.primaryStage.getScene().getHeight());
    }
    
    /**
     * 
     *     when is called the application shutdown
     * 
     * @param event active when is clicked a button
     */
    @FXML
    public void onQuitPressed(final MouseEvent event) {
        Platform.exit();
    }

}
