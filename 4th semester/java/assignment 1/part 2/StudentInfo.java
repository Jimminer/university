import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student{
    private int id;
    private String name;
    private String department;
    private int age;
    private String [] courses;
    private Double [] grades;
    
    
    public Student(){}

    public Student(int id, String name, String department, int age, String[] courses, Double[] grades) {
        this.id = id;
        this.name = name;
        this.department = department;
        this.age = age;
        this.courses = courses;
        this.grades = grades;
    }

    static public String getStudentName(int id){
        for (Student temp : StudentInfo.studentList){
            if (temp.id != id) continue;

            return temp.name;
        }
        return "Not Found";
    }

    static public double getLargestGrade(int id){
        double largestGrade = -1;

        for (Student temp : StudentInfo.studentList){
            if (temp.id != id) continue;

            for (double grade : temp.grades){
                if (grade > largestGrade) largestGrade = grade;
            }
            break;
        }

        return largestGrade;
    }

    static public double getGradeAverage(int id){
        double totalGrades = 0;
        int gradeCount = 0;

        for (Student temp : StudentInfo.studentList){
            if (temp.id != id) continue;

            for (double grade : temp.grades){
                totalGrades += grade;
                gradeCount++;
            }
            break;
        }

        return totalGrades/(double)gradeCount;
    }

    static public double getGradeAverage(String name){
        double totalGrades = 0;
        int gradeCount = 0;

        for (Student temp : StudentInfo.studentList){
            if (temp.name != name) continue;

            for (double grade : temp.grades){
                totalGrades += grade;
                gradeCount++;
            }
            break;
        }

        return totalGrades/(double)gradeCount;
    }

    static public void getStudentInfo(int id, String name){
        for (Student temp : StudentInfo.studentList){
            if (temp.id != id || temp.name != name) continue;

            System.out.println("\nStudent Info:");
            System.out.printf("id: %d\nname: %s\ndepartment: %s\nage: %d\n", temp.id, temp.name, temp.department, temp.age);
            System.out.println("courses: " + Arrays.toString(temp.courses));
            System.out.println("grades: " + Arrays.toString(temp.grades));
            break;
        }
    }

    static public void getCompletedCourses(int id){
        List<String> courseList = new ArrayList<String>();
        List<Double> gradeList = new ArrayList<Double>();
        int index;

        for (Student temp : StudentInfo.studentList){
            if (temp.id != id) continue;

            for (int i=0; i<temp.courses.length; i++){
                for (index=0; index<courseList.size(); index++){
                    if (temp.grades[i] > gradeList.get(index)) break;
                }

                courseList.add(index, temp.courses[i]);
                gradeList.add(index, temp.grades[i]);
            }
            break;
        }

        for (int i=0; i<courseList.size(); i++){
            System.out.println(courseList.get(i) + ": " + gradeList.get(i));
        }
    }

    public String toString() {
        return String.format("Student [ id = %d, name = %s, department = %s, age = %d, courses = %s, grades = %s ]", id, name, department, age, Arrays.toString(courses), Arrays.toString(grades));
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String[] getCourses() {
        return courses;
    }

    public void setCourses(String[] courses) {
        this.courses = courses;
    }

    public Double[] getGrades() {
        return grades;
    }

    public void setGrades(Double[] grades) {
        this.grades = grades;
    }
}



public class StudentInfo {
    public static List<Student> studentList = new ArrayList<Student>();
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        boolean idExists = false;

        int studentsAdded = 0;

        int id;
        String name;
        String department;
        int age;
        List<String> coursesArrayList = new ArrayList<String>();
        List<Double> gradesArrayList = new ArrayList<Double>();
        
        String tempCourse;
        double tempGrade;
        
        while (studentsAdded < 2){
            idExists = false;

            System.out.println("Create a student:\n");
            System.out.print("\nPlease input the student's id: ");
            id = input.nextInt();
            input.nextLine();
            
            if (id < 0) continue;

            for (Student temp : studentList){
                if (temp.getId() == id){
                    System.out.println("That id is already used. Please input another id.");
                    idExists = true;
                    break;
                }
            }

            if (idExists) continue;
            
            System.out.print("\nPlease input the student's name: ");
            name = input.nextLine();
            
            System.out.print("\nPlease input the student's department: ");
            department = input.nextLine();
            
            System.out.print("\nPlease input the student's age: ");
            age = input.nextInt();
            input.nextLine();
            
            System.out.print("\nPlease input courses with their grades\nThe format should be \"GRADE COURSE\"\nInput a negative number to stop adding courses\n");
            while (true){
                tempGrade = input.nextDouble();
                
                if (tempGrade < 0) break;
                
                tempCourse = input.nextLine().trim();
                
                coursesArrayList.add(tempCourse);
                gradesArrayList.add(tempGrade);
            }
            
            String [] courses = new String[coursesArrayList.size()];
            Double [] grades = new Double[gradesArrayList.size()];
            coursesArrayList.toArray(courses);
            gradesArrayList.toArray(grades);
            coursesArrayList.clear();
            gradesArrayList.clear();

            createStudent(id, name, department, age, courses, grades);

            studentsAdded++;

            System.out.println("-------------------------------------------------------");
        }


        while (true){
            System.out.print("\nPlease input an id of a student: ");
            id = input.nextInt();

            if (id < 0) break;

            System.out.println("\n\n" + id + "'s largest grade: " + Student.getLargestGrade(id));
            System.out.println("\n" + id + "'s average grade: " + Student.getGradeAverage(id) + "\n");
            System.out.println(id + "'s completed courses:");
            Student.getCompletedCourses(id);
            Student.getStudentInfo(id, Student.getStudentName(id));

            System.out.println("-------------------------------------------------------");
        }

        input.close();
    }

    public static Student createStudent(int id, String name, String department, int age, String[] courses, Double[] grades){
        Student newStudent = new Student(id, name, department, age, courses, grades);
        studentList.add(newStudent);
        return newStudent;
    }
}