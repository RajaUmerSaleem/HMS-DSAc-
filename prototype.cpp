//#include <iostream>
//using namespace std;
//#include <iostream>
//#include <string>
//using namespace std;
//
//// Patient Class
//class Patient {
//private:
//    int patientID;
//    string name;
//    int age;
//    string gender;
//    string diseaseDescription;
//    int assignedDoctorID;
//    int roomID;
//
//public:
//    void addPatientDetails();
//    void updatePatientDetails();
//    void viewPatientDetails();
//    void assignDoctor(int doctorID);
//    void assignRoom(int roomID);
//};
//
//// Doctor Class
//class Doctor {
//private:
//    int doctorID;
//    string name;
//    string specialization;
//    string department;
//    string availability;
//
//public:
//    void addDoctorDetails();
//    void updateDoctorDetails();
//    void viewDoctorDetails();
//    void checkAppointments();
//};
//
//// Appointment Class
//class Appointment {
//private:
//    int appointmentID;
//    int patientID;
//    int doctorID;
//    string appointmentDate;
//    string appointmentTime;
//    string status;
//
//public:
//    void scheduleAppointment(int patientID, int doctorID, string date, string time);
//    void cancelAppointment(int appointmentID);
//    void viewAppointmentDetails();
//};
//
//// Department Class
//class Department {
//private:
//    int departmentID;
//    string departmentName;
//    int numberOfDoctors;
//
//public:
//    void addDepartment();
//    void updateDepartment();
//    void viewDepartmentDetails();
//};
//
//// Hospital Class
//class Hospital {
//private:
//    string hospitalName;
//    string location;
//    int totalDepartments;
//
//public:
//    void addHospitalDetails();
//    void manageHospitalData();
//};
//
//// Billing Class
//class Billing {
//private:
//    int billID;
//    int patientID;
//    double totalAmount;
//    string paymentStatus;
//    string paymentDate;
//
//public:
//    void generateBill(int patientID, double amount);
//    void updatePaymentStatus(int billID, string status);
//    void viewBillDetails(int patientID);
//};
//
//// Admin Class
//class Admin {
//private:
//    int adminID;
//    string username;
//    string password;
//
//public:
//    void login(string username, string password);
//    void addDoctor();
//    void addPatient();
//    void addDepartment();
//    void generateReports();
//};
//// Room Class
//class Room {
//private:
//    int roomID;
//    string roomType; // e.g., "Single", "Shared"
//    bool isAvailable;  // true if the room is free
//    int occupiedByPatientID; // stores patient ID if room is occupied
//
//public:
//    void assignRoom(int patientID) {
//        occupiedByPatientID = patientID;
//        isAvailable = false;
//    }
//
//    void releaseRoom() {
//        occupiedByPatientID = -1;
//        isAvailable = true;
//    }
//
//    void viewRoomDetails() {
//        cout << "Room ID: " << roomID << "\n";
//        cout << "Room Type: " << roomType << "\n";
//        cout << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
//    }
//};
//
//// Staff Class
//class Staff {
//private:
//    int staffID;
//    string name;
//    string role;  // e.g., "Nurse", "Technician"
//    string department;
//
//public:
//    void addStaffDetails() {
//        cout << "Enter Staff Name: ";
//        cin >> name;
//        cout << "Enter Role: ";
//        cin >> role;
//        cout << "Enter Department: ";
//        cin >> department;
//    }
//
//    void viewStaffDetails() {
//        cout << "Staff Name: " << name << "\n";
//        cout << "Role: " << role << "\n";
//        cout << "Department: " << department << "\n";
//    }
//
//    void assignStaffToDepartment(string dept) {
//        department = dept;
//    }
//};
//
//// Medicine Class
//class Medicine {
//private:
//    int medicineID;
//    string medicineName;
//    double price;
//    string dosage;
//
//public:
//    void addMedicine() {
//        cout << "Enter Medicine Name: ";
//        cin >> medicineName;
//        cout << "Enter Price: ";
//        cin >> price;
//        cout << "Enter Dosage: ";
//        cin >> dosage;
//    }
//
//    void viewMedicineDetails() {
//        cout << "Medicine Name: " << medicineName << "\n";
//        cout << "Price: " << price << "\n";
//        cout << "Dosage: " << dosage << "\n";
//    }
//
//    void prescribeMedicine(int patientID, string dosage) {
//        cout << "Prescribed " << medicineName << " to Patient ID: " << patientID << " with dosage: " << dosage << "\n";
//    }
//};
//// Inventory Class
//class Inventory {
//private:
//    int inventoryID;
//    string itemName;
//    int quantityAvailable;
//
//public:
//    void addItemToInventory() {
//        cout << "Enter Item Name: ";
//        cin >> itemName;
//        cout << "Enter Quantity: ";
//        cin >> quantityAvailable;
//    }
//
//    void updateInventory() {
//        cout << "Enter new quantity for " << itemName << ": ";
//        cin >> quantityAvailable;
//    }
//
//    void viewInventoryDetails() {
//        cout << "Item: " << itemName << "\n";
//        cout << "Quantity Available: " << quantityAvailable << "\n";
//    }
//};
//
//// Updating the Billing Class for detailed charges
//class Billing {
//private:
//    int billID;
//    int patientID;
//    double totalAmount;
//    string paymentStatus;
//    string paymentDate;
//
//public:
//    void generateBill(int patientID, double amount) {
//        this->patientID = patientID;
//        this->totalAmount = amount;
//        cout << "Bill generated for Patient ID: " << patientID << " with total amount: " << totalAmount << "\n";
//    }
//
//    void updatePaymentStatus(int billID, string status) {
//        this->billID = billID;
//        this->paymentStatus = status;
//        cout << "Payment status updated to: " << paymentStatus << "\n";
//    }
//
//    void viewBillDetails(int patientID) {
//        cout << "Bill ID: " << billID << "\n";
//        cout << "Patient ID: " << patientID << "\n";
//        cout << "Amount: " << totalAmount << "\n";
//        cout << "Payment Status: " << paymentStatus << "\n";
//    }
//};
//
//// Admin Class for hospital management
//class Admin {
//private:
//    int adminID;
//    string username;
//    string password;
//
//public:
//    void login(string username, string password) {
//        this->username = username;
//        this->password = password;
//        cout << "Admin logged in: " << username << "\n";
//    }
//
//    void addDoctor() {
//        // Add a doctor
//    }
//
//    void addPatient() {
//        // Add a patient
//    }
//
//    void addDepartment() {
//        // Add a department
//    }
//
//    void generateReports() {
//        // Generate hospital reports
//    }
//};
//
//// Main Function
//int main() {
//    // Example of using the system
//    cout << "Hospital Management System Initialized!" << endl;
//
//    // Create objects
//    Patient p1;
//    Doctor d1;
//    Room r1;
//    Billing b1;
//
//    // Sample usage
//    p1.addPatientDetails();
//    d1.addDoctorDetails();
//    r1.assignRoom(101);  // Assign room 101 to patient with ID 101
//    b1.generateBill(101, 5000.75);  // Generate a bill for patient ID 101
//
//    return 0;
//}
