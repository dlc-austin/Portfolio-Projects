import java.util.Scanner;

public class program1 {
    public static void main(String[] args) {
    

        Scanner input = new Scanner(System.in); 
        double PI = 3.14159;

        System.out.println("Enter radius of circle: ");
        int radius = input.nextInt();

        int diameter = 2 * radius;
        double circumference = 2 * PI * radius;
        double area = PI * radius * radius;

        System.out.printf("The area of the circle is: %f. \n", area);
        System.out.printf("The diameter of the circle is: %d. \n", diameter);
        System.out.printf("The circumference of the circle is: %f. \n", circumference);
        System.exit(0);

        // Programer Name: Austin De La Cruz
        // Assignment Start: 4:10 PM
        // Assignment Completion: 6:50 PM
        // Total Hours for Assignment: 2 hours and 40 min.
        // Comments: This was fun for a first coding assignment.


    }
    
}
