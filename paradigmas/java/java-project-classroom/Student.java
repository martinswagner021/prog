public class Student{
    private String name;
    int age;
    double grade;

    public Student(String name, int age, double grade){
        this.name = name;
        this.age = age;
        this.grade = setGrade(grade);
    }

    private double setGrade(double g){
        return g <= 10 || g >= 0 ? g : 0;
    }

    public String getName() {
        return name;
    }
    public double getGrade() {
        return grade;
    }
    public int getAge() {
        return age;
    }
}