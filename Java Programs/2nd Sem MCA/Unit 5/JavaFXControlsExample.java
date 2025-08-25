import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.scene.control.TreeItem;

public class JavaFXControlsExample extends Application {

    @Override
    public void start(Stage primaryStage) {
        VBox layout = new VBox(10); // Main layout with spacing

        //  Label
        Label labelHeading = new Label("--->Label Control<---");
        Label label = new Label("Choose your favorite fruit:");
        layout.getChildren().addAll(labelHeading, label);

        //  RadioButtons
        Label radioHeading = new Label("--->RadioButton Control<---");
        RadioButton rb1 = new RadioButton("Java");
        RadioButton rb2 = new RadioButton("C++");
        ToggleGroup group = new ToggleGroup();
        rb1.setToggleGroup(group);
        rb2.setToggleGroup(group);
        layout.getChildren().addAll(radioHeading, rb1, rb2);

        // Button
        Label buttonHeading = new Label("--->Button Control<---");
        Button button = new Button("Submit");
        layout.getChildren().addAll(buttonHeading, button);

        //  ListView
        Label listHeading = new Label("--->ListView Control--->");
        ListView<String> listView = new ListView<>();
        listView.getItems().addAll("Mango", "Orange", "Grapes", "Papaya", "Pineapple");
        ScrollPane scrollPane = new ScrollPane(listView);
        scrollPane.setPrefHeight(100);
        layout.getChildren().addAll(listHeading, scrollPane);

        //  TreeView
        Label treeHeading = new Label("--->TreeView Control<---");
        TreeItem<String> root = new TreeItem<>("Fruits");
        root.setExpanded(true);
        root.getChildren().addAll(
            new TreeItem<>("Apple"),
            new TreeItem<>("Banana"),
            new TreeItem<>("Mango")
        );
        TreeView<String> treeView = new TreeView<>(root);
        layout.getChildren().addAll(treeHeading, treeView);

        //  Final Scene Setup
        Scene scene = new Scene(layout, 350, 500);
        primaryStage.setTitle("JavaFX Controls Example");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
