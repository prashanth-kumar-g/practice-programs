import javafx.application.Application;

import javafx.geometry.Pos;

import javafx.scene.Scene;

import javafx.scene.control.*;

import javafx.scene.layout.*;

import javafx.stage.Stage;


public class SimpleCalculatorFX extends Application
{
	private TextField tf1, tf2, tf3;
	private double n1, n2, result;

	@Override
	public void start(Stage stage)
	{
		Label lbl1 = new Label("First Number : ");
		Label lbl2 = new Label("Second Number : ");
		Label lbl3 = new Label("Result : ");

		tf1 = new TextField();
		tf2 = new TextField();
		tf3 = new TextField();

		tf1.setPromptText("Enter value");
		tf2.setPromptText("Enter value");
		tf3.setPromptText("Result");

		tf1.setPrefColumnCount(7);
		tf2.setPrefColumnCount(7);
		tf3.setPrefColumnCount(10);

		Button btn1 = new Button("Add");
		Button btn2 = new Button("Subtract");
		Button btn3 = new Button("Multiply");
		Button btn4 = new Button("Divide");

		btn1.setOnAction(e -> calculate('+') );

		btn2.setOnAction(e -> calculate('-') );

		btn3.setOnAction(e -> calculate('*') );

		btn4.setOnAction(e -> calculate('/') );

		HBox hboxN1 = new HBox(5);
		hboxN1.setAlignment(Pos.CENTER);
		hboxN1.getChildren().addAll(lbl1, tf1);

		HBox hboxN2 = new HBox(5);
		hboxN2.setAlignment(Pos.CENTER);
		hboxN2.getChildren().addAll(lbl2, tf2);

		HBox hboxN = new HBox(10);
		hboxN.setAlignment(Pos.CENTER);
		hboxN.getChildren().addAll(hboxN1, hboxN2);

		HBox hboxR = new HBox(5);
		hboxR.setAlignment(Pos.CENTER);
		hboxR.getChildren().addAll(lbl3, tf3);

		HBox hboxB = new HBox(10);
		hboxB.setAlignment(Pos.CENTER);
		hboxB.getChildren().addAll(btn1, btn2, btn3, btn4);

		VBox root = new VBox(20);
		root.setAlignment(Pos.CENTER);
		root.getChildren().addAll(hboxN, hboxR, hboxB);

		Scene scene = new Scene(root, 1000, 800);

		stage.setTitle("Simple Caluclator JavaFX");
		stage.setScene(scene);
		stage.show();

		root.requestFocus();
	}

	private void calculate(char operator)
	{
		try
		{
			n1 = Double.parseDouble(tf1.getText());
            		n2 = Double.parseDouble(tf2.getText());

 	 	        switch(operator)
			{
			      case '+': result = n1 + n2;
					break;

			      case '-': result = n1 - n2;
					break;

		    	      case '*': result = n1 * n2;
					break;

	                      case '/': result = n1 / n2;
                    			break;
		        }

        	    	tf3.setText(Double.toString(result));
                	System.out.println("\n Result : " + n1 + " " + operator + " " + n2 + " = " + result);

 	       }
	       catch(NumberFormatException e)
	       {
	         	tf3.setText("Invalid Input");
		        System.out.println("\n Result : Invalid Input");
    	       }
    	}

	public static void main(String [] args)
	{
		launch();

		System.out.println();
	}
}
