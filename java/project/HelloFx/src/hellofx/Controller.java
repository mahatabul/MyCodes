package hellofx;

import javafx.fxml.FXML;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.scene.control.Label;

import java.io.File;

public class Controller {
    @FXML
    private Label label;

    @FXML
    public void openFile() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Open Source File");

        // Limit to .java and .cpp
        // fileChooser.getExtensionFilters().addAll(
        //     new FileChooser.ExtensionFilter("Java Files", "*.java"),
        //     new FileChooser.ExtensionFilter("C++ Files", "*.cpp")
        // );

        // Show file chooser
        File file = fileChooser.showOpenDialog(new Stage());

        if (file != null) {
            label.setText("Selected: " + file.getName());
            // now you can read it, compile it, etc.
        } else {
            label.setText("No file selected");
        }
    }
}
