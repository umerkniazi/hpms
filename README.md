# Hospital Patient Management System (HPMS)

## 📚 Course Information

- **Course:** Programming Fundamentals  
- **Course Code:** AI-133  
- **Semester:** Spring 2025  
- **Instructor:** Mr. Muhammad Usman Yousaf

## 👥 Project Background

This project started as a group assignment during my first semester. Original contributors included:

- Amna  
- Haider  
- Rehman  
- Umer

Since then, I've made significant changes and continued development independently.

## 🏥 Project Description

**HPMS** is a console-based Hospital Patient Management System written in **C++**. It allows you to register, search, update, delete, and categorize patient records. Data is stored in a plain text file for persistence between sessions.

This project is cross-platform and runs on **Windows**, **Linux**, and **macOS**, using only standard console features (no GUI or external libraries).

## 💡 Features

- Register new patients  
- Search by CNIC  
- Update existing records  
- Delete patients  
- Categorize by symptom  
- List all patients  
- Save/load from `patients.txt`

## 🖥 Cross-Platform Support

- Works in terminals like CMD, Bash, etc.
- Uses:
  - ANSI escape codes for Linux/macOS
  - `windows.h` for Windows console colors

## 🚀 How to Compile and Run

```
# Linux/macOS
g++ hpms.cpp -o hpms
./hpms

# Windows
c++ hpms.cpp -o hpms.exe
hpms.exe
```

📌 Make sure `patients.txt` is in the same folder as your executable for data loading and saving.

## 🔧 Future Improvements

- Refactor to use classes and proper object-oriented design  
- Add input validation and error handling  
- Improve the user interface (better formatting, colors, etc.)  
- Add login/user roles (e.g. admin, doctor)  
- Migrate from text file to a proper database

## 📄 License

This project is licensed under the [MIT License](LICENSE).