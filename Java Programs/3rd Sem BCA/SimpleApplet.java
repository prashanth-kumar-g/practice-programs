import java.awt.*;
import java.applet.*;
/*
<applet code="SimpleApplet" width=200 height=200>
</applet>
*/
public class SimpleApplet extends Applet
{
public void paint(Graphics g)
{
g.drawString("A Simple Applet",20,20);
g.drawRect(25,25,75,75);
g.fillRect(25,25,75,75);
}
}