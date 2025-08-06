# Hospital Patient Management System (HPMS)

Console-based hospital patient management system built with C++ for a Programming Fundamentals course.

## 📚 Course Info

- **Course:** Programming Fundamentals
- **Code:** AI-133
- **Semester:** Spring 2025
- **Instructor:** Mr. Muhammad Usman Yousaf

## 👥 Background

Originally a group assignment in my first semester with:

- Amna
- Haider
- Rehman
- Umer

I've continued developing and improving the project on my own since the initial submission.

## 🏥 Overview

**HPMS** is a simple console program that lets you:

- Register, search, update and delete patients
- Filter by symptom
- View all records
- Save data to `patients.txt` for later use

It’s completely terminal-based with no external libraries or GUI.

## 💡 Features

- Add new patients
- Search by CNIC
- Update records
- Delete entries
- List patients by symptom or all
- Persistent file storage with `patients.txt`

## 🖥 Platform Support

- **Cross-platform:** Works on Windows, Linux, macOS
- Uses ANSI escape codes for Linux/macOS
- Uses `windows.h` for colors in Windows CMD

## ⚙️ Compile & Run

```bash
# On Linux/macOS
g++ hpms.cpp -o hpms
./hpms

# On Windows
c++ hpms.cpp -o hpms.exe
hpms.exe
```

📌 Keep `patients.txt` in the same folder for saving and loading data.

## 🛠 Improvements Planned

- Convert to proper OOP with classes
- Input validation and error handling
- Better formatting and CLI styling
- Add login system and user roles
- Migrate from text file to database

## 📄 License

This project is licensed under the [MIT License](LICENSE).
