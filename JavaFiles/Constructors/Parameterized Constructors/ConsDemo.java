class MyClass {
    int num;

    MyClass(int num) {
        this.num = num;
    }
}

public class ConsDemo {
    public static void main(String args[]) {
        MyClass t1 = new MyClass(12);
        MyClass t2 = new MyClass(16);
        System.out.println(t1.num + " " + t2.num);
    }
}