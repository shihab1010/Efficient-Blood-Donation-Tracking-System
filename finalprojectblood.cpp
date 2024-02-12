#include <iostream>
#include <vector>
#include<fstream>
using namespace std;
bool verifyUser(const string& username, const string& password) {
    ifstream userFile("user.txt");
    string line;

    while (getline(userFile, line)) {
        size_t pos = line.find('/');
        string user = line.substr(0, pos);
        string pass = line.substr(pos + 1);

        if (user == username && pass == password) {
            userFile.close();
            return true;
        }
    }

    userFile.close();
    return false;
}

enum bloodtype {A_POS, B_POS, AB_POS, O_POS, A_NEG, B_NEG, AB_NEG, O_NEG};
int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};

void collect(bloodtype choice)
{
    int* ptr = arr;
    switch (choice)
    {
    case A_POS:
        (*ptr)++;
        cout << "A+ added to bloodbank"<<endl<< endl;
        break;
    case B_POS:
        (*(ptr + 1))++;
        cout << "B+ added to bloodbank"<<endl<< endl;
        break;
    case AB_POS:
        (*(ptr + 2))++;
        cout << "AB+ added to bloodbank"<<endl<< endl;
        break;
    case O_POS:
        (*(ptr + 3))++;
        cout << "O+ added to bloodbank"<<endl<< endl;
        break;
    case A_NEG:
        (*(ptr + 4))++;
        cout << "A- added to bloodbank"<<endl<< endl;
        break;
    case B_NEG:
        (*(ptr + 5))++;
        cout << "B- added to bloodbank"<<endl<< endl;
        break;
    case AB_NEG:
        (*(ptr + 6))++;
        cout << "AB- added to bloodbank"<<endl<< endl;
        break;
    case O_NEG:
        (*(ptr + 7))++;
        cout << "O- added to bloodbank"<<endl<< endl;
        break;
    default:
        cout << "Invalid blood type"<<endl<< endl;
    }
}

void available(bloodtype choice)
{
    int* ptr = arr;
    switch (choice)
    {
    case A_POS:
        if(*(ptr) == 0)
            cout << "Required blood type not available" << endl << endl;
        else
            cout << *(ptr) << " bag(s) of A+ available" << endl << endl;
        break;
    case B_POS:
        if(*(ptr + 1) == 0)
            cout << "Required blood type not available" << endl << endl;
        else
            cout << *(ptr + 1) << " bag(s) of B+ available" << endl << endl;
        break;
    case AB_POS:
        if(*(ptr + 2) == 0)
            cout << "Required blood type not available" << endl << endl;
        else
            cout << *(ptr + 2) << " bag(s) of AB+ available" << endl << endl;
        break;
    case O_POS:
        if(*(ptr + 3) == 0)
            cout << "Required blood type not available " << endl << endl;
        else
            cout << *(ptr + 3) << " bag(s) of O+ available" << endl << endl;
        break;
    case A_NEG:
        if(*(ptr + 4) == 0)
            cout << "Required blood type not available " << endl << endl;
        else
            cout << *(ptr + 4) << " bag(s) of A- available" << endl << endl;
        break;
    case B_NEG:
        if(*(ptr + 5) == 0)
            cout << "Required blood type not available " << endl << endl;
        else
            cout << *(ptr + 5) << " bag(s) of B- available" << endl << endl;
        break;
    case AB_NEG:
        if(*(ptr + 6) == 0)
            cout << "Required blood type not available " << endl << endl;
        else
            cout << *(ptr + 6) << " bag(s) of AB- available" << endl << endl;
        break;
    case O_NEG:
        if(*(ptr + 7) == 0)
            cout << "Required blood type not available " << endl << endl;
        else
            cout << *(ptr + 7) << " bag(s) of O- available" << endl << endl;
        break;
    default:
        cout << "Invalid blood type"<<endl << endl;
    }
}

class User
{
public:
    string username;
    string password;
    User(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    string getuser()
    {
        return username;
    }

    string getpass()
    {
        return password;
    }

    virtual void displayinfo()
    {
        cout << "Username: " << username << endl << "Password: " << password << endl<<endl;
    }
};

class Patient : public User
{
public:
    string name;
    string phone;
    string add;
    int type;

    Patient(string username, string password, string name,int type, string phone, string add) : User(username, password)
    {
        this->name = name;
        this->phone = phone;
        this->add = add;
        this->type=type;
    }

    void displayinfo()
    {
        User::displayinfo();
        cout << "Name: " << name << endl;
        if(type==0)
        {
            cout<<"Blood group : A+"<<endl;
        }
        if(type==1)
        {
            cout<<"Blood group : B+"<<endl;
        }
        if(type==2)
        {
            cout<<"Blood group : AB+"<<endl;
        }
        if(type==3)
        {
            cout<<"Blood group : O+"<<endl;
        }
        if(type==4)
        {
            cout<<"Blood group : A-"<<endl;
        }
        if(type==5)
        {
            cout<<"Blood group : B-"<<endl;
        }
        if(type==6)
        {
            cout<<"Blood group : AB-"<<endl;
        }
        if(type==7)
        {
            cout<<"Blood group : O+"<<endl;
        }
        cout << "Phone: " << phone << endl << "Address: " << add << endl;
    }
};

class Donor : public User
{
public:
    string name;
    string phone;
    string add;
    string date;

    int type;

    Donor(string username, string password, string name, int type,string phone, string add, string date) : User(username, password)
    {
        this->name = name;
        this->phone = phone;
        this->add = add;
        this->date = date;
        this->type=type;
    }

    void displayinfo()
    {
        User::displayinfo();
        cout << "Name: " << name << endl;
        if(type==0)
        {
            cout<<"Blood group : A+"<<endl;
        }
        if(type==1)
        {
            cout<<"Blood group : B+"<<endl;
        }
        if(type==2)
        {
            cout<<"Blood group : AB+"<<endl;
        }
        if(type==3)
        {
            cout<<"Blood group : O+"<<endl;
        }
        if(type==4)
        {
            cout<<"Blood group : A-"<<endl;
        }
        if(type==5)
        {
            cout<<"Blood group : B-"<<endl;
        }
        if(type==6)
        {
            cout<<"Blood group : AB-"<<endl;
        }
        if(type==7)
        {
            cout<<"Blood group : O+"<<endl;
        }
        cout << "Phone: " << phone << endl << "Address: " << add << endl << "Date of donation: " << date << endl;
    }
};

class BloodDonationSystem
{
private:
    vector<User> users;
    vector<Donor> donors;
    vector<Patient> patients;

public:

    void reg(string username, string password)
    {
        users.push_back(User(username, password));
        cout<< "\nUSER REGISTRATION SUCCESSFUL!\n\n";
    }

    bool loginuser(string username, string password)
    {
        for (auto i = users.begin(); i != users.end(); ++i)
        {
            if (i->getuser() == username && i->getpass() == password)
            {
                cout << "Password matched" << endl;
                return true;
            }
        }
        return false;
    }

    void reg(string username, string password, string name, int type,string phone, string add)
    {
        cout << "\nPATIENT REGISTRATION SUCCESSFUL!\n\n";
        patients.push_back(Patient(username, password, name,type, phone, add));
    }

    void reg(string username, string password, string name, int type, string phone, string add, string date)
    {
        cout << "\nDONOR REGISTRATION SUCCESSFUL!\n\n";
        donors.push_back(Donor(username, password, name,type, phone, add, date));
    }
    void displayUsers()
    {
        cout<<"Username and Password of all users: "<<endl<<endl;
        if(users.empty())
        {
            cout<<"No User Registered."<<endl;
            cout<<endl;
        }
        for (auto i = users.begin(); i != users.end(); ++i)
        {
            i->displayinfo();
        }
    }
    void displayDonors()
    {
        cout << "List of Donors:\n";
        if(donors.empty())
        {
            cout<<"No Donor Registered."<<endl<<endl;
        }

        for (auto i = donors.begin(); i != donors.end(); ++i)
        {
            i->displayinfo();
            cout << endl;
        }
    }

    void displayPatients()
    {
        cout << "List of Patients:\n"<<endl;
        if(patients.empty())
        {
            cout<<"No Patient Registered."<<endl<<endl;
        }
        for (auto i = patients.begin(); i != patients.end(); ++i)
        {
            i->displayinfo();
            cout << endl;
        }
    }
    void searchblood()
    {

        cout<<"Enter the bloodtype: ";
        int bg;
        cin>>bg;

        if(donors.empty())
        {
            cout<<"Blood bank is empty.";
            cout<<endl<<endl;
        }

        for(auto i=donors.begin(); i!=donors.end(); i++)
        {
            if(i->type==bg)
            {
                cout<<"found donor"<<endl;
                cout<<"name  :"<<i->name<<" Contact number : "<<i->phone<<endl;
            }
            else
            {

                cout<<"Not Found"<<endl;
            }
        }

    }
    void updateDonor(string username)
    {

        for(auto& donor : donors)
        {
            if(donor.username == username)
            {
                cout << "Enter new information for donor: " << donor.name << endl;
                cout << "Enter donor name: ";
                getline(cin, donor.name);
                cout << "Enter donor phone number: ";
                getline(cin, donor.phone);
                cout << "Enter donor area: ";
                getline(cin, donor.add);
                cout << "Enter date of donation: ";
                getline(cin, donor.date);
                cout << "Donor information updated successfully!" << endl;
                return;
            }
        }
        cout << "Donor with username " << username << " not found!\n" << endl;
    }
    void updatePatient(string username)
    {

        for(auto& patient : patients)
        {
            if(patient.username == username)
            {
                cout << "Enter new information for patient: " << patient.name << endl;
                cout << "Enter patient name: ";
                getline(cin, patient.name);
                cout << "Enter patient phone number: ";
                getline(cin, patient.phone);
                cout << "Enter patient area: ";
                getline(cin, patient.add);
                cout << "Patient information updated successfully!" << endl;
                return;
            }
        }
        cout << "Patient with username " << username << " not found!\n" << endl;
    }
    void deleteDonor(const string& name)
    {
        for (auto it = donors.begin(); it != donors.end(); ++it)
        {
            if (it->name == name)
            {
                donors.erase(it);
                cout << "Donor " << name << " deleted successfully!" << endl;
                return;
            }
        }
        cout << "Donor " << name << " not found!\n" << endl;
    }
    void deletePatient(const string& name)
    {

        for (auto it = patients.begin(); it != patients.end(); ++it)
        {
            if (it->name == name)
            {
                patients.erase(it);
                cout << "Patient " << name << " deleted successfully!" << endl;
                return;
            }
        }
        cout << "Patient " << name << " not found!\n" << endl;
    }
};
class Admin
{
public:
    string id;
    long long int num;
    Admin(string id,long long int num)
    {
        this->id=id;
        this->num=num;
    }
    void adminmenu()
    {
        cout<<"Administrator Functions: "<<endl<<endl;
        cout<<"Press 1 for accessing all usernames and passwords"<<endl;
        cout<<"Press 2 for accessing all donor informations"<<endl;
        cout<<"Press 3 for accessing all patient informations"<<endl;
        cout<<"Press 4 for Updating donor information"<<endl;
        cout<<"Press 5 for Updating Patient information"<<endl;
        cout<<"Press 6 for deleting donor"<<endl;
        cout<<"Press 7 for deleting patient"<<endl;
        cout<<"Press 8 for exiting admin panel"<<endl<<endl;
        cout<<"Enter your choice: ";

    }
};

int main()

{
    BloodDonationSystem bloodSystem;
    cout<<"      -------------------------------------------------\n";
    cout<<"      | EFFICIENT  BLOOD DONATION AND TRACKING SYSTEM |\n";
    cout<<"      -------------------------------------------------";
    cout<<endl;
    int choice;
    string username, password, name, phone, address, date;
    char show;
    int type;
    BloodDonationSystem bds;
    while (1)
    {
        cout << "\n************MAIN MENU*************\n"<<endl;
        cout << "1. Registration\n";
        cout << "2. register Patient\n";
        cout << "3. register Donor\n";
        cout << "4. search blood\n";
        cout<<"5. Admin Panel"<<endl<<endl;
        cout<<"Enter you choice: ";
        cin >> choice;
        cout<<endl;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            ofstream fileuser;
            fileuser.open("User.txt",ios::out|ios::app);

            cout << "Registration" << endl;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout<<endl;
            fileuser<<username<<"/"<<password<<endl;
            fileuser.close();
            bds.reg(username, password);
        }
        break;
        case 2:

        {

            cout << "Welcome Patient" << endl;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout<<endl;

            if (verifyUser(username, password))
            {
                cout << "Login successful!" << endl<<endl;
                ofstream filepatient;
                filepatient.open("Patient.txt",ios::out|ios::app);

                cout << "Enter patient name: ";
                getline(cin, name);
                cout << "Enter blood type (0=A+, 1=B+, 2=AB+, 3=O+, 4=A-, 5=B-, 6=AB-, 7=O-): ";
                cin >> type;
                cin.ignore();
                cout << "Enter patient phone number: ";
                getline(cin, phone);
                cout << "Enter patient area: ";
                getline(cin, address);
                Patient x(username, password, name, type, phone, address);
                cout << "Do you want to watch your information? (Press y to watch): ";
                cin >> show;
                cout<<endl;
                if (show == 'y')
                {
                    x.displayinfo();
                }
                bds.reg(username, password, name, type, phone, address);
                filepatient<<endl<<name<<"/";
                if(type==0)
                { filepatient<<"A+";

                }
                 else if(type==1)
                { filepatient<<"B+";

                }
                else if(type==2)
                { filepatient<<"AB+";

                }
                else if(type==3)
                { filepatient<<"O+";

                }
                else if(type==4)
                { filepatient<<"A-";

                }
                 else if(type==5)
                { filepatient<<"B-";

                }
                else if(type==6)
                { filepatient<<"AB-";

                }
                else if(type==7)
                { filepatient<<"O-";

                }
                filepatient<<"/"<<phone<<"/"<<address<<"/"<<endl;
                filepatient.close();

                available(static_cast<bloodtype>(type));

            }
            else
            {
                cout << "Login failed!" << endl;
            }
        }
        break;
        case 3:

        {
            cout << "Welcome Donor" << endl;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout<<endl;
            if (verifyUser(username, password))
            {
                cout << "Login successful!" << endl;
                ofstream filedonor;
                filedonor.open("donor.txt",ios::out|ios::app);
                cout << "Enter donor name: ";
                getline(cin, name);
                cout << "Enter blood type (0=A+, 1=B+, 2=AB+, 3=O+, 4=A-, 5=B-, 6=AB-, 7=O-): ";
                cin >> type;
                cin.ignore(); // Consume newline
                cout << "Enter donor phone number: ";
                getline(cin, phone);
                cout << "Enter donor area: ";
                getline(cin, address);
                cout << "Enter date of donation: ";
                getline(cin, date);
                Donor y(username, password, name, type, phone, address, date);
                cout << "Do you want to watch your information? (Press y to watch): ";
                cin >> show;
                cout<<endl;
                filedonor<<name<<"/";
                if(type==0)
                { filedonor<<"A+";

                }
                 else if(type==1)
                { filedonor<<"B+";

                }
                else if(type==2)
                { filedonor<<"AB+";

                }
                else if(type==3)
                { filedonor<<"O+";

                }
                else if(type==4)
                { filedonor<<"A-";

                }
                 else if(type==5)
                { filedonor<<"B-";

                }
                else if(type==6)
                { filedonor<<"AB-";

                }
                else if(type==7)
                { filedonor<<"O-";

                }

                filedonor<<"/"<<phone<<"/"<<address<<"/"<<date<<"/"<<endl;
                if (show == 'y')
                {
                    y.displayinfo();
                }
                bds.reg(username, password, name, type, phone, address, date);
                collect(static_cast<bloodtype>(type));
            }
            else
            {
                cout << "Login failed!" << endl;
            }
        }
        break;

        case 4:
            cout<<"                 Search Blood        "<<endl;
            cout << "Available blood types (0=A+, 1=B+, 2=AB+, 3=O+, 4=A-, 5=B-, 6=AB-, 7=O-) "<<endl;
            bds.searchblood();
            break;
        case 5:
           {

           Admin key("Orthita",398) ;
            string id;
            long long int num;

            cout <<"Enter Admin ID: ";
            getline(cin,id);
            cout <<"Enter Admin pin number: ";
            cin>>num;
            cout<<endl;
            cin.ignore();
            Admin login(id,num);
            if(key.id==login.id && key.num==login.num)
            {
                cout<<"Administrator identification successful"<<endl<<endl;

                while(1)
                {

                    login.adminmenu();

                    int option;
                    cin>>option;
                    cin.ignore();
                    if(option==1)
                    {
                        bds.displayUsers();
                    }
                    if(option==2)
                    {
                        bds.displayDonors();
                    }
                    if(option==3)
                    {
                        bds.displayPatients();
                    }
                    if(option==4)
                    {
                        cout << "Enter username of the donor to update: ";
                        getline(cin, username);
                        bds.updateDonor(username);

                    }
                    if(option==5)
                    {
                        cout << "Enter username of the patient to update: ";
                        getline(cin, username);
                        bds.updatePatient(username);
                    }
                    if(option==6)
                    {
                        string donorName;
                        cout << "Enter the name of the donor to delete: ";
                        getline(cin, donorName);
                        bds.deleteDonor(donorName);
                    }
                    if(option==7)
                    {
                        string patientName;
                        cout << "Enter the name of the patient to delete: ";
                        getline(cin, patientName);
                        bds.deletePatient(patientName);

                    }
                    if(option==8)
                    {
                        cout<<"Exiting Admin Panel "<<endl<<endl;
                        return main();
                    }

                }
            }
            else
            {

                cout<<"Admin login failed"<<endl;
            }}
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
