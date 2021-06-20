// When we have the same method names within the same class 
// but with different number of arguments, 
// we call it **method overloading**
public class Student{
    private int studentId, score;
    private String name;
    private String department; 

    // We can store it in every variable of class using static 
    // static makes a variable common to each and every variable of a class
    static String collegeName = "ABC";

    // Student here follows **constructor overloading**
    public Student(int studentId, String name, String department, float score)
    {
        // It means first execute the constructor with 3 arguments 
        // and then initialize the score variable
        this(studentId, name, department);
        this.score = score;
    }

    public Student(int studentId, String name, String department)
    {
        super();
        this.studentId = studentId;
        this.name = name;
        this.department = department;
    }
    
    public void display()
    {
        System.out.println(this.studentId + " " + this.name + " " + this.department);
    }
}