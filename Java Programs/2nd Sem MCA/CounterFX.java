import javafx.application.Application;

import javafx.geometry.Pos;

import javafx.scene.Scene;

import javafx.scene.control.*;

import javafx.scene.layout.*;

import javafx.stage.Stage;


public class CounterFX extends Application
{
	private int count = 0;

	@Override
	public void start(Stage stage)
	{
		Label lbl = new Label("Count : 0");

		Button btn1 = new Button("Increase");
		Button btn2 = new Button("Decrease");
		Button btn3 = new Button("Reset");

		btn1.setOnAction(e -> {
				count++;
				lbl.setText("Count : " + count);
				System.out.println("\n Count : " + count);
			});

		btn2.setOnAction(e -> {
				count--;
				lbl.setText("Count : " + count);
				System.out.println("\n Count : " + count);
			});

		btn3.setOnAction(e -> {
				count = 0;
				lbl.setText("Count : " + count);
				System.out.println("\n Count : " + count);
			});

		HBox hbox = new HBox(10);
		hbox.setAlignment(Pos.CENTER);
		hbox.getChildren().addAll(btn1, btn2, btn3);

		VBox vbox = new VBox(20);
		vbox.setAlignment(Pos.CENTER);
		vbox.getChildren().addAll(lbl, hbox);

		Scene scene = new Scene(vbox, 500, 350);

		stage.setTitle("Counter JavaFX");
		stage.setScene(scene);
		stage.show();
	}

	public static void main(String [] args)
	{
		launch();

		System.out.println();
	}
}
