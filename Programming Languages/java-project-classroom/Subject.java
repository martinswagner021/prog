import java.util.ArrayList;

public class Subject{
    String title;
    ArrayList<Student> subscripted;

    public Subject(String title){
        this.title = title;
    }
    public void addStudent(Student std){
        this.subscripted.add(std);
    }
    public String getTitle() {
        return title;
    }
    public ArrayList<Student> getSubscripted() {
        return subscripted;
    }
}