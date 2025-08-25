import java.awt.*;
import java.awt.event.*;

public class MouseEventExample {
    public static void main(String[] args) {
        Frame frame = new Frame("MouseEvent Example");
        Button myButton = new Button("Click Me");
        myButton.setBounds(100, 100, 100, 40);

        frame.add(myButton);
        frame.setSize(300, 300);
        frame.setLayout(null);
        frame.setVisible(false);

        // Create MouseEvent manually
        MouseEvent event = new MouseEvent(
            myButton,                        // Component src
            MouseEvent.MOUSE_CLICKED,        // int type
            System.currentTimeMillis(),      // long when
            InputEvent.BUTTON1_DOWN_MASK,    // int modifiers (left click)
            120, 75,                          // int x, int y
            3,                                // int clicks
            true                             // boolean triggersPopup
        );

        System.out.println("MouseEvent created:");
        System.out.println("Source: " + event.getComponent().getClass().getSimpleName());
        System.out.println("Type: " + event.getID());
        System.out.println("When: " + event.getWhen());
        System.out.println("Modifiers: " + event.getModifiersEx());
        System.out.println("X: " + event.getX() + ", Y: " + event.getY());
        System.out.println("Click Count: " + event.getClickCount());
        System.out.println("Triggers Popup: " + event.isPopupTrigger());
    }
}
