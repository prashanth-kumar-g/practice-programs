import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="appletevents" width=500 height=500>
</applet>
*/
public class appletevents extends Applet implements 
MouseListener,MouseMotionListener,KeyListener
{
String str="";
String str2="";
public void init()
{
addMouseListener(this);
addMouseMotionListener(this);
addKeyListener(this);
requestFocus();
}
public void keyTyped(KeyEvent e)
{
str2 += e.getKeyChar();
repaint();
}
public void keyPressed(KeyEvent e)
{
showStatus("Key Pressed");
}
public void keyReleased(KeyEvent e)
{
showStatus("Key Released");
}
public void paint(Graphics g)
{
g.drawString("Applet Events",20,20);
g.drawString(str,20,40);
g.drawString(str2,20,60);
}
public void mousePressed(MouseEvent me)
{
str="Mouse button Pressed";
repaint();
}
public void mouseClicked(MouseEvent me)
{
str="Mouse button Clicked";
repaint();
}
public void mouseReleased(MouseEvent me)
{
str="Mouse button Released";
repaint();
}
public void mouseEntered(MouseEvent me)
{
str="Mouse button Entered";
repaint();
}
public void mouseExited(MouseEvent me)
{
str="Mouse button Exited";
repaint();
}
public void mouseMoved(MouseEvent me)
{
str="Mouse Moved";
repaint();
}
public void mouseDragged(MouseEvent me)
{
str="Mouse Dragged";
repaint();
}
public void mouseDropped(MouseEvent me)
{
str="Mouse dropped";
repaint();
}
}
