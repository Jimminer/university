import java.util.Scanner;
import java.util.ArrayList;
import java.util.Map;
import java.util.AbstractMap;
import java.util.HashMap;
import java.util.Collections;

public class Transport{
    private static String tempOwner;
    private static String tempLicensePlate;
    private static int tempYear;
    private static int tempDisplacement;
    private static int tempHorsepower;
    private static Vehicle tempVehicle;
    private static HashMap <String, Vehicle> vehicles;

    public static void main(String[] args) {
        vehicles = new HashMap <String, Vehicle>();
        Scanner input = new Scanner(System.in);

        while(true){
            System.out.println("Please input the vehicle's specifications:\n");


            System.out.print("Owner's full name: ");
            tempOwner = input.nextLine();
            System.out.print("\n");

            System.out.print("License plate: ");
            tempLicensePlate = input.nextLine();
            System.out.print("\n");

            System.out.print("Year: ");
            tempYear = input.nextInt();
            input.nextLine();
            System.out.print("\n");

            System.out.print("Engine displacement (CC): ");
            tempDisplacement = input.nextInt();
            input.nextLine();
            System.out.print("\n");

            System.out.print("Engine horsepower: ");
            tempHorsepower = input.nextInt();
            input.nextLine();
            System.out.print("\n");


            tempVehicle = new Vehicle(tempOwner, tempLicensePlate, tempYear, new ControlSystem(), new Engine(tempDisplacement, tempHorsepower));
            vehicles.put(tempLicensePlate, tempVehicle);


            System.out.print("Do you want to input another vehicle? (y/n): ");
            String choice = input.nextLine();
            if (!choice.equals("y") && !choice.equals("Y")){
                break;
            }
            System.out.print("\n");
        }

        after:
        while(true){
            System.out.print("\n");
            System.out.println("Please choose an option: ");
            System.out.println("\t1: Get a vehicle's engine displacement based on license plate");
            System.out.println("\t2: Get a vehicle's engine horsepower based on year");
            System.out.println("\t3: Get a vehicle's owner and year based on license plate");
            System.out.println("\t4: Control a vehicle");
            System.out.println("\t5: Exit");
            System.out.print("Choice: ");

            int choice = input.nextInt();
            input.nextLine();
            System.out.print("\n");

            switch(choice){
                case 1:
                    System.out.print("Input the vehicle's license plate: ");
                    tempLicensePlate = input.nextLine();
                    System.out.print("\n");

                    if (!vehicles.containsKey(tempLicensePlate)){
                        System.out.println("A vehicle with the license plate " + tempLicensePlate + " does not exist!");
                        break;
                    }
                    tempVehicle = vehicles.get(tempLicensePlate);
                    System.out.println("Engine displacement of " + tempLicensePlate + " is: " + tempVehicle.getEngine().getDisplacement());
                    break;
                
                case 2:
                    System.out.print("Input the vehicle's year: ");
                    tempYear = input.nextInt();
                    input.nextLine();
                    System.out.print("\n");

                    ArrayList < Map.Entry <String, Integer> > horsepowerList = new ArrayList < Map.Entry <String, Integer> >();

                    for (Vehicle vehicle : vehicles.values()){
                        if (vehicle.getYear() != tempYear){
                            continue;
                        }

                        horsepowerList.add(new AbstractMap.SimpleEntry<>(vehicle.getLicensePlate(), vehicle.getEngine().getHorsepower()));
                    }

                    if (horsepowerList.size() == 0){
                        System.out.println("There are no vehicles from the year " + tempYear);
                        break;
                    }

                    horsepowerList.sort(Collections.reverseOrder(Map.Entry.comparingByValue()));
                    
                    System.out.println("There are " + horsepowerList.size() + " vehicles from the year " + tempYear + ":");
                    for (Map.Entry<String, Integer> vehicle : horsepowerList){
                        System.out.println(vehicle.getKey() + ": " + vehicle.getValue());
                    }
                    break;

                case 3:
                    System.out.print("Input the vehicle's license plate: ");
                    tempLicensePlate = input.nextLine();
                    System.out.print("\n");

                    if (!vehicles.containsKey(tempLicensePlate)){
                        System.out.println("A vehicle with the license plate " + tempLicensePlate + " does not exist!");
                        break;
                    }
                    tempVehicle = vehicles.get(tempLicensePlate);
                    System.out.println("Owner and year of " + tempLicensePlate + " is: " + tempVehicle.getOwner() + ", " + tempVehicle.getYear());
                    break;

                case 4:
                    System.out.print("Input the vehicle's license plate: ");
                    tempLicensePlate = input.nextLine();
                    System.out.print("\n");

                    if (!vehicles.containsKey(tempLicensePlate)){
                        System.out.println("A vehicle with the license plate " + tempLicensePlate + " does not exist!");
                        break;
                    }
                    tempVehicle = vehicles.get(tempLicensePlate);


                    System.out.print("\n");
                    System.out.println("Please choose an option: ");
                    System.out.println("\t1: Turn the car on");
                    System.out.println("\t2: Turn the car off");
                    System.out.println("\t3: Steer the car left");
                    System.out.println("\t4: Steer the car right");
                    System.out.println("\t5: Operate the engine");
                    System.out.println("\t6: Move the car");
                    System.out.println("\t7: Stop the engine");
                    System.out.print("Choice: ");
        
                    int methodChoice = input.nextInt();
                    input.nextLine();
                    System.out.print("\n");


                    switch(methodChoice){
                        case 1:
                            tempVehicle.getControlSystem().turnOn();
                            break;
                        
                        case 2:
                            tempVehicle.getControlSystem().turnOff();
                            break;
                        
                        case 3:
                            tempVehicle.getControlSystem().steerLeft();
                            break;

                        case 4:
                            tempVehicle.getControlSystem().steerRight();
                            break;
                        
                        case 5:
                            tempVehicle.getEngine().operate();
                            break;
                        
                        case 6:
                            tempVehicle.getEngine().move();
                            break;
                        
                        case 7:
                            tempVehicle.getEngine().stop();
                            break;
                        
                        default:
                            System.out.println("You chose an invalid option!");
                    }

                    break;
                
                case 5:
                    break after;
                
                default:
                    System.out.println("You chose an invalid option!");
                    continue;
            }
        }

        input.close();
    }
}
