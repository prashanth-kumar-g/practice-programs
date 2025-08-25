import java.awt.*;
import java.awt.event.*;

public class EventDemo extends Frame implements ActionListener {

    Button b;

    EventDemo() {
        // Create a button
        b = new Button("Click Me");
        b.setBounds(100, 100, 80, 30);

        // Register the listener with the source
        b.addActionListener(this);

        // Add button to the frame
        add(b);

        // Set frame properties
        setSize(300, 200);
        setLayout(null);
        setVisible(true);
    }

    // Override actionPerformed to handle the event
    public void actionPerformed(ActionEvent e) {
        b.setLabel("Clicked!");
    }

    public static void main(String[] args) {
        new EventDemo();
    }
}
