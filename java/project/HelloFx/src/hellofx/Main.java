package hellofx;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;

@SuppressWarnings("unused")

public class Main extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("scene.fxml"));
        Scene scene1 = new Scene(root);
        stage.setScene(scene1);
        Image icon = new Image("icon.png");
        stage.getIcons().add(icon);
        stage.show();

        stage.setOnCloseRequest(event -> {
            event.consume();
            logout(stage);
        });

    }

    public void logout(Stage stage) {

        Alert alert = new Alert(AlertType.CONFIRMATION);
        
        alert.setTitle("LogOut");
        alert.setHeaderText("You are about to logout!!");
        alert.setContentText("Do you want to save before logout?");

        if (alert.showAndWait().get() == ButtonType.OK) {
            // stage = (Stage) anchorPane.getScene().getWindow();
            stage.close();
        }

    }

    public static void main(String[] args) {
        launch(args);
    }

}