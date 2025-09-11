# Hospital Patient Management System (HPMS)

A console-based hospital patient management system built in C++ for the Programming Fundamentals course.

## 📚 Course Information

- **Course:** Programming Fundamentals (AI-133)
- **Semester:** Spring 2025
- **Instructor:** Mr. Muhammad Usman Yousaf

## 👥 Project Background

Originally developed as a group assignment with:

- Amna
- Haider
- Rehman
- Umer

The project has since been improved and maintained individually.

## 🏥 System Overview

**HPMS** is a terminal application that allows you to:

- Register, search, update, and delete patient records
- Filter patients by symptom
- View all patient records
- Save and load data from `patients.txt`

No external libraries or GUI are required.

## 💡 Key Features

- Add new patients
- Search by CNIC
- Update patient details
- Delete patient records
- List patients by symptom or view all
- Persistent storage in `patients.txt`

## 🖥 Platform Support

- **Cross-platform:** Windows, Linux, macOS
- Uses ANSI escape codes for Linux/macOS
- Uses `windows.h` for color support in Windows CMD

## ⚙️ Compilation & Usage

```bash
# Linux/macOS
g++ hpms.cpp -o hpms
./hpms

# Windows
c++ hpms.cpp -o hpms.exe
hpms.exe
```

> **Note:** Keep `patients.txt` in the same folder for data persistence.

## 🚀 How to Use

1. Run the compiled program.
2. Follow the menu prompts to manage patient records.
3. Data is automatically saved to `patients.txt`.

## 🛠 Planned Improvements

- Refactor to use OOP and classes
- Enhanced input validation and error handling
- Improved CLI formatting and styling
- Add login system and user roles
- Migrate storage from text file to database

## 📄 License

Licensed under the [MIT License](LICENSE).
