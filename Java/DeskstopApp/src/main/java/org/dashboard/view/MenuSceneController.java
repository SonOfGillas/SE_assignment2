package org.dashboard.view;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class MenuSceneController extends AbstractController{
    
    Stage primaryStage;
    Showable gui;
    
    @FXML
    private BorderPane root;

    @FXML private Label CarWashed;
    @FXML private Label WashingMachineState;
    @FXML private Label Temperature;

    
    /**
     * {@inheritDoc}
     */
    @Override
    public void initialize() {
        //TODO inizialize Dashboard manager
    }
    
    /**
     * {@inheritDoc}
     */
    @FXML
    public void onMantencanceDone(final MouseEvent event) {

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
