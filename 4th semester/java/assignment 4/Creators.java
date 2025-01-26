import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;

public class Creators {
    public static ArrayList <Department> departments = new ArrayList <Department> ();
    public static ArrayList <Student> students = new ArrayList <Student> ();
    public static ArrayList <Graduate> graduates = new ArrayList <Graduate> ();
    public static ArrayList <Employee> employees = new ArrayList <Employee> ();
    public static ArrayList <Professor> professors = new ArrayList <Professor> ();




    public static void createDepartment(Scanner input){
        System.out.println("--------------------------");
        System.out.println("Creating department:\n");
        Department department = new Department();

        System.out.print("Name: ");
        department.setName(input.nextLine());
        System.out.print("\n");

        System.out.print("Address: ");
        department.setAddress(input.nextLine());
        System.out.print("\n");

        System.out.print("Phone: ");
        department.setPhone(input.nextLine());
        System.out.print("\n");

        System.out.print("Employee Count: ");
        department.setEmployeeCount(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Student Count: ");
        department.setStudentCount(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        departments.add(department);
    }




    public static void createStudent(Scanner input){
        System.out.println("--------------------------");
        System.out.println("Creating student:\n");
        Student student = new Student();

        System.out.print("Student Number: ");
        student.setStudentNumber(input.nextLine());
        System.out.print("\n");
        
        System.out.print("First Name: ");
        student.setFirstName(input.nextLine());
        System.out.print("\n");

        System.out.print("Last Name: ");
        student.setLastName(input.nextLine());
        System.out.print("\n");

        System.out.print("Age: ");
        student.setAge(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Address: ");
        student.setAddress(input.nextLine());
        System.out.print("\n");

        System.out.print("Department (name): ");
        String depName = input.nextLine();
        for (Department dep : departments){
            if (dep.getName().equals(depName)){
                student.setDepartment(dep);
                break;
            }
        }
        if (student.getDepartment() == null){
            student.setDepartment(departments.get(0));
        }
        System.out.print("\n");

        System.out.print("Enroll Year: ");
        student.setEnrollYear(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.println("Course Grades: ");
        HashMap <String, Double> courseGrades = new HashMap <String, Double> ();
        while (true){
            System.out.print("\tCourse Name: ");
            String course = input.nextLine();
            System.out.print("\n");

            System.out.print("\tGrade: ");
            courseGrades.put(course, input.nextDouble());
            input.nextLine();
            System.out.print("\n");

            System.out.print("\tAdd another course grade? (y/N): ");
            if (!input.nextLine().toLowerCase().equals("y")){
                System.out.print("\n");
                student.setCourseGrades(courseGrades);
                break;
            }
            System.out.print("\n");
        }

        students.add(student);
    }




    public static void createGraduate(Scanner input){
        System.out.println("--------------------------");
        System.out.println("Creating graduate student:\n");
        Graduate graduate = new Graduate();

        System.out.print("Student Number: ");
        graduate.setStudentNumber(input.nextLine());
        System.out.print("\n");
        
        System.out.print("First Name: ");
        graduate.setFirstName(input.nextLine());
        System.out.print("\n");

        System.out.print("Last Name: ");
        graduate.setLastName(input.nextLine());
        System.out.print("\n");

        System.out.print("Age: ");
        graduate.setAge(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Address: ");
        graduate.setAddress(input.nextLine());
        System.out.print("\n");

        System.out.print("Department (name): ");
        String depName = input.nextLine();
        for (Department dep : departments){
            if (dep.getName().equals(depName)){
                graduate.setDepartment(dep);
                break;
            }
        }
        if (graduate.getDepartment() == null){
            graduate.setDepartment(departments.get(0));
        }
        System.out.print("\n");

        System.out.print("Enroll Year: ");
        graduate.setEnrollYear(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.println("Course Grades: ");
        HashMap <String, Double> courseGrades = new HashMap <String, Double> ();
        while (true){
            System.out.print("\tCourse Name: ");
            String course = input.nextLine();
            System.out.print("\n");

            System.out.print("\tGrade: ");
            courseGrades.put(course, input.nextDouble());
            input.nextLine();
            System.out.print("\n");

            System.out.print("\tAdd another course grade? (y/N): ");
            if (!input.nextLine().toLowerCase().equals("y")){
                System.out.print("\n");
                graduate.setCourseGrades(courseGrades);
                break;
            }
            System.out.print("\n");
        }

        System.out.print("Degree Title: ");
        graduate.setDegreeTitle(input.nextLine());
        System.out.print("\n");

        System.out.print("Degree Grade: ");
        graduate.setDegreeGrade(input.nextDouble());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Supervisor (last name): ");
        String profName = input.nextLine();
        for (Professor prof : professors){
            if (prof.getLastName().equals(profName)){
                graduate.setSupervisor(prof);
                break;
            }
        }
        if (graduate.getSupervisor() == null){
            graduate.setSupervisor(professors.get(0));
        }
        System.out.print("\n");

        System.out.print("Thesis Title: ");
        graduate.setThesisTitle(input.nextLine());
        System.out.print("\n");

        graduates.add(graduate);
    }



    
    public static void createEmployee(Scanner input){
        System.out.println("--------------------------");
        System.out.println("Creating Employee:\n");
        Employee employee = new Employee();

        System.out.print("SSN: ");
        employee.setSsn(input.nextLine());
        System.out.print("\n");
        
        System.out.print("First Name: ");
        employee.setFirstName(input.nextLine());
        System.out.print("\n");

        System.out.print("Last Name: ");
        employee.setLastName(input.nextLine());
        System.out.print("\n");

        System.out.print("Age: ");
        employee.setAge(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Address: ");
        employee.setAddress(input.nextLine());
        System.out.print("\n");

        System.out.print("Department (name): ");
        String depName = input.nextLine();
        for (Department dep : departments){
            if (dep.getName().equals(depName)){
                employee.setDepartment(dep);
                break;
            }
        }
        if (employee.getDepartment() == null){
            employee.setDepartment(departments.get(0));
        }
        System.out.print("\n");

        System.out.print("Salary: ");
        employee.setSalary(input.nextDouble());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Specialty: ");
        employee.setSpecialty(input.nextLine());
        System.out.print("\n");

        System.out.print("Duty Years: ");
        employee.setDutyYears(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        employees.add(employee);
    }




    public static void createProfessor(Scanner input){
        System.out.println("--------------------------");
        System.out.println("Creating Professor:\n");
        Professor professor = new Professor();

        System.out.print("SSN: ");
        professor.setSsn(input.nextLine());
        System.out.print("\n");
        
        System.out.print("First Name: ");
        professor.setFirstName(input.nextLine());
        System.out.print("\n");

        System.out.print("Last Name: ");
        professor.setLastName(input.nextLine());
        System.out.print("\n");

        System.out.print("Age: ");
        professor.setAge(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Address: ");
        professor.setAddress(input.nextLine());
        System.out.print("\n");

        System.out.print("Department (name): ");
        String depName = input.nextLine();
        for (Department dep : departments){
            if (dep.getName().equals(depName)){
                professor.setDepartment(dep);
                break;
            }
        }
        if (professor.getDepartment() == null){
            professor.setDepartment(departments.get(0));
        }
        System.out.print("\n");

        System.out.print("Salary: ");
        professor.setSalary(input.nextDouble());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Specialty: ");
        professor.setSpecialty(input.nextLine());
        System.out.print("\n");

        System.out.print("Duty Years: ");
        professor.setDutyYears(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Rank: ");
        professor.setRank(input.nextLine());
        System.out.print("\n");

        System.out.print("Doctorate Duration: ");
        professor.setDoctorateDuration(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Post Count: ");
        professor.setPostCount(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.print("Masters Supervising: ");
        professor.setMastersSupervising(input.nextInt());
        input.nextLine();
        System.out.print("\n");

        System.out.println("Courses: ");
        ArrayList <String> courses = new ArrayList <String> ();
        while (true){
            System.out.print("\tCourse Name: ");
            courses.add(input.nextLine());
            System.out.print("\n");

            System.out.print("\tAdd another course? (y/N): ");
            if (!input.nextLine().toLowerCase().equals("y")){
                System.out.print("\n");
                professor.setCourses(courses);
                break;
            }
            System.out.print("\n");
        }

        professors.add(professor);
    }
}