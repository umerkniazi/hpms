/*
    Hospital Patient Management System (HPMS)
    -----------------------------------------
    Authors    : Amna, Haider, Rehman, Umer
    Course     : Programming Fundamentals (AI-133)
    Instructor : Mr. Muhammad Usman Yousaf

    Description:
        Console-based system to manage patient records: registration,
        search, update, delete, listing, and categorization.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#endif

using namespace std;

const int MAX_PATIENTS = 100;
int patientCount = 0;

string cnics[MAX_PATIENTS];
string names[MAX_PATIENTS];
int ages[MAX_PATIENTS];
char genders[MAX_PATIENTS];
string phoneNumbers[MAX_PATIENTS];
string emailAddresses[MAX_PATIENTS];
string symptoms[MAX_PATIENTS];

void printMenu();
void registerPatient();
void searchPatientByCNIC();
void updatePatient();
void showCategories();
void listAllPatients();
void deletePatientByCNIC();
string selectSymptom();
void setColor(int color);
void resetColor();
void clearScreen();
void waitForKey();
void savePatientsToFile();
void loadPatientsFromFile();

// Validate CNIC format: 12345-1234567-1
bool isValidCNIC(const string &cnic)
{
    return cnic.length() == 15 &&
           isdigit(cnic[0]) && isdigit(cnic[1]) && isdigit(cnic[2]) && isdigit(cnic[3]) && isdigit(cnic[4]) &&
           cnic[5] == '-' &&
           isdigit(cnic[6]) && isdigit(cnic[7]) && isdigit(cnic[8]) && isdigit(cnic[9]) && isdigit(cnic[10]) &&
           isdigit(cnic[11]) && isdigit(cnic[12]) &&
           cnic[13] == '-' &&
           isdigit(cnic[14]);
}

// Validate phone number format: 03001234567
bool isValidPhone(const string &phone)
{
    return phone.length() == 11 && phone.substr(0, 2) == "03" &&
           all_of(phone.begin(), phone.end(), ::isdigit);
}

// Simple email validation: must contain '@' and '.' after '@'
bool isValidEmail(const string &email)
{
    size_t at = email.find('@');
    size_t dot = email.find('.', at + 1);
    return !email.empty() && at != string::npos && dot != string::npos && dot > at + 1;
}

int main()
{
    setColor(11);
    cout << "\n=============================================\n";
    cout << " Welcome to the Hospital Patient Management System\n";
    cout << "=============================================\n";
    resetColor();
    loadPatientsFromFile();
    int choice = 0;

    while (true)
    {
        printMenu();
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(12);
            cout << "\n[!] Invalid input. Please enter a number between 1 and 7.\n";
            resetColor();
            waitForKey();
            continue;
        }

        if (choice == 7)
            break;

        switch (choice)
        {
        case 1:
            registerPatient();
            break;
        case 2:
            searchPatientByCNIC();
            break;
        case 3:
            updatePatient();
            break;
        case 4:
            showCategories();
            break;
        case 5:
            listAllPatients();
            break;
        case 6:
            deletePatientByCNIC();
            break;
        default:
            setColor(12);
            cout << "\n[!] Invalid choice. Please select a valid option from the menu.\n";
            resetColor();
            break;
        }

        waitForKey();
    }

    setColor(10);
    cout << "\n****************************************\n";
    cout << "   Thank you for using HPMS. Goodbye!   \n";
    cout << "****************************************\n";
    resetColor();
    return 0;
}

void printMenu()
{
    clearScreen();
    setColor(11);
    cout << "               _    _ _____  __  __  _____  \n";
    cout << "              | |  | |  __ \\|  \\/  |/ ____| \n";
    cout << "              | |__| | |__) | \\  / | (___   \n";
    cout << "              |  __  |  ___/| |\\/| |\\___ \\  \n";
    cout << "              | |  | | |    | |  | |____) | \n";
    cout << "              |_|  |_|_|    |_|  |_|_____/  \n";
    resetColor();
    cout << "  +----------------------------------------------------+\n";
    cout << "  |        Hospital Patient Management System          |\n";
    cout << "  +----------------------------------------------------+\n";
    cout << "  | Created by : Amna, Haider, Rehman, Umer            |\n";
    cout << "  | Course     : Programming Fundamentals (AI-133)     |\n";
    cout << "  | Instructor : Mr. Muhammad Usman Yousaf             |\n";
    cout << "  +----------------------------------------------------+\n";
    setColor(14);
    cout << "  +------------------------ MENU ----------------------+ \n";
    resetColor();
    cout << "  | [1] Register Patient                               |\n";
    cout << "  | [2] Search Patient by CNIC                         |\n";
    cout << "  | [3] Update Patient Details                         |\n";
    cout << "  | [4] Show Categories                                |\n";
    cout << "  | [5] List All Patients                              |\n";
    cout << "  | [6] Delete Patient by CNIC                         |\n";
    cout << "  | [7] Exit                                           |\n";
    cout << "  +----------------------------------------------------+\n";
    setColor(10);
    cout << "\n  Total Patients Registered: " << patientCount << "\n";
    setColor(11);
    cout << "\n  Please select an option and press Enter [1-7]: ";
    resetColor();
}

void registerPatient()
{
    if (patientCount >= MAX_PATIENTS)
    {
        setColor(12);
        cout << "\n[!] Maximum number of patients reached. Cannot register more.\n";
        resetColor();
        return;
    }

    cin.ignore();
    string cnicInput;
    while (true)
    {
        cout << "\nEnter CNIC (format: 12345-1234567-1): ";
        getline(cin, cnicInput);
        bool duplicate = false;
        for (int i = 0; i < patientCount; i++)
        {
            if (cnics[i] == cnicInput)
            {
                duplicate = true;
                break;
            }
        }
        if (!isValidCNIC(cnicInput))
        {
            setColor(12);
            cout << "[!] Invalid CNIC format. Please use 12345-1234567-1.\n";
            resetColor();
        }
        else if (duplicate)
        {
            setColor(12);
            cout << "[!] This CNIC is already registered. Please enter a unique CNIC.\n";
            resetColor();
        }
        else
        {
            cnics[patientCount] = cnicInput;
            break;
        }
    }

    cout << "Enter full name: ";
    getline(cin, names[patientCount]);

    while (true)
    {
        cout << "Enter age (1-120): ";
        cin >> ages[patientCount];
        if (!cin.fail() && ages[patientCount] >= 1 && ages[patientCount] <= 120)
            break;
        cin.clear();
        cin.ignore(1000, '\n');
        setColor(12);
        cout << "[!] Invalid age. Please enter a number between 1 and 120.\n";
        resetColor();
    }

    while (true)
    {
        cout << "Enter gender (M/F): ";
        cin >> genders[patientCount];
        genders[patientCount] = toupper(genders[patientCount]);
        if (genders[patientCount] == 'M' || genders[patientCount] == 'F')
            break;
        setColor(12);
        cout << "[!] Invalid input. Please enter 'M' for Male or 'F' for Female.\n";
        resetColor();
    }

    cin.ignore();
    string phoneInput;
    while (true)
    {
        cout << "Enter phone number (format: 03001234567): ";
        getline(cin, phoneInput);
        if (!isValidPhone(phoneInput))
        {
            setColor(12);
            cout << "[!] Invalid phone number format. Please use 03001234567.\n";
            resetColor();
        }
        else
        {
            phoneNumbers[patientCount] = phoneInput;
            break;
        }
    }

    string emailInput;
    while (true)
    {
        cout << "Enter email address: ";
        getline(cin, emailInput);
        if (!isValidEmail(emailInput))
        {
            setColor(12);
            cout << "[!] Invalid email address. Please enter a valid email (e.g., user@example.com).\n";
            resetColor();
        }
        else
        {
            emailAddresses[patientCount] = emailInput;
            break;
        }
    }

    symptoms[patientCount] = selectSymptom();
    patientCount++;
    savePatientsToFile();
    setColor(10);
    cout << "\n[OK] Patient registered successfully!\n";
    resetColor();
}

void searchPatientByCNIC()
{
    string cnic;
    cin.ignore();
    cout << "\nEnter the patient's CNIC to search (format: 12345-1234567-1): ";
    getline(cin, cnic);
    bool found = false;

    for (int i = 0; i < patientCount; i++)
    {
        if (cnics[i] == cnic)
        {
            setColor(11);
            cout << "\nPatient Found:\n";
            cout << string(70, '=') << "\n";
            cout << left << setw(20) << "Field" << "Details\n";
            cout << string(70, '-') << "\n";
            cout << left << setw(20) << "CNIC:" << cnics[i] << "\n";
            cout << left << setw(20) << "Name:" << names[i] << "\n";
            cout << left << setw(20) << "Age:" << ages[i] << "\n";
            cout << left << setw(20) << "Gender:" << genders[i] << "\n";
            cout << left << setw(20) << "Phone:" << phoneNumbers[i] << "\n";
            cout << left << setw(20) << "Email:" << emailAddresses[i] << "\n";
            cout << left << setw(20) << "Symptom:" << symptoms[i] << "\n";
            cout << string(70, '=') << "\n";
            resetColor();
            found = true;
            break;
        }
    }

    if (!found)
    {
        setColor(12);
        cout << "\n[!] Patient not found. Please check the CNIC and try again.\n";
        resetColor();
    }
}

void updatePatient()
{
    string cnic;
    cin.ignore();
    cout << "\nEnter CNIC to update (format: 12345-1234567-1): ";
    getline(cin, cnic);

    for (int i = 0; i < patientCount; i++)
    {
        if (cnics[i] == cnic)
        {
            while (true)
            {
                cout << "Current Age: " << ages[i] << "\n";
                cout << "Enter new age: ";
                cin >> ages[i];
                if (!cin.fail() && ages[i] >= 1 && ages[i] <= 120)
                    break;
                cin.clear();
                cin.ignore(1000, '\n');
                setColor(12);
                cout << "[!] Invalid age. Please enter a number between 1 and 120.\n";
                resetColor();
            }
            cin.ignore();

            string phoneInput;
            while (true)
            {
                cout << "Current Phone: " << phoneNumbers[i] << "\n";
                cout << "Enter new phone (format: 03001234567): ";
                getline(cin, phoneInput);
                if (!isValidPhone(phoneInput))
                {
                    setColor(12);
                    cout << "[!] Invalid phone number format. Please use 03001234567.\n";
                    resetColor();
                }
                else
                {
                    phoneNumbers[i] = phoneInput;
                    break;
                }
            }

            cout << "Current Email: " << emailAddresses[i] << "\n";
            string emailInput;
            while (true)
            {
                cout << "Enter new email: ";
                getline(cin, emailInput);
                if (!isValidEmail(emailInput))
                {
                    setColor(12);
                    cout << "[!] Invalid email address. Please enter a valid email (e.g., user@example.com).\n";
                    resetColor();
                }
                else
                {
                    emailAddresses[i] = emailInput;
                    break;
                }
            }

            cout << "Current Symptom: " << symptoms[i] << "\n";
            symptoms[i] = selectSymptom();

            savePatientsToFile();
            setColor(10);
            cout << "\n[OK] Patient updated successfully!\n";
            resetColor();
            return;
        }
    }

    setColor(12);
    cout << "\n[!] Patient not found. Please check the CNIC and try again.\n";
    resetColor();
}

void showCategories()
{
    if (patientCount == 0)
    {
        setColor(12);
        cout << "\n[!] No patients registered yet.\n";
        resetColor();
        return;
    }

    setColor(11);
    cout << "\nPatient Categories:\n";
    cout << left << setw(20) << "CNIC" << setw(20) << "Name"
         << setw(20) << "Symptom" << setw(20) << "Category" << endl;
    cout << string(80, '-') << endl;

    for (int i = 0; i < patientCount; i++)
    {
        string category;
        if (symptoms[i] == "Fever")
            category = "Infection";
        else if (symptoms[i] == "Cough" || symptoms[i] == "Shortness of Breath")
            category = "Respiratory";
        else if (symptoms[i] == "Headache" || symptoms[i] == "Dizziness")
            category = "Neurological";
        else if (symptoms[i] == "Fatigue")
            category = "General";
        else if (symptoms[i] == "Chest Pain")
            category = "Cardiac";
        else if (symptoms[i] == "Nausea" || symptoms[i] == "Vomiting")
            category = "Digestive";
        else
            category = "Other";

        cout << left << setw(20) << cnics[i]
             << setw(20) << names[i]
             << setw(20) << symptoms[i]
             << setw(20) << category << endl;
    }

    cout << string(80, '-') << endl;
    resetColor();
}

void listAllPatients()
{
    if (patientCount == 0)
    {
        setColor(12);
        cout << "\n[!] No patients registered yet.\n";
        resetColor();
        return;
    }

    setColor(11);
    cout << "\nAll Registered Patients:\n";
    cout << left << setw(18) << "CNIC" << setw(20) << "Name"
         << setw(6) << "Age" << setw(8) << "Gender"
         << setw(15) << "Phone" << setw(30) << "Email"
         << setw(20) << "Symptom" << endl;
    cout << string(117, '-') << endl;

    for (int i = 0; i < patientCount; i++)
    {
        cout << left << setw(18) << cnics[i]
             << setw(20) << names[i]
             << setw(6) << ages[i]
             << setw(8) << genders[i]
             << setw(15) << phoneNumbers[i]
             << setw(30) << emailAddresses[i]
             << setw(20) << symptoms[i] << endl;
    }

    cout << string(117, '-') << endl;
    resetColor();
}

void deletePatientByCNIC()
{
    string cnicToDelete;
    cin.ignore();
    cout << "\nEnter CNIC of the patient to delete (format: 12345-1234567-1): ";
    getline(cin, cnicToDelete);
    bool found = false;

    for (int i = 0; i < patientCount; i++)
    {
        if (cnics[i] == cnicToDelete)
        {
            cout << "\nAre you sure you want to delete this patient? (Y/N): ";
            char confirm;
            cin >> confirm;
            confirm = toupper(confirm);
            cin.ignore();
            if (confirm != 'Y')
            {
                setColor(14);
                cout << "\n[!] Deletion cancelled.\n";
                resetColor();
                return;
            }
            for (int j = i; j < patientCount - 1; j++)
            {
                cnics[j] = cnics[j + 1];
                names[j] = names[j + 1];
                ages[j] = ages[j + 1];
                genders[j] = genders[j + 1];
                phoneNumbers[j] = phoneNumbers[j + 1];
                emailAddresses[j] = emailAddresses[j + 1];
                symptoms[j] = symptoms[j + 1];
            }
            patientCount--;
            savePatientsToFile();
            setColor(10);
            cout << "\n[OK] Patient deleted successfully!\n";
            resetColor();
            found = true;
            break;
        }
    }

    if (!found)
    {
        setColor(12);
        cout << "\n[!] No patient found with that CNIC. Please check and try again.\n";
        resetColor();
    }
}

string selectSymptom()
{
    int choice;
    while (true)
    {
        cout << "\n+---------------------------+\n";
        cout << "|   Select a Symptom        |\n";
        cout << "+---------------------------+\n";
        cout << "| 1. Fever       2. Cough   |\n";
        cout << "| 3. Headache    4. Fatigue |\n";
        cout << "| 5. Breathless  6. Chest   |\n";
        cout << "| 7. Dizziness   8. Nausea  |\n";
        cout << "| 9. Vomiting   10. Other   |\n";
        cout << "+---------------------------+\n";
        cout << "Enter choice (1-10): ";
        cin >> choice;

        if (!cin.fail() && choice >= 1 && choice <= 10)
            break;

        cin.clear();
        cin.ignore(1000, '\n');
        setColor(12);
        cout << "[!] Invalid input. Please enter a number between 1 and 10.\n";
        resetColor();
    }
    cin.ignore();

    switch (choice)
    {
    case 1:
        return "Fever";
    case 2:
        return "Cough";
    case 3:
        return "Headache";
    case 4:
        return "Fatigue";
    case 5:
        return "Shortness of Breath";
    case 6:
        return "Chest Pain";
    case 7:
        return "Dizziness";
    case 8:
        return "Nausea";
    case 9:
        return "Vomiting";
    default:
        return "Other";
    }
}

void setColor(int color)
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    switch (color)
    {
    case 7:
        cout << "\033[0m";
        break;
    case 10:
        cout << "\033[32m";
        break;
    case 11:
        cout << "\033[36m";
        break;
    case 12:
        cout << "\033[31m";
        break;
    case 14:
        cout << "\033[33m";
        break;
    default:
        cout << "\033[0m";
        break;
    }
#endif
}

void resetColor() { setColor(7); }

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H";
#endif
}

void waitForKey()
{
#ifdef _WIN32
    getch();
#else
    cin.ignore();
    cin.get();
#endif
}

void savePatientsToFile()
{
    ofstream outFile("patients.txt");
    if (!outFile)
    {
        setColor(12);
        cout << "Error saving patient data.\n";
        resetColor();
        return;
    }

    for (int i = 0; i < patientCount; i++)
    {
        outFile << cnics[i] << ',' << names[i] << ',' << ages[i] << ','
                << genders[i] << ',' << phoneNumbers[i] << ','
                << emailAddresses[i] << ',' << symptoms[i] << '\n';
    }
    outFile.close();
}

void loadPatientsFromFile()
{
    ifstream file("patients.txt");
    string line;

    while (getline(file, line) && patientCount < MAX_PATIENTS)
    {
        stringstream ss(line);
        string ageStr, genderStr;

        getline(ss, cnics[patientCount], ',');
        getline(ss, names[patientCount], ',');
        getline(ss, ageStr, ',');
        getline(ss, genderStr, ',');
        getline(ss, phoneNumbers[patientCount], ',');
        getline(ss, emailAddresses[patientCount], ',');
        getline(ss, symptoms[patientCount]);

        ages[patientCount] = stoi(ageStr);
        genders[patientCount] = genderStr.empty() ? '?' : genderStr[0];

        patientCount++;
    }
    file.close();
}