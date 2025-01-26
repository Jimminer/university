public class Engine{
    private int displacement;
    private int horsepower;

    public void operate(){
        System.out.println("The engine started operating");
    }

    public void move(){
        System.out.println("The engine makes power");
    }

    public void stop(){
        System.out.println("The engine stops");
    }


    public Engine(){}

    public Engine(int displacement, int horsepower){
        this.displacement = displacement;
        this.horsepower = horsepower;
    }

    
    public int getDisplacement(){
        return displacement;
    }

    public void setDisplacement(int displacement){
        this.displacement = displacement;
    }

    public int getHorsepower(){
        return horsepower;
    }

    public void setHorsepower(int horsepower){
        this.horsepower = horsepower;
    }


    public String toString() {
        return "displacement: " + displacement + ", horsepower: " + horsepower;
    }
}
