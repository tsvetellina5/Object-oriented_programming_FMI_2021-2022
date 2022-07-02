# FMI-Project 
Програма, която моделира система на хотел.

![image](https://user-images.githubusercontent.com/93201913/173634014-2905b47f-8d9f-4f92-a852-dd787b73e0b4.png)

## клас Hotel
 name – име на хотела.  
 address – адрес на хотела.  
 customers – списък от посетители.  
 reservations – списък от резервации.  
 log – списък от всички извършени посещения.  
	Функционалности:  
 addVisitor- добавя посетител.  
 deleteVisitor - изтрива посетител.  
 addReservation – създава нова резервация от съответния тип и я добавя към списъка с резервации.  
 listVisitors – извежда списък с потребителите.  
 listReservations – извежда информация за всички налични резервации.  
 listVisitorData – извежда информация на конкретен потребител.  
 exportVisitors – запазвала текушия списък от посетители във файл.  
 display – извежда информация за хотела и колко посетители имa.  

## клас Visitor (посетител)  
Visitor (посетител)  
 id- идентификатор на потребителя  
 име на посетителя  
 резервация  

## клас Резервация- Абстрактен клас  
	Тип на резервацията  
	Престой (брой дни)  
	Номер на стая  
	Брой легла  
	Цена за престоя  
	Функционалности:  
	display (извежда информация за резервацията)  
	goToRestaurant (връща true или false, в зависимост от това, дали типа на резервация на съответния посетител, позволява той да яде в ресторанта)  
	goToBar (връща true или false, в зависимост от това, дали типа на резервация на съответния посетител, позволява той да консумира алкохол)  

## клас AI (all inclusive)  
Класът AI наследява Reservation, като го допълва с:  
•	paidBar (булева променлива, която по подразбиране е false)  
и реализира методите:  
	display- за извеждане на информация за резервацията– тип на резервация, престой, номер на стая, идентификатор на притежателя й, цена за престоя, брой легла.  
	payToBar(променя стойността на paidBar на true)  
	goToRestaurant (връща винаги true)  
	goToBar(връща стойността на paidBar)   

## клас	UAI (ultra all inclusive)  
Класът UAI наследява Reservation и реализира методите:  
	display-за извеждане на информация за резервацията.  
	goToRestaurant (връща винаги true)  
	goToBar (връща винаги true)  

## клас	NO (nights only)  
Класът NO наследява Reservation, като го допълва с:  
•	paidBar (булева променлива, която по подразбиране е false)  
•	paidRestaurant (булева променлива, която по подразбиране е false)  
и реализира методите:  
	display-за извеждане на информация за резервацията.  
	goToRestaurant (връща стойността на paidRestaurant)  
	goToBar (връща стойността на paidBar)  

Тестово меню:  
1.  Edit  
a. Visitor  
    i. Add new visitor  
    ii. Delete visitor  
b. Reservation  
     i. Add new reservation  
     ii. Delete reservation  
2.  List  
      a. List all visitors  
      b. List all reservations  
      c. List visitor reservation  
3.   Save to file  
4.	Display info for the hotel  
5.	Action  
a. Pay to bar  
b. Pay to restaurant  
6.	Quit  

