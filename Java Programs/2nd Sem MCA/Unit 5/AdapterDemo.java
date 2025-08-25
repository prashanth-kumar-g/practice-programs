import java.awt.*;
import java.awt.event.*;

public class AdapterDemo extends Frame {

    public AdapterDemo() {
        setTitle("Adapter Demo");
        setSize(400, 200);
        setLayout(new FlowLayout());

        // Add mouse listeners using adapter classes
        addMouseListener(new MyMouseAdapter(this));
        addMouseMotionListener(new MyMouseMotionAdapter(this));

        // Close window on click
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        setVisible(true);
    }

    // This replaces showStatus from Applet
    public void showStatus(String msg) {
        // Set title bar to show the message
        setTitle(msg);
    }

    public static void main(String[] args) {
        new AdapterDemo();
    }
}

class MyMouseAdapter extends MouseAdapter {
    AdapterDemo adapterDemo;

    public MyMouseAdapter(AdapterDemo adapterDemo) {
        this.adapterDemo = adapterDemo;
    }

    public void mouseClicked(MouseEvent me) {
        adapterDemo.showStatus("Mouse clicked at (" + me.getX() + ", " + me.getY() + ")");
    }
}

class MyMouseMotionAdapter extends MouseMotionAdapter {
    AdapterDemo adapterDemo;

    public MyMouseMotionAdapter(AdapterDemo adapterDemo) {
        this.adapterDemo = adapterDemo;
    }

    public void mouseDragged(MouseEvent me) {
        adapterDemo.showStatus("Mouse dragged at (" + me.getX() + ", " + me.getY() + ")");
    }
}
