/**
 * Gas Mileage - program2
 */
import java.util.Scanner;
import java.util.Date;

 public class program2 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        Date currentdate = new Date();
        

        System.out.println("Enter how many miles you have driven from your trip: ");
        float miles = input.nextFloat();

        System.out.println("Enter how many gallons you had filled up: ");
        float gallons = input.nextFloat();

        double mpg = miles / gallons;

        System.out.printf("Your gas mileage is: %f \n", mpg);
        System.out.println("Thank you for using the Gas Mileage application. Date and time of calculation is " + currentdate);

    }
    
}


// Programmer Name: Austin De La Cruz
// Assignment Start: 5:30 PM
// Assignment Completion: 7:15 PM
// Total hours for assignment: 1 hour 45 min
// Comments: This assignment was a little bit confusing but was able to execute.