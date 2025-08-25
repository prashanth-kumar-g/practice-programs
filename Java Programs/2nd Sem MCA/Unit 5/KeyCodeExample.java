import java.awt.*;
import java.awt.event.*;
import java.lang.reflect.*;

public class KeyCodeExample extends Frame implements KeyListener {

    public KeyCodeExample() {
        addKeyListener(this);
        setSize(400, 200);
        setTitle("KeyCode Example with getKeyChar()");
        setVisible(true);
    }

    public void keyPressed(KeyEvent e) {
        char keyChar = e.getKeyChar();       // Character representation
        int keyCode = e.getKeyCode();        // Integer key code
        String keyName = getKeyText(keyCode); // KeyEvent.VK_* constant

        System.out.println("Pressing " + keyChar + 
                           " → Key Code: " + keyCode + 
                           " (" + keyName + ")");
    }

    public void keyReleased(KeyEvent e) {}
    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        new KeyCodeExample();
    }

    // Utility method to get KeyEvent constant name (like KeyEvent.VK_A)
    private String getKeyText(int keyCode) {
        Field[] fields = KeyEvent.class.getFields();
        for (Field field : fields) {
            try {
                if (field.getName().startsWith("VK_") && field.getInt(null) == keyCode) {
                    return "KeyEvent." + field.getName();
                }
            } catch (Exception ex) {
               
            }
        }
        return "Unknown Key";
    }
}
