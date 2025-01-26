public class Department {
    private String name;
    private String address;
    private String phone;
    private int studentCount;
    private int employeeCount;


    public Department() {}

    public Department(String name, String address, String phone, int studentCount, int employeeCount) {
        this.name = name;
        this.address = address;
        this.phone = phone;
        this.studentCount = studentCount;
        this.employeeCount = employeeCount;
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public int getStudentCount() {
        return studentCount;
    }

    public void setStudentCount(int studentCount) {
        this.studentCount = studentCount;
    }

    public int getEmployeeCount() {
        return employeeCount;
    }

    public void setEmployeeCount(int employeeCount) {
        this.employeeCount = employeeCount;
    }

    @Override
    public String toString() {
        return "Department [name=" + name + ", address=" + address + ", phone=" + phone + ", studentCount="
                + studentCount + ", employeeCount=" + employeeCount + "]";
    }
}