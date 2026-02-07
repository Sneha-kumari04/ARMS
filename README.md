# ARMS – Academic Record Management System
ARMS (Academic Record Management System) is a console-based C project designed to manage academic records of admins, students, and professors using file handling.
The system supports role-based access, record storage, and system reset functionality.

This project is built for academic and learning purposes, focusing on C programming concepts like file I/O, structures, modular programming, and menu-driven design.

## Features
- Admin login
- Student login
- Professor login
- Credential verification using files

### Student Module
1. View My Profile
2. View My Branch & Semester
3. View My attendance
4. View My SGPA & CGPA

### Professor Module
1. View My Profile
2. View My Subjects & Semester
3. Search Student
4. View My All Students
5. View Student Analytics

### Admin Module
1. View Admin Profile
2. Student Management
3. Professor Management
4. Analytics & Reports
5. System Settings

#### Student Management in Admin Module
1. Add New Student
2. View All Students
3. Search Student

#### Professor Management in Admin Module
1. Add Professor
2. Assign Subject & Semester
3. Search professor
4. Search Professor Subject
5. View All Professors
6. View All Professor subject

#### System Setting in Admin Module
1. View System Summary
2. Reset System Data

### File Handling
- Persistent data storage using .txt files
- Separate directories for:
  - Academic data
  - Login credentials


## 🛠️ Technologies Used

- **Language:** C  
- **Concepts:**
  - File Handling
  - Structures
  - Functions
  - Modular Programming
  - Menu-Driven Programs
- **Compiler:** GCC


# How to Compile

## Manual Way
### For Window , Mac OS and Linux
```bash
gcc main.c student.c admin.c utils.c professor.c login.c -o arms
```

## Using MAKEFILE (Recommended for Mac OS & Linux)
```bash
make
```


# How to Run
```bash
./arms
```

## Project Structure
```text
ARMS/
│
├── data/
│   ├── admin.txt
│   ├── student.txt
│   ├── professor.txt
│   └── professor_subjects.txt
│
├── login_credential/
│   ├── admin_credential.txt
│   ├── student_credential.txt
│   └── professor_credential.txt
│
├── main.c
├── admin.c
├── student.c
├── professor.c
├── login.c
├── utils.c
├── structures.h
├── Makefile
└── README.md
```

## Important Notes
- All data is stored in plain text files for academic simplicity.
- Passwords are not encrypted
- Reset system option permanently deletes all stored data.
- Proper file paths and directories must exist before running.

## Future Improvements
- Edit existing data
- Password hashing
- Better input validation

## Contributors
- Sneha Kumari  
- Krishna Kumar

## License

This project is developed for **educational and academic purposes only**.  
It is not intended for commercial use.
