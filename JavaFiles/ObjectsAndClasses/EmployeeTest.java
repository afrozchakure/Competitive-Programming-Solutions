import java.io.*;

class EmployeeTest {
    public static void main(String args[]) {
        Employee empOne = new Employee("Tom Boy");
        Employee empTwo = new Employee("Good Boy");

        empOne.setAge(20);
        empOne.setDes("Associate");
        empOne.setSalary(20000);

        empTwo.setAge(50);
        empTwo.setDes("Boss");
        empTwo.setSalary(20000000);

        empOne.printEmployee();
        System.out.println();
        empTwo.printEmployee();

    }
}