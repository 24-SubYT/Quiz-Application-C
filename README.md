# Quiz Application - Multiple Choice Quiz System

## 📋 Project Overview
A Console-Based Quiz Application implemented in C programming language designed for educational assessments.

### ✨ Features
- **File-based question storage** - Questions stored in external text file
- **Interactive console interface** - User-friendly command-line UI
- **Input validation** - Robust error handling for invalid inputs
- **Real-time scoring** - Instant score calculation and feedback
- **Performance analysis** - Detailed results with ratings (Excellent/Good/Needs Improvement)

## 📚 Project Details
- **Student:** Penmetsa Abhishek Varma
- **Registration No:** 2025523939
- **Department:** Electronics & Communication Engineering
- **Institution:** GITAM School of Technology, Visakhapatnam
- **Guides:** Dr. Bhawani Sankar Panigrahi, Dr. Naina Narang

## 🛠️ Technologies Used
- **Language:** C Programming
- **Platform:** Console-based (Cross-platform)
- **File Handling:** Standard C library (stdio.h, stdlib.h, string.h)



## 🚀 Getting Started

### Compilation

To compile the quiz application, use the GCC compiler:

```bash
gcc quiz.c -o quiz
```

### Running the Application

Execute the compiled program:

```bash
./quiz
```

## 📖 Usage

1. Launch the program using the command above
2. The quiz will load questions from `questions.txt` file
3. Answer each multiple-choice question by entering A, B, C, or D
4. After completing all questions, the program will display your score and performance rating
5. Results include detailed analysis and feedback

## 📝 Questions File Format

The `questions.txt` file should follow this format:

```
Question text here?
A) First option
B) Second option
C) Third option
D) Fourth option
Correct Answer: A
```

Each question must have exactly 4 options and a correct answer indicator.

## 📋 Project Structure

```
quiz-application-c/
├── quiz.c              # Main C program source code
├── questions.txt       # Question database file
├── README.md          # Project documentation
└── Design and Implementation.pdf  # Detailed project report
```
