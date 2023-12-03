package org.dashboard.view;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import org.dashboard.model.DashboardManager;
import org.dashboard.model.UpdateView;

public class MenuSceneController extends AbstractController{
    private DashboardManager dashboardManager;

    @FXML
    private BorderPane root;
    @FXML private Label CarWashed;
    @FXML private Label WashingMachineState;
    @FXML private Label Temperature;
    @FXML private VBox errorConsole;

    /**
     * {@inheritDoc}
     */
    @Override
    public void initialize() {
        this.dashboardManager = new DashboardManager(updateView);
        errorConsole.setVisible(false);
    }

    private final UpdateView updateView = () -> {
        CarWashed.setText(this.dashboardManager.getCarWashed());
        WashingMachineState.setText(this.dashboardManager.getWashingMachineState());
        Temperature.setText(this.dashboardManager.getTemperature() + "C°");
        errorConsole.setVisible(this.dashboardManager.errorDetected());
    };
    
    /**
     * {@inheritDoc}
     */
    @FXML
    public void onMantencanceDone(final MouseEvent event) {
        this.dashboardManager.setMantainenceDone();
    }

}
