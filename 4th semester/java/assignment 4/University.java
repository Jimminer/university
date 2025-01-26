import java.util.Scanner;

public class University {
    
    private static double getAvgGradePerYear(int year){
        double sum = 0;
        int count = 0;

        for (Student student : Creators.students){
            if (student.getEnrollYear() == year){
                sum += student.getAvgGrade();
                count++;
            }
        }

        for (Graduate graduate : Creators.graduates){
            if (graduate.getEnrollYear() == year){
                sum += graduate.getAvgGrade();
                count++;
            }
        }

        return sum/count;
    }

    private static double getAvgPostCountPerDep(String depName){
        double sum = 0;
        int count = 0;

        for (Department dep : Creators.departments){
            if (dep.getName().equals(depName)){
                for (Professor prof : Creators.professors){
                    sum += prof.getPostCount();
                    count++;
                }

                break;
            }
        }

        return sum/count;
    }


    private static Student findStudent(String studentNumber){
        for (Student stu : Creators.students){
            if (stu.getStudentNumber().equals(studentNumber)){
                return stu;
            }
        }

        return null;
    }

    private static Person findPerson(String lastName){
        for (Student stu : Creators.students){
            if (stu.getLastName().equals(lastName)){
                return stu;
            }
        }

        for (Graduate grad : Creators.graduates){
            if (grad.getLastName().equals(lastName)){
                return grad;
            }
        }

        for (Employee emp : Creators.employees){
            if (emp.getLastName().equals(lastName)){
                return emp;
            }
        }

        for (Professor prof : Creators.professors){
            if (prof.getLastName().equals(lastName)){
                return prof;
            }
        }

        return null;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Creators.createDepartment(input);
        Creators.createProfessor(input);
        Creators.createProfessor(input);
        Creators.createStudent(input);
        Creators.createStudent(input);
        Creators.createGraduate(input);
        Creators.createGraduate(input);

        Creators.createDepartment(input);
        Creators.createProfessor(input);
        Creators.createProfessor(input);
        Creators.createStudent(input);
        Creators.createStudent(input);
        Creators.createGraduate(input);
        Creators.createGraduate(input);

        while (true){
            System.out.print("\n");
            System.out.println("Please choose an option: ");
            System.out.println("\t1: Get average student grade by year");
            System.out.println("\t2: Get average professor post count by department");
            System.out.println("\t3: Find student/graduate by student number");
            System.out.println("\t4: Find person by last name");
            
            System.out.print("Choice: ");
            int choice = input.nextInt();
            input.nextLine();
            System.out.print("\n");


            switch(choice){
                case 1:
                    System.out.print("Input the year: ");
                    int year = input.nextInt();
                    input.nextLine();
                    System.out.print("\n");
                    System.out.println("Average student grade for year " + year + " is: " + getAvgGradePerYear(year));
                    break;
                
                case 2:
                    System.out.print("Input the department's name: ");
                    String depName = input.nextLine();
                    System.out.print("\n");
                    System.out.println("Average professor post count for department " + depName + " is: " + getAvgPostCountPerDep(depName));
                    break;
                
                case 3:
                    System.out.print("Input the student's number: ");
                    String stuNumber = input.nextLine();
                    System.out.print("\n");
                    System.out.println(findStudent(stuNumber));
                    break;

                case 4:
                    System.out.print("Input the person's last name: ");
                    String lastName = input.nextLine();
                    System.out.print("\n");
                    System.out.println(findPerson(lastName));
                    break;
                
                default:
                    System.out.println("You chose an invalid option!");
            }

            System.out.print("Choose again? (y/N): ");
            if (!input.nextLine().toLowerCase().equals("y")){
                break;
            }
        }
    }
}