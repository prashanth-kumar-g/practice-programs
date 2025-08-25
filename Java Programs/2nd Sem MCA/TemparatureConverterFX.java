import javafx.application.Application;

import javafx.geometry.Pos;

import javafx.scene.Scene;

import javafx.scene.control.*;

import javafx.scene.layout.*;

import javafx.stage.Stage;


public class TemparatureConverterFX extends Application
{
	private TextField tf1, tf2;
	private double temparature, result;

	@Override
	public void start(Stage stage)
	{
		Label lbl1 = new Label("Temparature in Celsius : ");
		Label lbl2 = new Label("Temparature in Fahrenheit : ");

		tf1 = new TextField();
		tf2 = new TextField();

		tf1.setPromptText("Enter value");
		tf2.setPromptText("Enter value");

		tf1.setPrefColumnCount(10);
		tf2.setPrefColumnCount(10);

		Button btn1 = new Button("Convert C -> F");
		Button btn2 = new Button("Convert F -> C");

		btn1.setOnAction(e -> convert('C') );
		btn2.setOnAction(e -> convert('F') );

		HBox hbox1 = new HBox(5);
		hbox1.setAlignment(Pos.CENTER);
		hbox1.getChildren().addAll(lbl1, tf1);

		VBox vbox1 = new VBox(25);
		vbox1.setAlignment(Pos.CENTER);
		vbox1.getChildren().addAll(hbox1, btn1);

		HBox hbox2 = new HBox(5);
		hbox2.setAlignment(Pos.CENTER);
		hbox2.getChildren().addAll(lbl2, tf2);

		VBox vbox2 = new VBox(25);
		vbox2.setAlignment(Pos.CENTER);
		vbox2.getChildren().addAll(hbox2, btn2);

		HBox root = new HBox(10);
		root.setAlignment(Pos.CENTER);
		root.getChildren().addAll(vbox1, vbox2);

		Scene scene = new Scene(root, 800, 600);

		stage.setTitle("Simple Temparature Converter JavaFX");
		stage.setScene(scene);
		stage.show();

		root.requestFocus();
	}

	private void convert(char symbol)
	{
		try
		{
 	 	        switch(symbol)
			{
			      case 'C': temparature = Double.parseDouble(tf1.getText());
					result = (temparature * 9 / 5) + 32;
					tf2.setText(Double.toString(result));
                	 		System.out.println("\n Result : " + temparature + " C -> " + result + " F");
					break;

			      case 'F': temparature = Double.parseDouble(tf2.getText());
					result = (temparature - 32) * 5 / 9;
					tf1.setText(Double.toString(result));
                	 		System.out.println("\n Result : " + temparature + " F -> " + result + " C ");
					break;
  		    	}
 	       }
	       catch(NumberFormatException e)
	       {
			switch(symbol)
			{
	         		case 'C': tf2.setText("Invalid Input");
					  break;

	         		case 'F': tf1.setText("Invalid Input");
					  break;
			}

		        System.out.println("\n Result : Invalid Input");
    	       }
    	}

	public static void main(String [] args)
	{
		launch();

		System.out.println();
	}
}
