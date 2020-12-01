import java.io.*;

public class Employee {
    String name;
    String designation;
    int salary;
    int age;

    public Employee(String name) {
        this.name = name;
    }

    public void setDes(String empDes) {
        designation = empDes;
    }

    public void setAge(int empAge) {
        age = empAge;
    }

    public void setSalary(int empSalary) {
        salary = empSalary;
    }

    public void printEmployee() {
        System.out.println("Employee Name : " + name);
        System.out.println("Employee Age : " + age);
        System.out.println("Employee Salary : " + salary);
        System.out.println("Employee Designation : " + designation);
    }

}