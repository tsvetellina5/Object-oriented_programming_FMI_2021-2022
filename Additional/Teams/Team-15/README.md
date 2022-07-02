# Rent House
The project has the goal to help a new rent house to manage its operations. 
The program can track info for customers, vechiles and rents. 
The user can add vehicles and customer, rent a vehicle to a customer, print data
for different things and much more. With an easy to use interface everyone can open there
own vehicle rent house.

We have the following classes to help us:
## Vehicles (abstract class)
- Brand
- Model
- License plate
- Year of production
- Number of seats
- Gearbox which can be Manual or Auto
- Type of the engine which can be Diesel, Petrol and Electric
- We have 3 types of vehicles - Car, Motorcycle and Bus

## Car 
- Inherited properties from class Vehicle 
- Is it sports car (true/false)
- Is it convertable (true/false)

## Bus 
- Inherited properties from class Vehicle 
- Rating of the bus 
- Does it have AC (true/false)

## Motorcycle
- Inherited properties from class Vehicle 
- Does it have a sidecar (true/false)
- Does it have extra storage space (true/false)

## Customer
- Name
- Email address
- EGN
- City
- Phone number
- Username
- Password

## Rent
- EGN of the person (customer can rent multiple vehicles) 
- Licese Plate (a vehicle can be rented by only 1 customer)
- Date rented
- Date to return ( with the needed validations)

## Rent House
- List of all vehicles in store
- List of all signed customers
- List of all current rents
- Functionalities:
  - Add vehicle
  - Add customer
  - Delete vehicle
  - Delete customer

  - Print all vehicles
  - Print all customers
  - Print all rents
  - Print vehicles by brand
  - Print rents by start date 
  - Print rents by end date 
  - Print all cars which can be rented

  - Add rent with a customer and vehicle
  - Remove rent
  - Increase rental time
  - Change the owner of the rent

The program will save all the data into a file (***data.txt***) which with 
every start of the app will be loaded with the current data.

## UML diagram

This diagram will help you visualize the relationships between the classes in the application

![alt text](https://github.com/n0tn1w/RentHouse/blob/master/Rent_House_UML.png?raw=true)

## Menu 

A quick guild how to use our program

(***Type only the first letter or number***)

1. Add
- a. Customer
- b. Vehicle
2. Print
- a. All customers
- b. All vehicles
- c. All rents
- d. Cars by model
- e. Rents by start date
- f. Rents by end date
- g. All free cars
3. Rent 
- a. Rent a vehicle
- b. Extend rent
- c. Change owner
- d. End rent
4. Delete
- a. Customer
- b. Vehicle
5. Quit (and save into file)