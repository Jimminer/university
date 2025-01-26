import java.util.HashMap;

public class Student extends Person {
    private String studentNumber;
    private int enrollYear;
    private HashMap <String, Double> courseGrades;
    private double avgGrade;


    public Student() {}

    public Student(String firstName, String lastName, int age, String address, Department department, String studentNumber, int enrollYear, HashMap <String, Double> courseGrades, double avgGrade) {
        super(firstName, lastName, age, address, department);
        this.studentNumber = studentNumber;
        this.enrollYear = enrollYear;
        this.courseGrades = courseGrades;
        this.avgGrade = avgGrade;
    }


    public String getStudentNumber() {
        return studentNumber;
    }

    public void setStudentNumber(String studentNumber) {
        this.studentNumber = studentNumber;
    }

    public int getEnrollYear() {
        return enrollYear;
    }

    public void setEnrollYear(int enrollYear) {
        this.enrollYear = enrollYear;
    }

    public HashMap<String, Double> getCourseGrades() {
        return courseGrades;
    }

    public void setCourseGrades(HashMap<String, Double> courseGrades) {
        this.courseGrades = courseGrades;
    }

    public double getAvgGrade() {
        double sum = 0;
        int count = 0;

        for (double grade : courseGrades.values()){
            sum += grade;
            count++;
        }

        avgGrade = sum/count;

        return avgGrade;
    }

    public void setAvgGrade(double avgGrade) {
        this.avgGrade = avgGrade;
    }

    @Override
    public String toString() {
        return super.toString() + " " + "Student [studentNumber=" + studentNumber + ", enrollYear=" + enrollYear + ", courseGrades="
                + courseGrades + ", avgGrade=" + avgGrade + "]";
    }
}