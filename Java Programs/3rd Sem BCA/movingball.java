import java.awt.*;
import java.applet.*;
/*
<applet code="movingball" width=500 height=500>
</applet>
*/
public class movingball extends Applet implements Runnable
{
int x=150,y=50,r=50;
int dx=11,dy=7;
Thread t;
volatile boolean stop;
public void paint(Graphics g)
{
g.setColor(Color.red);
g.fillOval(x-r,y-r,r*2,r*2);
}
public void animate()
{
Rectangle bounds=getBounds();
if((x-r+dx<0)||(x+r+dx>bounds.width))
dx=-dx;
if((y-r+dx<0)||(y+r+dx>bounds.width))
dy=-dy;
x+=dx;
y+=dy;
repaint();
}
public void run()
{
while(!stop)
{
animate();
try
{
Thread.sleep(100);
}
catch(InterruptedException e)
{}
}
}
public void start()
{
t=new Thread(this);
stop=false;
t.start();
}
public void stop()
{
stop=true;
}
}