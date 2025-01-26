import java.util.HashMap;

public class Graduate extends Student {
    private String degreeTitle;
    private double degreeGrade;
    private Professor supervisor;
    private String thesisTitle;


    public Graduate() {}

    public Graduate(String firstName, String lastName, int age, String address, Department department, String studentNumber, int enrollYear, HashMap <String, Double> courseGrades, double avgGrade, String degreeTitle, double degreeGrade, Professor supervisor, String thesisTitle) {
        super(firstName, lastName, age, address, department, studentNumber, enrollYear, courseGrades, avgGrade);
        this.degreeTitle = degreeTitle;
        this.degreeGrade = degreeGrade;
        this.supervisor = supervisor;
        this.thesisTitle = thesisTitle;
    }


    public String getDegreeTitle() {
        return degreeTitle;
    }

    public void setDegreeTitle(String degreeTitle) {
        this.degreeTitle = degreeTitle;
    }

    public double getDegreeGrade() {
        return degreeGrade;
    }

    public void setDegreeGrade(double degreeGrade) {
        this.degreeGrade = degreeGrade;
    }

    public Professor getSupervisor() {
        return supervisor;
    }

    public void setSupervisor(Professor supervisor) {
        this.supervisor = supervisor;
    }

    public String getThesisTitle() {
        return thesisTitle;
    }

    public void setThesisTitle(String thesisTitle) {
        this.thesisTitle = thesisTitle;
    }

    @Override
    public String toString() {
        return super.toString() + " " + "Graduate [degreeTitle=" + degreeTitle + ", degreeGrade=" + degreeGrade + ", supervisor=" + supervisor
                + ", thesisTitle=" + thesisTitle + "]";
    }
}