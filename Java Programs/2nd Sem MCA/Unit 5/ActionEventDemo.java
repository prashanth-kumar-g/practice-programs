import java.awt.*;
import java.awt.event.*;

public class ActionEventDemo extends Frame implements ActionListener {

    Button b;

    ActionEventDemo() {
        b = new Button("Click Me");
        b.setBounds(100, 100, 80, 30);
        b.addActionListener(this); // Register listener
        add(b);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }

    // Event Handling Logic
    public void actionPerformed(ActionEvent e) {
        System.out.println("Button Clicked!");
    }

    public static void main(String[] args) {
        new ActionEventDemo();
    }
}
