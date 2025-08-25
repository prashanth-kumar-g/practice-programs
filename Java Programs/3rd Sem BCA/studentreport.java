import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*
<applet code="studentreport" width=300 height= 200>
</applet>
*/
public class studentreport extends Applet implements 
ActionListener
{
Label r,c,s,s1,s2;
int isub1,isub2;
TextField t1,t2,t3,t4,t5;
Button b;
String rno=" ",course=" ",sem=" ",sub1=" ",sub2=" ",avg=" ",heading=" ";
public void init()
{
setLayout(new GridLayout(6,2));
r=new Label("Register Number");
t1=new TextField(25);
c=new Label("Course");
t2=new TextField(25);
s=new Label("Semester");
t3=new TextField(25);
s1=new Label("Marks of Subject 1");
t4=new TextField(25);
s2=new Label("Marks of Subject 2");
t5=new TextField(25);
b=new Button("View Report");
add(r);
add(t1);
add(c);
add(t2);
add(s);
add(t3);
add(s1);
add(t4);
add(s2);
add(t5);
add(b);
b.addActionListener(this);
}
public void paint(Graphics g)
{
g.drawString(heading,30,30);
g.drawString(rno,30,80);
g.drawString(course,30,100);
g.drawString(sem,30,120);
g.drawString(sub1,30,140);
g.drawString(sub2,30,160);
g.drawString(avg,30,180);
}
public void actionPerformed(ActionEvent e)
{
try
{
if(e.getSource()==b)
{
rno=t1.getText().trim();
course=t2.getText().trim();
sem=t3.getText().trim();
sub1=t4.getText().trim();
sub2=t5.getText().trim();
isub1=Integer.parseInt(sub1);
isub2=Integer.parseInt(sub2);
avg="Average Marks "+((isub1+isub2)/2.0);
rno="Register Number "+rno;
course="course\t"+course;
sem="Semster\t"+sem;
sub1="Subject1\t"+sub1;
sub2="Subject2\t"+sub2;
heading="Student Report";
removeAll();
showStatus("");
repaint();
}
}
catch(Exception ex)
{}
}
}
