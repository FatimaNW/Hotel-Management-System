# 🏨 Hotel Management System

A console-based Hotel Management System developed in C++ using Object-Oriented Programming (OOP) principles. 

## 💡 Features

- Room booking and availability check  
- Guest record management  
- Hotel service reservation
- Password-protected admin access
- Bill generation with service breakdown  
- Guest feedback and rating system  
- File handling for storing guest data and feedback  

## 🛠️ Tech Stack

- **Language:** C++  
- **Paradigm:** Object-Oriented Programming (Uses classes, inheritance, encapsulation, and polymorphism)
- **Environment:** Console-based  

## ▶️ How to Use

1. **Requirements:** You need to have a C++ compiler installed on your system to run this project.
2. **Compile and Run:** Open `Hotel_Management_System.cpp` in your IDE or terminal, compile it, and run the executable.
3. **Using the System:** After running the program, choose whether to continue as a Guest or log in as Admin using the credentials.

## 🧭 Program Navigation

### 1. 🔐 Admin Menu:
To access admin functionalities, enter the credentials:
- **Username**: `user`  
- **Password**: `password`
  
Once logged in, you can:
1. **View Available Rooms** – See which rooms are currently unbooked. 
2. **Add Rooms** – Add new rooms to the hotel’s inventory.
3. **Customer Record** – View all guest booking records.
4. **View Customer Feedback** – View guest ratings and comments.
5. **Exit**

### 2. 👤 Guest Menu:
No login is required. You can:
1. **Book a Room** – Enter your details and select a room to reserve.
2. **Check Room Availability** – View which rooms are currently free.
3. **Book a Service** – Choose from room service, gym, spa, or WiFi.
4. **Check Out** – Check out of your room.
5. **Generate Bill** – View your total charges and pay the bill.
6. **Give Feedback** – Rate your experience and leave a comment.
7. **Exit**

## 📄 File Outputs

These files are automatically created/updated when guest details or feedback are entered:
- `Hotel_Customers.txt`: Stores guest records including room details and personal information.
- `Hotel_Feedback.txt`: Stores feedback and ratings given by guests.
