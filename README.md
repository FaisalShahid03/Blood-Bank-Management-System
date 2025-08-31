# Blood Bank Management System  

## 📌 Project Overview  
The **Blood Bank Management System** is a C++-based Object-Oriented Programming (OOP) project designed to manage the reservation, storage, and transportation of blood for hospitals and medical research. It ensures real-time inventory tracking, donor/receiver management, hospital requests, and emergency response, ultimately improving coordination and healthcare delivery.  

---

## 👨‍💻 Group Members  
- **Sajeel Tariq (CTAI-028)**  
- **Faraz Ahmed (CTAI-029)**  
- **Faisal Shahid (CTAI-011)**  
- **Hunaiza Khan (CTAI-007)**  

**Course Instructor:** Miss Samia  

---

## 🎯 Objectives  
- Manage **blood inventory** efficiently.  
- Track **patients’ blood requirements** and **available reserves**.  
- Handle **emergency blood requests** from nearby hospitals.  
- Ensure **secure login and registration** using password encryption.  
- Improve **coordination between blood banks and hospitals**.  

---

## 🚀 Features  

### 🔑 Login & Registration  
- Secure **password encryption & decryption** for all users.  
- Verification checks for valid usernames & passwords.  

### 👨‍💼 Admin  
- Search, view, and delete user records.  
- Manage and view **blood inventory** in real-time.  

### 🧑 Citizen  
- Register with personal & health details.  
- Can be either:  
  - **Receiver** → Request 1–5 blood packets, with checks on the last received date.  
  - **Donor** → Donate if health criteria are met & last donation was ≥56 days ago.  

### 🏥 Hospital  
- Authenticate and set hospital location.  
- Request 1–10 blood packets.  
- Emergency handling: connects to the **nearest blood bank branch**.  

---

## 🛠️ System Design  

- **Core Classes:**  
  - `User`, `Citizen`, `Donor`, `Receiver`, `Hospital`, `Admin`  
  - `Records`, `Verification`, `BloodReserves`  
- **Key Functionalities:**  
  - Blood packet management.  
  - Exception handling for invalid inputs.  
  - Location-based hospital emergency handling.  

---

## 📷 Sample Outputs  
- Main Menu  
- Admin Menu  
- Citizen Menu (Receiver & Donor)  
- Hospital Menu  
- End Page  

---

## ✅ Conclusion  
The Blood Bank Management System provides an **efficient, user-friendly, and secure** platform for managing blood reserves. It helps tackle the growing issue of blood shortages by improving **resource allocation, emergency response, and healthcare delivery**.  

The system was **tested by peers and seniors**, receiving **positive feedback** for its functionality and usability.  

---

## ⚙️ Tech Stack  
- **Language:** C++  
- **Concepts Used:** OOP (Inheritance, Encapsulation, Polymorphism, Exception Handling, Templates)  
- **Data Handling:** File-based storage  
