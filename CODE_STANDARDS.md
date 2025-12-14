# C Programming Code Standards and Guidelines

## Overview

This document outlines the coding standards and best practices followed in the Quiz Application development. Adherence to these standards ensures code readability, maintainability, and consistency across the project.

## 1. Naming Conventions

### Variables

- Use lowercase with underscores for global and local variables
- Use meaningful, descriptive names that indicate purpose
- Avoid single-letter variables except for loop counters

**Examples:**
```c
int total_questions;      // Good
char user_answer;         // Good
int n;                    // Acceptable only in loops
int qq;                   // Bad
```

### Functions

- Use camelCase starting with lowercase verb
- Function names should describe what they do
- Prefix helper functions with underscore

**Examples:**
```c
void displayQuestion();

int calculateScore();

void _loadFileData();      // Private helper function
```

### Constants

- Use uppercase with underscores for preprocessor constants
- Define all magic numbers as named constants

**Examples:**
```c
#define MAX_QUESTIONS 50
#define BUFFER_SIZE 256
#define OPTION_COUNT 4
```

### Structure Names

- Use PascalCase for struct names
- Suffix with `_t` for typedef'd structures

**Examples:**
```c
struct Question_t {
    // members
};

typedef struct Question_t Question;
```

## 2. Code Formatting

### Indentation

- Use 4 spaces per indentation level (NO TABS)
- Maintain consistent indentation throughout

```c
if (condition) {
    // 4 spaces
    doSomething();
    if (nested_condition) {
        // 8 spaces
        doAnother();
    }
}
```

### Line Length

- Maximum 80 characters per line
- Break long lines at logical points

```c
// Bad - too long
int result = calculateScore(totalQuestions, correctAnswers, questionDifficulty);

// Good
int result = calculateScore(totalQuestions, 
                           correctAnswers, 
                           questionDifficulty);
```

### Braces

- Use K&R style: opening brace on same line
- Always use braces, even for single statements

```c
// Correct
if (condition) {
    statement;
}

// Avoid
if (condition)
    statement;
```

## 3. Comments and Documentation

### File Header

Include at the beginning of each file:

```c
/*
 * quiz.c
 * 
 * Purpose: Main quiz application implementation
 * Author: Student Name
 * Date: YYYY-MM-DD
 * Course: Course Name
 * Institution: GITAM School of Technology
 */
```

### Function Documentation

Document complex functions with brief descriptions:

```c
// Loads questions from file
// Returns: number of questions loaded, -1 on error
int loadQuestions(struct Question *questions, const char *filename) {
    // implementation
}
```

### Inline Comments

- Use sparingly, only for non-obvious logic
- Place comments above the code they describe
- Use single-line comments (//)

```c
// Calculate weighted score considering question difficulty
int weighted_score = (correct_count * difficulty_factor) / total_questions;
```

## 4. Variable Declaration and Initialization

### Declarations

- Declare variables close to usage
- Initialize variables at declaration when possible
- Group related declarations

```c
// Good
int correct_count = 0;
int total_count = 0;
char user_answer = '\0';

// Avoid
int x, y, z;  // Too generic
```

## 5. Function Guidelines

### Size

- Keep functions focused on single responsibility
- Functions should be 20-50 lines typically
- Avoid deeply nested code (max 3 levels)

### Parameters

- Use const for read-only parameters
- Limit parameters to 5 or fewer
- Pass pointers only when necessary

```c
int processQuiz(const struct Question *questions, int count);
```

## 6. Memory Management

### Static Arrays

- Prefer stack-allocated fixed-size arrays
- Define array sizes as named constants

```c
#define MAX_QUESTIONS 50
struct Question questions[MAX_QUESTIONS];
```

### Resource Cleanup

- Always close opened files
- Check return values of system calls

```c
FILE *fp = fopen(filename, "r");
if (fp == NULL) {
    perror("Error opening file");
    return -1;
}
// ... operations ...
fclose(fp);  // Always close
```

## 7. Error Handling

### Return Codes

- Use consistent error return patterns
- Return 0 or positive for success
- Return -1 or specific error codes for failures

```c
int loadQuestions(struct Question *q, const char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;      // File error
    // ... loading ...
    fclose(fp);
    return question_count;          // Success
}
```

### User Input Validation

- Validate all user input
- Check buffer boundaries
- Provide informative error messages

```c
if (answer < 'A' || answer > 'D') {
    printf("Invalid input. Please enter A, B, C, or D.\n");
    // Retry or handle error
}
```

## 8. Type Safety

### Explicit Types

- Avoid implicit type conversions
- Use explicit casts when necessary

```c
int percentage = (int)((correct * 100.0) / total);
```

### Use of typedef

For improved readability:

```c
typedef struct {
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer;
} Question;
```

## 9. Compiler Flags

Always compile with strict warning flags:

```bash
gcc -Wall -Wextra -Werror quiz.c -o quiz
```

Flags mean:
- `-Wall`: Enable all common warnings
- `-Wextra`: Enable additional warnings
- `-Werror`: Treat warnings as errors

## 10. Code Review Checklist

- [ ] Variable and function names are descriptive
- [ ] Code follows indentation standards
- [ ] Functions have documentation comments
- [ ] Error handling is present
- [ ] Magic numbers are defined as constants
- [ ] No unused variables or functions
- [ ] Consistent bracket and quote usage
- [ ] Compiled without warnings
- [ ] Resource cleanup is implemented
- [ ] Edge cases are handled

## 11. Common Pitfalls to Avoid

### Memory Issues
- Buffer overflow attacks
- Uninitialized variables
- Memory leaks

### Logic Errors
- Off-by-one errors in loops
- Unvalidated input assumptions
- Missing null pointer checks

### Style Issues
- Inconsistent naming conventions
- Poor variable names (x, y, temp)
- Missing comments on complex logic

## References

- Linux Kernel Coding Style Guide
- GNU Coding Standards
- ISO/IEC 9899:2018 (C Standard)

## Version History

| Version | Date | Description |
|---------|------|-------------|
| 1.0 | 2025-12-14 | Initial code standards document |
