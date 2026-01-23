#include <iostream>
#include <vector>
#include<string>
using namespace std;

const string ROLE_STUDENT = "STUDENT";
const string ROLE_PROVIDER = "PROVIDER";
const string ROLE_ADMIN = "ADMIN";

class Student
{
    string id;
    string name;
    string phone;
    string email;
    vector<string> preferences;
    string emergencyContact;
    string collegeName;
    string parentsName;
    string parentsPhone;
    string semStartDate;
    string semEndDate;
    int yearOfStudy;
    int graduationYear;
    double maxBudget;
    bool isVerified = false;
    string stream;
    string subscriptionPlan;
    string password;

public:
    Student(string id, string name, string phone, string email, vector<string> preferences, string emergencyContact, string collegeName, string parentsName, string parentsPhone, string semStartDate, string semEndDate, int yearOfStudy, int graduationYear, double maxBudget, bool isVerified, string stream, string subscriptionPlan, string password)
    {

        this->id = id;
        this->name = name;
        this->phone = phone;
        this->email = email;
        this->preferences = preferences;
        this->collegeName = collegeName;
        this->emergencyContact = emergencyContact;
        this->parentsName = parentsName;
        this->parentsPhone = parentsPhone;
        this->semStartDate = semStartDate;
        this->semEndDate = semEndDate;
        this->yearOfStudy = yearOfStudy;
        this->graduationYear = graduationYear;
        this->maxBudget = maxBudget;
        this->isVerified = isVerified;
        this->stream = stream;
        this->subscriptionPlan = subscriptionPlan;
        this->password = password;
    }

    bool getIsVerified() {
        return isVerified; 
    }

    string getSubscriptionPlan() { 
        return subscriptionPlan; 
    }

    string getStudentPassword() {
        return password;
    }

    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Preferences: ";
        for (auto &pref : preferences)
        {
            cout << pref << ", ";
        }
        cout << endl;
        cout << "Emergency Contact: " << emergencyContact << endl;
        cout << "College Name: " << collegeName << endl;
        cout << "Parents Name: " << parentsName << endl;
        cout << "Parents Phone: " << parentsPhone << endl;
        cout << "Semester Start Date: " << semStartDate << endl;
        cout << "Semester End Date: " << semEndDate << endl;
        cout << "Year of Study: " << yearOfStudy << endl;
        cout << "Graduation Year: " << graduationYear << endl;
        cout << "Max Budget: " << maxBudget << endl;
        cout << "Is Verified: " << (isVerified ? "Yes" : "No") << endl;
        cout << "Stream: " << stream << endl;
        cout << "Subscription Plan: " << subscriptionPlan << endl;
    }

    string getStudentID(){
        return id;
    }

    string getStudentName(){
        return name;
    }
};

class Provider
{
    string id;
    string name;
    string email;
    string phone;
    bool isVerified;
    bool isKYC;
    vector<string> serviceType;
    string serviceName;
    string pan;
    string gstin;
    string address;
    string landmark;
    string city;
    string state;
    string pinCode;
    vector<string> amenities;
    bool isSubscribed = true;
    int totalListings = 0;
    int totalBookings = 0;
    vector<string> bankDetails;
    string password;

public:
    Provider(string id, string name, string email, string phone, bool isVerified, bool isKYC,
             vector<string> serviceType, string serviceName, string pan, string gstin,
             string address, string landmark, string city, string state, string pinCode,
             vector<string> amenities, bool isSubscribed,
             int totalListings, int totalBookings, vector<string> bankDetails, string password)
    {

        this->id = id;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->isVerified = isVerified;
        this->isKYC = isKYC;
        this->serviceType = serviceType;
        this->serviceName = serviceName;
        this->pan = pan;
        this->gstin = gstin;
        this->address = address;
        this->landmark = landmark;
        this->city = city;
        this->state = state;
        this->pinCode = pinCode;
        this->amenities = amenities;
        this->isSubscribed = isSubscribed;
        this->totalListings = totalListings;
        this->totalBookings = totalBookings;
        this->bankDetails = bankDetails;
        this->password = password;
    }

    bool getIsVerified() { 
        return isVerified; 
    }

    bool getIsKYC() {
         return isKYC;
         }

    bool getIsSubscribed() { 
        return isSubscribed; 
    }

    string getServiceName() {
         return serviceName; 
        }

    string getProviderPassword(){
        return password;
    }

    void display()
    {

        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "Is Verified: " << (isVerified ? "Yes" : "No") << endl;
        cout << "Is KYC: " << (isKYC ? "Yes" : "No") << endl;
        cout << "Service Type: ";
        for (auto &type : serviceType)
        {
            cout << type << ", ";
        }
        cout << endl;
        cout << "Service Name: " << serviceName << endl;
        cout << "PAN: " << pan << endl;
        cout << "GSTIN: " << gstin << endl;
        cout << "Address: " << address << endl;
        cout << "Landmark: " << landmark << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "Pin Code: " << pinCode << endl;
        cout << "Amenities: ";
        for (auto &amenity : amenities)
        {
            cout << amenity << ", ";
        }
        cout << endl;
        cout << "Is Subscribed: " << (isSubscribed ? "Yes" : "No") << endl;
        cout << "Total Listings: " << totalListings << endl;
        cout << "Total Bookings: " << totalBookings << endl;
        cout << "Bank Details: ";
        for (auto &detail : bankDetails)
        {
            cout << detail << ", ";
        }
        cout << endl;
    }

    string getProviderID(){
        return id;
    }

    string getProviderName(){
        return name;
    }
};

class Admin {
    vector<Student> students;
    vector<Provider> providers;

    string id = "AD001";
    string password = "PASS123";

public:
    void addStudent(Student s) {
        students.push_back(s);
    }

    void addProvider(Provider p) {
        providers.push_back(p);
    }

    void checkStudentAccess(Student &s) {

        cout<<"ID: "<<s.getStudentID()<<" Name: "<<s.getStudentName();

        if (s.getIsVerified() && s.getSubscriptionPlan() != "free") {
            cout << " Student access granted. Available services: ";
            for (auto &p : providers) {
                if (p.getIsVerified() && p.getIsKYC() && p.getIsSubscribed()) {
                    cout << p.getServiceName() << ", ";
                }
            }
            cout << endl;
        } else {
            cout << " Student access denied. Verification or subscription required." << endl;
        }
    }

    void checkProviderAccess(Provider &p) {

        cout<<"ID: "<<p.getProviderID()<<" Name: "<<p.getProviderName();

        if (p.getIsVerified() && p.getIsKYC() && p.getIsSubscribed()) {
            cout << " Provider verified. Services listed: " << p.getServiceName() << endl;
        } else {
            cout << " Provider not verified. Check verification, KYC, and subscription." << endl;
        }
    }

    void displayAllStudents() {
        cout << "All Students:" << endl;
        for (auto &s : students) {
            s.display();
            //cout<<"ID: "<<s.getID()<<" Name:"<<s.getName();
            cout << endl;
        }
    }

    void displayAllProviders() {
        cout << "All Providers:" << endl;
        for (auto &p : providers) {
            p.display();
            cout << endl;
        }
    }

    void countOfStudents(){
        
        cout<<"Count of all Students: ";
        cout<<students.size();
        cout<<endl;
    }

    void countOfProviders(){
        
        cout<<"Count of all Providers: ";
        cout<<providers.size();
        cout<<endl;
    }

    vector<Student>& getStudents() {
        return students;
    }

    vector<Provider>& getProviders() {
        return providers;
    }

    string getAdminID(){
        return id;
    }

    string getAdminPassword(){
        return password;
    }

    bool deleteStudentByID(string &studentID) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getStudentID() == studentID) {
                students.erase(it);   
                cout << "Student deleted successfully \n";
                return true;
            }
        }
        cout << "Student not found\n";
        return false;
    }

    bool deleteProviderByID(string &providerID){
        for (auto it = providers.begin(); it != providers.end(); ++it) {
        if (it->getProviderID() == providerID) {
            providers.erase(it);
            cout << "Provider deleted successfully\n";
            return true;
            }
        }
        cout << "Provider not found \n";
        return false;
    }
 
};

class AuthToken {
    string token;

    public:
        AuthToken(string userId, string role) {
            token = userId + "|" + role;
        }

        string getToken() {
            return token;
        }

        string getUserId() {
            return token.substr(0, token.find("|"));
        }

        string getRole() {
            return token.substr(token.find("|") + 1);
        }
};


class System{

    Admin &admin;

    AuthToken* currentToken = nullptr;

    void studentLogin() {
        string id, password;
        cout << "\nStudent Login\n";
        cout << "ID: ";
        cin >> id;
        cout << "\nPassword: ";
        cin >> password;

        for (auto &s : admin.getStudents()) {
            if (s.getStudentID() == id && s.getStudentPassword() == password) {
                cout << "\nWelcome " << s.getStudentName() << "...!";
                // admin.checkStudentAccess(s);
                currentToken = new AuthToken(s.getStudentID(), ROLE_STUDENT);
                cout << "\nJWT issued for Student\n";
                admin.checkStudentAccess(s);

                return;
            }
        }
        cout << "\nInvalid student credentials....!"<<endl;
}


    void providerLogin(){
        string id, password;

        cout<<"\nProvider Login"<<endl;

        cout<<"Enter your ID: ";
        cin>>id;

        cout<<"\nEnter your password: ";
        cin>>password;

        for(auto&p: admin.getProviders()){
            if(p.getProviderID()==id && p.getProviderPassword()==password){
                cout<<"\nWelcome " <<p.getProviderName()<<"...!";
                //admin.checkProviderAccess(p);
                currentToken = new AuthToken(p.getProviderID(), ROLE_PROVIDER);
                cout << "\nJWT issued for Provider\n";
                admin.checkProviderAccess(p);

                return;
            }
        }

        cout<<"\n Invalid Provider Credentials.....!"<<endl;
    }

    void adminLogin(){

        string id, password;

        cout<<"\nAdmin Login"<<endl;

        cout<<"Enter your ID: ";
        cin>>id;

        cout<<"\nEnter your password: ";
        cin>>password;

        if(id == admin.getAdminID() && password == admin.getAdminPassword()){
            cout<<"\nWelcome Admin....!";

           currentToken = new AuthToken(admin.getAdminID(), ROLE_ADMIN);
            cout << "\nJWT issued for Admin\n";
            adminDashboard();

        }
        else{
            cout<<"Invalid Credentials.....!";
        }

    }

    void adminDashboard() {

    if (!currentToken || currentToken->getRole() != ROLE_ADMIN) {
    cout << "Unauthorized access\n";
    return;
    }

    int choice;
    string id;
    do {
        cout << "\nADMIN DASHBOARD\n";
        cout << "1. Show all students\n";
        cout << "2. Show all providers\n";
        cout << "3. Count students\n";
        cout << "4. Count providers\n";
        cout << "5. Delete Student\n";
        cout << "6. Delete Provider\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            admin.displayAllStudents();
            break;
        case 2:
            admin.displayAllProviders();
            break;
        case 3:
            admin.countOfStudents();
            break;
        case 4:
            admin.countOfProviders();
            break;
        case 5:
            cout<<"Enter Student ID to delete: ";
            cin>>id;
            admin.deleteStudentByID(id);
            break;
        case 6:
            cout<<"Enter Provider ID to delete: ";
            cin>>id;
            admin.deleteProviderByID(id);
            break;
        case 0:
            delete currentToken;
            currentToken = nullptr;
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid option....!\n";
        }
    } while (choice != 0);
}

public:
    System(Admin &a) : admin(a) {}

    void start() {
        int choice;
        do{
        cout << "\nWELCOME TO SYSTEM\n";
        cout << "1. Student Login\n";
        cout << "2. Provider Login\n";
        cout << "3. Admin Login\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            studentLogin();
            break;
        case 2:
            providerLogin();
            break;
        case 3:
            adminLogin();
            break;
        case 0:
            cout << "Exiting system \n Thank you for using our system"<<endl;
            break;
        default:
            cout << "Invalid choice"<<endl;
        }
    }while(choice!=0);
    }

};

class Bookings {
    string bookingID;
    string studentID;
    string providerID;
    string serviceName;
    string status;

public:
    Bookings(string bid, string sid, string pid, string service){
        bookingID = bid;
        studentID = sid;
        providerID = pid;
        serviceName = service;
    }
        
    string getBookingID(){ 
        return bookingID; 
    }

    string getStudentID(){ 
        return studentID; 
    }

    string getProviderID(){ 
        return providerID; 
    }

    string getServiceName(){ 
        return serviceName; 
    }

    string getStatus(){ 
        return status; 
    }

    void cancel() {
        status = "CANCELLED";
    }

    void createBookings(string ){

    }
};


int main()
{
    //student
    vector<string> prefs = {"Hostel", "Near College", "Veg food", "Hot Water", "Filter Water Supply", "Cot Basis Room"};

    Student s1("S001", "Omkumar", "1234567890", "om@promaxsys.in", prefs, "9874561230", "TKIET College", "Kumar", "0987654321", "2023-08-01", "2024-05-31", 4, 2026, 15000.0, true, "Computer Science", "Silver", "OK123");

    Student s2("S002", "Rahul", "5421218540", "rahul@123.com", {"Room", "Non-veg", "Hot water"}, "894131313486", "TKIET College", "Omkumar", "8946661313", "2023-08-01", "2024-05-31", 4, 2026, 25000.0, true, "Computer Science", "Gold", "RA456");

    //provider
    vector<string> serviceTypes = {"Accommodation", "Mess"};
    vector<string> amenities = {"WiFi", "Parking", "Hot Water", "Filtered RO Water", "Electricity Bill included", "Spacious Rooms"};
    vector<string> bankDetails = {"Bank of Maharashtra", "Account No: 123456", "IFSC: ABC123"};

    Provider p1("P001", "Master", "provider@hostel.com", "1234567890", true, true, serviceTypes, "Kumar PG & Mess", "PAN123", "GSTIN123", "Kalamba Road", "Next To DY Patil College", "Kolhapur", "Maharashtra", "416009", amenities, true, 5, 10, bankDetails, "PROV123");

    Provider p2("P002", "Shinde", "shinde@Foods.com", "8451311265", true, true, {"Mess"}, "Shinde Mess", "PAN456", "GSTIN456", "Kalamba Road", "Behind Promaxsys Office", "Kolhapur", "Maharashtra", "416009", {"Home like food", "Fresh and Hygienic", "Veg/Non-veg"}, true, 1, 0, {"SBI", "Account No: 84651313466", "IFSC: SBI543131"}, "PROV456");

    // admin
    Admin a;
    a.addStudent(s1);
    a.addStudent(s2);
    a.addProvider(p1);
    a.addProvider(p2);
    
    // cout << "Checking student access:" << endl;
    // a.checkStudentAccess(s1);
    // a.checkStudentAccess(s2);

    // cout << "Checking provider access:" << endl;
    // a.checkProviderAccess(p1);
    // a.checkProviderAccess(p2);

    // cout << endl;
    // a.displayAllStudents();
    // a.displayAllProviders();
    // a.countOfStudents();
    // a.countOfProviders();

    System system(a);
    system.start();

    return 0;
}