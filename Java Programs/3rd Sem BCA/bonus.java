abstract class Department
{
double salary,bonus,totalSalary;
public abstract void calBonus(double salary);
public void displaysalary(String dept)
{
System.out.println(dept+"\t"+salary+"\t"+bonus+"\t"+totalSalary);
}
}
class accounts extends Department
{
public void calBonus(double sal)
{
salary=sal;
bonus=sal*0.2;
totalSalary=salary+bonus;
}
}
class sales extends Department
{
public void calBonus(double sal)
{
salary=sal;
bonus=sal*0.3;
totalSalary=salary+bonus;
}
}
public class bonus
{
public static void main(String args[])
{
Department d1=new accounts();
Department d2=new sales();
d1.calBonus(10000);
d2.calBonus(20000);
System.out.println("Department\tSalary\tBonus\tTotal Salary");
d1.displaysalary("Accounts");
d2.displaysalary("Sales ");
}
}
