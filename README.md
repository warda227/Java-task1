# Java-task1

## Scenario: Smart Ride-Hailing System (Taxi Service)
You are required to design the core backend logic for a **Smart Ride-Hailing Application** (similar to Uber or InDrive). The system consists of three main components: **Driver**, **Passenger**, and the **Ride System**.
### 1. Requirements & Core Logic
Write a Java program that strictly implements the following operational rules:
 * **Driver Class:** Every driver must have a name, a rating (out of 5.0), and a vehicleType (e.g., "Bike", "Car", "AC-Car"). Drivers must also have a status flag isAvailable (true/false) that can be toggled.
 * **Passenger Class:** Every passenger must have a name and a walletBalance (funds available to pay for rides).
 * **Ride Allocation Logic:** Whenever a passenger requests a ride, the system must validate the following conditions:
   1. Is the selected driver currently available?
   2. Does the passenger have the mandatory minimum wallet balance of **Rs. 250** to even initiate a request?
 * **Fare Calculation:** The fixed base fare is determined strictly by the type of vehicle requested:
   * Bike: Rs. 150
   * Car: Rs. 300
   * AC-Car: Rs. 500
### 2. Task Breakdown & Implementation Details
Your code must demonstrate key Object-Oriented Programming (OOP) concepts:
 1. **Encapsulation:** All data fields (attributes) in the classes must be declared private. Access to and modification of these fields must be handled exclusively through public **getters** and **setters**.
 2. **Method Overloading:** Implement two versions of the booking method within your system:
   * bookRide(String destination): Automatically books a standard **Car** by default.
   * bookRide(String destination, String vehicleType): Books the specific vehicle type chosen by the user.
 3. **Simulation:** Create a Main class to simulate real-world testing scenarios:
   * Instantiate sample Driver and Passenger objects.
   * Trigger ride requests to test successful bookings (where the wallet balance is successfully deducted and driver availability turns false).
   * Trigger edge cases to test failures (e.g., insufficient funds or trying to book an already busy driver).
