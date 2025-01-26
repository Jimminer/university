import java.util.Scanner;


public class product{
    private double price;
    private String name;
    private String code;
    public product(){
        
    }
    public product(double price, String name, String code){
        this.price = price;
        this.name = name;
        this.code = code;
    }
    public double getPrice(){
        return price;
    }
    public String getName(){
        return name;
    }
    public String getCode(){
        return code;
    }
    public void setPrice(double newPrice) {
        this.price = newPrice;    
    }
    public void setName(String newName) {
        this.name = newName;    
    }   
    public void setCode(String newCode){
        this.code = newCode;
    }
    public String toString(){
        return name+", "+price+", "+code;
    }
    public boolean compare(product p){
        return this.price > p.price;
    }

    public boolean readProduct(Scanner scan){

        System.out.print("Please enter product name (\"exit\" to stop): ");
        this.name = scan.nextLine();
        if(this.name.equals("exit")) return false;
        System.out.print("\n");




        System.out.print("Please enter product price: ");
        while(true){
            try{
                this.price = Double.parseDouble(scan.nextLine());
            }
            catch(NumberFormatException e){
            }
            
            if(this.price > 0) break;
            
            System.out.print("Please enter a positive number: ");
        }
        System.out.print("\n");
        



        System.out.print("Please enter product code: ");
        while(true){
            this.code = scan.nextLine();

            if(this.code.matches("[0-9]{2}[a-zA-Z]{6}")) break;

            System.out.print("Please enter a code that matches this syntax NNCCCCCC (N = number, C = character): ");
            
        }
        System.out.print("\n");


        return true;
    }
        
}