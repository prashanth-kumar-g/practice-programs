import javafx.application.Application;

import javafx.scene.Scene;

import javafx.scene.control.*;

import javafx.scene.layout.VBox;

import javafx.stage.Stage;


public class SampleTextFieldFX extends Application
{
	@Override
	public void start(Stage stage)
	{
		Label lbl = new Label("Your Name : ");

		TextField tf = new TextField();
		tf.setPromptText("Enter your name");

		Button btn = new Button("Click Me");

		btn.setOnAction(e -> {
					String input = tf.getText();
					lbl.setText("Your Name : " + input);
					System.out.println("\n Your Name : " + input);
				     });

		VBox root = new VBox(10);
		root.getChildren().addAll(lbl, tf, btn);

		Scene scene = new Scene(root, 300, 200);

		stage.setTitle("Sample TextField JavaFX");
		stage.setScene(scene);
		stage.show();

		root.requestFocus();
	}

	public static void main(String [] args)
	{
		launch();
	}
}
