import java.util.Scanner;

class Cars{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        double petrolPrice = 1.873;
        double petrolUsage = 6.3;

        double km;
        double totalDistance = 0;
        double largestDistance = -1;


        while(true){
            System.out.print("Please input the car's distance (in km): ");
            km = input.nextInt();

            if (km < 0) continue;
            if (km == 0) break;

            totalDistance += km;
            if (km > largestDistance) largestDistance = km;

            System.out.println("Petrol cost (in euros): " + km/100*petrolUsage*petrolPrice + "\n");
        }


        System.out.println("\n\n -- Info --");
        System.out.println("Total distance travelled was: " + totalDistance);
        System.out.println("Total petrol consumption (in litres): " + totalDistance/100*petrolUsage);
        System.out.println("Largest distance among all cars was: " + largestDistance);

        input.close();
    }
}