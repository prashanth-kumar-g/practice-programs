import java.awt.*;
import java.awt.event.*;

public class SimpleAdapterDemo extends Frame {

    public SimpleAdapterDemo() {
        setTitle("Mouse Adapter Example");
        setSize(300, 150);
        setLayout(null);

        // Add mouse listener
        addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                setTitle("Mouse Clicked");
            }
        });

        // Add mouse motion listener
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                setTitle("Mouse Dragged");
            }
        });

        // Close window properly
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        setVisible(true);
    }

    public static void main(String[] args) {
        new SimpleAdapterDemo();
    }
}
