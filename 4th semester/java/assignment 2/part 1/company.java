import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;



public class company {
    private String companyName;
    private ArrayList <product> products;
    private Map<String,Integer> productNames = new HashMap<String,Integer>();
    private Map<String,Integer> productCodes = new HashMap<String,Integer>();

    public company(){

    }

    public company(String companyName, ArrayList <product> products, Map<String,Integer> productNames, Map<String,Integer> productCodes){
        this.companyName = companyName;
        this.products = products;
        this.productNames = productNames;
        this.productCodes = productCodes;
    }

    public int getNumOfProducts(){
        return products.size();
    }

    public String getCompanyName(){
        return companyName;
    }

    public void setCompanyName(String companyName){
        this.companyName = companyName;
    }

    public ArrayList <product> getProducts(){
        return products;
    }

    public void setProducts(ArrayList <product> products){
        this.products = products;
    }

    public String toString(){
        return companyName+", "+products.toString();
    }

    public Map<String, Integer> getProductNames() {
        return productNames;
    }

    public Map<String, Integer> getProductCodes() {
        return productCodes;
    }

    public void setProductNames(Map<String, Integer> productNames) {
        this.productNames = productNames;
    }

    public void setProductCodes(Map<String, Integer> productCodes) {
        this.productCodes = productCodes;
    }

}
