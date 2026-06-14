// 1. Driver Class
class Driver {
    private String name;
    private double rating;
    private String vehicleType;
    private boolean isAvailable;

    public Driver(String name, double rating, String vehicleType, boolean isAvailable) {
        this.name = name;
        this.rating = rating;
        this.vehicleType = vehicleType;
        this.isAvailable = isAvailable;
    }

    // Getters and Setters (Encapsulation)
    public String getName() { return name; }
    public double getRating() { return rating; }
    public String getVehicleType() { return vehicleType; }
    public boolean isAvailable() { return isAvailable; }
    public void setAvailable(boolean available) { this.isAvailable = available; }
}

// 2. Passenger Class
class Passenger {
    private String name;
    private double walletBalance;

    public Passenger(String name, double walletBalance) {
        this.name = name;
        this.walletBalance = walletBalance;
    }

    // Getters and Setters (Encapsulation)
    public String getName() { return name; }
    public double getWalletBalance() { return walletBalance; }
    public void deductBalance(double amount) { this.walletBalance -= amount; }
}

// 3. Ride System Class (Handles Booking and Overloading)
class RideSystem {
    
    // Method Overloading - Type 1: Default Car Booking
    public void bookRide(Passenger passenger, Driver driver, String destination) {
        bookRide(passenger, driver, destination, "Car"); // Calls the second method with default "Car"
    }

    // Method Overloading - Type 2: Custom Vehicle Booking
    public void bookRide(Passenger passenger, Driver driver, String destination, String requestedVehicle) {
        System.out.println("\n--- Processing Ride Request for " + passenger.getName() + " to " + destination + " ---");
        
        // Step 1: Check Driver Availability
        if (!driver.isAvailable()) {
            System.out.println("Booking Failed: Driver " + driver.getName() + " is currently busy or offline.");
            return;
        }

        // Step 2: Check Minimum Wallet Balance Requirement (Rs. 250)
        if (passenger.getWalletBalance() < 250) {
            System.out.println("Booking Failed: Insufficient funds. Minimum Rs. 250 required to request a ride.");
            return;
        }

        // Step 3: Check if driver's vehicle matches passenger's choice
        if (!driver.getVehicleType().equalsIgnoreCase(requestedVehicle)) {
            System.out.println("Booking Failed: Requested vehicle (" + requestedVehicle + ") does not match Driver's vehicle (" + driver.getVehicleType() + ").");
            return;
        }

        // Step 4: Calculate Fare
        double fare = calculateFare(requestedVehicle);
        
        // Step 5: Final Balance Check against actual fare
        if (passenger.getWalletBalance() < fare) {
            System.out.println("Booking Failed: Your wallet balance (Rs. " + passenger.getWalletBalance() + ") is less than the calculated fare (Rs. " + fare + ").");
            return;
        }

        // Step 6: Successful Booking & Updates
        passenger.deductBalance(fare);
        driver.setAvailable(false); // Driver is now busy

        System.out.println("Ride Confirmed Success fully!");
        System.out.println("Driver " + driver.getName() + " (" + driver.getRating() + "⭐) is on the way in a " + driver.getVehicleType() + ".");
        System.out.println("Total Fare: Rs. " + fare);
        System.out.println("Remaining Wallet Balance: Rs. " + passenger.getWalletBalance());
    }

    // Helper method to calculate fare based on vehicle type
    private double calculateFare(String vehicleType) {
        switch (vehicleType.toLowerCase()) {
            case "bike": return 150.0;
            case "car": return 300.0;
            case "ac-car": return 500.0;
            default: return 300.0; // Default fallback
        }
    }
}

// 4. Main Class to run simulation
public class Main {
    public static void main(String[] args) {
        // Creating objects
        Driver driver1 = new Driver("Ali", 4.8, "AC-Car", true);
        Passenger passenger1 = new Passenger("Zain", 600.0); // Has enough balance
        Passenger passenger2 = new Passenger("Sara", 200.0); // Low balance

        RideSystem uber = new RideSystem();

        // Scenario 1: Sara tries to book (Will fail due to minimum balance rule < 250)
        uber.bookRide(passenger2, driver1, "Mall of Lahore");

        // Scenario 2: Zain tries to book an "AC-Car" (Will succeed)
        uber.bookRide(passenger1, driver1, "DHA Phase 6", "AC-Car");

        // Scenario 3: Someone else tries to book Ali again (Will fail because Ali is now busy)
        Passenger passenger3 = new Passenger("Hamza", 1000.0);
        uber.bookRide(passenger3, driver1, "Airport", "AC-Car");
    }
}
