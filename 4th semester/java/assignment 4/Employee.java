public class Employee extends Person {
    private String ssn;
    private double salary;
    private String specialty;
    private int dutyYears;


    public Employee() {}


    public Employee(String firstName, String lastName, int age, String address, Department department, String ssn, double salary, String specialty, int dutyYears) {
        super(firstName, lastName, age, address, department);
        this.ssn = ssn;
        this.salary = salary;
        this.specialty = specialty;
        this.dutyYears = dutyYears;
    }


    public String getSsn() {
        return ssn;
    }

    public void setSsn(String ssn) {
        this.ssn = ssn;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getSpecialty() {
        return specialty;
    }

    public void setSpecialty(String specialty) {
        this.specialty = specialty;
    }

    public int getDutyYears() {
        return dutyYears;
    }

    public void setDutyYears(int dutyYears) {
        this.dutyYears = dutyYears;
    }


    @Override
    public String toString() {
        return super.toString() + " " + "Employee [ssn=" + ssn + ", salary=" + salary + ", specialty=" + specialty + ", dutyYears=" + dutyYears
                + "]";
    }
}