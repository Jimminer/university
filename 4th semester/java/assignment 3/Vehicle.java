public class Vehicle{
    private String owner;
    private String licensePlate;
    private int year;
    private ControlSystem controlSystem;
    private Engine engine;


    public Vehicle(){}

    public Vehicle(String owner, String licensePlate, int year, ControlSystem controlSystem, Engine engine){
        this.owner = owner;
        this.licensePlate = licensePlate;
        this.year = year;
        this.controlSystem = controlSystem;
        this.engine = engine;
    }


    public String getOwner(){
        return owner;
    }

    public void setOwner(String owner){
        this.owner = owner;
    }

    public String getLicensePlate(){
        return licensePlate;
    }

    public void setLicensePlate(String licensePlate){
        this.licensePlate = licensePlate;
    }

    public int getYear(){
        return year;
    }

    public void setYear(int year){
        this.year = year;
    }

    public ControlSystem getControlSystem(){
        return controlSystem;
    }

    public void setControlSystem(ControlSystem controlSystem){
        this.controlSystem = controlSystem;
    }

    public Engine getEngine(){
        return engine;
    }
    
    public void setEngine(Engine engine){
        this.engine = engine;
    }


    public String toString() {
        return "owner:" + owner + ", licensePlate:" + licensePlate + ", year:" + year + ", engine: [" + engine + "]";
    }
}
