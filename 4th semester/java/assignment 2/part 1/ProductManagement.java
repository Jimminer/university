import java.util.Scanner;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class ProductManagement {
    
    static ArrayList <company> companies;
    static ArrayList <product> products;
    static String compName;
    static product NewProduct;
    static company NewCompany;
    static Map<String,Integer> productNames;
    static Map<String,Integer> productCodes;
    
    

    public void search(){

    }


    public static void main(String[] args){
        Scanner Scan = new Scanner(System.in);
        
        companies = new ArrayList <company>();
        while(true){
            products = new ArrayList <product>();
            productNames = new HashMap<String,Integer>();
            productCodes = new HashMap<String,Integer>();

            System.out.print("\nPlease input a company name (\"exit\" to stop): ");
            compName = Scan.nextLine();
            System.out.print("\n");

            if (compName.equals("exit")){
                break;
            }
            while(true){
                NewProduct = new product();
                if(!NewProduct.readProduct(Scan)){
                    break;
                }
                if(productNames.containsKey(NewProduct.getName()) || productCodes.containsKey(NewProduct.getCode())){
                    continue;
                }
                products.add(NewProduct);
                productNames.put(NewProduct.getName(), 0);
                productCodes.put(NewProduct.getCode(), 0);
            }
            NewCompany = new company(compName, products, productNames, productCodes);
            companies.add(NewCompany);
        }


        for (company comp : companies){
            System.out.println(comp.getCompanyName() + " has " + comp.getNumOfProducts() + " products");
        }

        for (company comp : companies){
            double biggestPrice = 0;
            int productIndex = 0;
            for (int i = 0; i<comp.getNumOfProducts(); i++){
                if (comp.getProducts().get(i).getPrice() > biggestPrice){
                    biggestPrice = comp.getProducts().get(i).getPrice();
                    productIndex = i;
                }
            }
            System.out.println("Most expensive product of " + comp.getCompanyName() + " is " + comp.getProducts().get(productIndex).getName() + " with a price of " + comp.getProducts().get(productIndex).getPrice());
        }

        while(true){
            System.out.print("\nTo search for a product enter a name (\"quit\" to exit): ");
            String pName = Scan.nextLine();
            System.out.print("\n");
            if (pName.equals("quit")) break;

            for (company comp : companies){
                for (product prod : comp.getProducts()){
                    if(prod.getName().equals(pName))
                        System.out.println(comp.getCompanyName() + ": " + prod);
                }
            }
        }
        Scan.close();
    }
}
