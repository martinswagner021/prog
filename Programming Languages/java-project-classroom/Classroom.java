public class Classroom{
    public static void main(String args[]){
        Student wag = new Student("Wagner", 20, 9.5);
        Subject math = new Subject("Math");
        math.addStudent(wag);

        System.out.println(math.getSubscripted());
    }
}
