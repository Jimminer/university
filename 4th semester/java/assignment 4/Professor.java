import java.util.ArrayList;

public class Professor extends Employee {
    private String rank;
    private int doctorateDuration;
    private int postCount;
    private int mastersSupervising;
    private ArrayList <String> courses;


    public Professor() {}

    public Professor(String firstName, String lastName, int age, String address, Department department, String ssn, double salary, String specialty, int dutyYears, String rank, int doctorateDuration, int postCount, int mastersSupervising, ArrayList<String> courses) {
        super(firstName, lastName, age, address, department, ssn, salary, specialty, dutyYears);
        this.rank = rank;
        this.doctorateDuration = doctorateDuration;
        this.postCount = postCount;
        this.mastersSupervising = mastersSupervising;
        this.courses = courses;
    }


    public String getRank() {
        return rank;
    }

    public void setRank(String rank) {
        this.rank = rank;
    }

    public int getDoctorateDuration() {
        return doctorateDuration;
    }

    public void setDoctorateDuration(int doctorateDuration) {
        this.doctorateDuration = doctorateDuration;
    }

    public int getPostCount() {
        return postCount;
    }

    public void setPostCount(int postCount) {
        this.postCount = postCount;
    }

    public int getMastersSupervising() {
        return mastersSupervising;
    }

    public void setMastersSupervising(int mastersSupervising) {
        this.mastersSupervising = mastersSupervising;
    }

    public ArrayList<String> getCourses() {
        return courses;
    }

    public void setCourses(ArrayList<String> courses) {
        this.courses = courses;
    }

    @Override
    public String toString() {
        return super.toString() + " " + "Professor [rank=" + rank + ", doctorateDuration=" + doctorateDuration + ", postCount=" + postCount
                + ", mastersSupervising=" + mastersSupervising + ", courses=" + courses + "]";
    }
}