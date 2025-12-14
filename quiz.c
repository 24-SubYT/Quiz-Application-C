#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ============================================================
// STRUCTURE DEFINITION FOR STORING QUIZ QUESTIONS
// ============================================================
struct Question {
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer; // Stores 'a', 'b', 'c', or 'd'
};
// ============================================================
// GLOBAL VARIABLES
// ============================================================
struct Question questions[50]; // Array to store up to 50 questions
int totalQuestions = 0;        // Counter for total questions loaded
int correctAnswers = 0;        // Counter for correct answers
// ============================================================
// FUNCTION PROTOTYPES
// ============================================================
int loadQuestions(const char *filename);
void displayQuestion(int questionNum);
char getValidInput(void);
void checkAnswer(char userAnswer, int questionNum);
void displayResults(void);
char getPerformanceRating(float percentage);
void displayWelcomeScreen(void);
// ============================================================
// MAIN FUNCTION - PROGRAM ENTRY POINT
// ============================================================
int main() {
    int i;
    char userAnswer;
    // Display welcome message
    displayWelcomeScreen();
    // Attempt to load questions from file
    if (loadQuestions("questions.txt") == 0) {
        printf("\n\nERROR: Unable to load questions from file!\n");
        printf("Please ensure 'questions.txt' exists in the current directory.\n");
        return 1;
    }
    printf("\n========================================\n");
    printf("Successfully loaded %d questions!\n", totalQuestions);
    printf("========================================\n");
    printf("\nPress Enter to begin the quiz...\n");
    getchar();  // Wait for user confirmation
    // Main quiz loop - iterate through each question
    for (i = 0; i < totalQuestions; i++) {
        system("clear || cls"); // Clear screen (works on Unix/Windows)
        printf("\n==================== QUESTION %d OF %d ====================\n\n", i + 1, totalQuestions);
        // Display current question
        displayQuestion(i);
        // Get user's answer with validation
        userAnswer = getValidInput();
        // Check if answer is correct and update score
        checkAnswer(userAnswer, i);
        // Brief pause before next question
        printf("\nPress Enter to continue to next question...\n");
        getchar();
    }
    // Display final results and performance feedback
    system("clear || cls");
    displayResults();
    return 0;
}
// ============================================================
// FUNCTION: loadQuestions
// PURPOSE: Read quiz questions from external file into memory
// PARAMETERS: filename - name of the file containing questions
// RETURN: Number of questions loaded (0 if file not found)
// ============================================================
int loadQuestions(const char *filename) {
    FILE *file;
    char line[256];
    int count = 0;
    // Attempt to open file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR: Cannot open file '%s'\n", filename);
        return 0;
    }
    // Read questions from file until EOF or array is full
    while (fgets(line, sizeof(line), file) != NULL && count < 50) {
        // Skip empty lines and comments
        if (line[0] == '\n' || line[0] == '#') {
            continue;
        }
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';
        // Read question text
        strcpy(questions[count].question, line);
        // Read four answer options
        if (fgets(line, sizeof(line), file) == NULL) break;
        line[strcspn(line, "\n")] = '\0';
        strcpy(questions[count].optionA, line);
        if (fgets(line, sizeof(line), file) == NULL) break;
        line[strcspn(line, "\n")] = '\0';
        strcpy(questions[count].optionB, line);
        if (fgets(line, sizeof(line), file) == NULL) break;
        line[strcspn(line, "\n")] = '\0';
        strcpy(questions[count].optionC, line);
        if (fgets(line, sizeof(line), file) == NULL) break;
        line[strcspn(line, "\n")] = '\0';
        strcpy(questions[count].optionD, line);
        // Read correct answer (single character: a, b, c, or d)
        if (fgets(line, sizeof(line), file) == NULL) break;
        questions[count].correctAnswer = tolower(line[0]);
        count++;
    }
    // Close file and return count
    fclose(file);
    totalQuestions = count;
    return count;
}
// ============================================================
// FUNCTION: displayQuestion
// PURPOSE: Display a question and its four answer options
// PARAMETERS: questionNum - index of question to display (0-based)
// RETURN: void
// ============================================================
void displayQuestion(int questionNum) {
    // Display the question text
    printf("Question: %s\n\n", questions[questionNum].question);
    // Display four labeled options
    printf(" a) %s\n", questions[questionNum].optionA);
    printf(" b) %s\n", questions[questionNum].optionB);
    printf(" c) %s\n", questions[questionNum].optionC);
    printf(" d) %s\n", questions[questionNum].optionD);
    printf("\n");
}
// ============================================================
// FUNCTION: getValidInput
// PURPOSE: Get user input with validation for a, b, c, or d
// PARAMETERS: none
// RETURN: Valid answer character (a, b, c, or d)
// ============================================================
char getValidInput(void) {
    char input[10];
    char answer;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;
    // Loop until valid input received or max attempts exceeded
    while (attempts < MAX_ATTEMPTS) {
        printf("Your answer (a/b/c/d): ");
        // Read input from user
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("ERROR: Input failed!\n");
            attempts++;
            continue;
        }
        // Convert to lowercase for consistency
        answer = tolower(input[0]);
        // Validate that answer is one of four options
        if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd') {
            return answer; // Valid input received
        }
        // Invalid input - prompt user to try again
        printf("Invalid input! Please enter a, b, c, or d.\n");
        attempts++;
    }
    // If max attempts exceeded, default to 'a'
    printf("Maximum attempts exceeded. Defaulting to 'a'.\n");
    return 'a';
}
// ============================================================
// FUNCTION: checkAnswer
// PURPOSE: Compare user answer with correct answer and update score
// PARAMETERS: userAnswer - user's chosen answer
//             questionNum - index of current question
// RETURN: void
// ============================================================
void checkAnswer(char userAnswer, int questionNum) {
    // Compare user's answer with stored correct answer
    if (userAnswer == questions[questionNum].correctAnswer) {
        printf("\n✓ CORRECT!\n");
        correctAnswers++; // Increment score
    } else {
        printf("\n✗ INCORRECT!\n");
        printf("The correct answer is: %c\n", questions[questionNum].correctAnswer);
    }
}
// ============================================================
// FUNCTION: getPerformanceRating
// PURPOSE: Determine performance category based on percentage
// PARAMETERS: percentage - score as percentage (0-100)
// RETURN: Single character rating ('E', 'G', or 'N')
// ============================================================
char getPerformanceRating(float percentage) {
    if (percentage >= 80.0) {
        return 'E'; // Excellent
    } else if (percentage >= 60.0) {
        return 'G'; // Good
    } else {
        return 'N'; // Needs Improvement
    }
}
// ============================================================
// FUNCTION: displayResults
// PURPOSE: Show final quiz results with performance feedback
// PARAMETERS: none
// RETURN: void
// ============================================================
void displayResults(void) {
    float percentage;
    char rating;
    // Calculate percentage score
    percentage = (correctAnswers * 100.0) / totalQuestions;
    // Determine performance rating
    rating = getPerformanceRating(percentage);
    // Display results header
    printf("╔════════════════════════════════════════╗\n");
    printf("║ QUIZ RESULTS & FEEDBACK               ║\n");
    printf("╠════════════════════════════════════════╣\n");
    // Display performance statistics
    printf("║ Total Questions: %3d                   ║\n", totalQuestions);
    printf("║ Correct Answers: %3d                   ║\n", correctAnswers);
    printf("║ Score Percentage: %.1f%%                ║\n", percentage);
    printf("║ Final Score: %3d/%d                     ║\n", correctAnswers, totalQuestions);
    printf("╠════════════════════════════════════════╣\n");
    // Display rating with appropriate feedback
    switch (rating) {
        case 'E':
            printf("║ Rating: EXCELLENT! 🌟                  ║\n");
            printf("║ Feedback: Outstanding performance!     ║\n");
            printf("║ You have excellent command of this     ║\n");
            printf("║ topic. Keep up the great work!         ║\n");
            break;
        case 'G':
            printf("║ Rating: GOOD! 👍                       ║\n");
            printf("║ Feedback: Good performance!            ║\n");
            printf("║ You demonstrate solid knowledge.       ║\n");
            printf("║ Review weak areas for improvement.     ║\n");
            break;
        case 'N':
            printf("║ Rating: NEEDS IMPROVEMENT 📚           ║\n");
            printf("║ Feedback: Keep studying!               ║\n");
            printf("║ Review the material and try again.     ║\n");
            printf("║ Don't give up - you'll improve!        ║\n");
            break;
    }
    printf("╚════════════════════════════════════════╝\n");
    printf("\nThank you for taking the quiz!\n");
}
// ============================================================
// FUNCTION: displayWelcomeScreen
// PURPOSE: Show welcome message and program information
// PARAMETERS: none
// RETURN: void
// ============================================================
void displayWelcomeScreen(void) {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║ WELCOME TO QUIZ APPLICATION           ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Test Your Knowledge with Our Quiz!    ║\n");
    printf("║                                        ║\n");
    printf("║ Features:                              ║\n");
    printf("║ • Multiple-choice questions            ║\n");
    printf("║ • Instant score calculation            ║\n");
    printf("║ • Performance feedback                 ║\n");
    printf("║ • Real-time answer validation          ║\n");
    printf("║                                        ║\n");
    printf("║ Instructions:                          ║\n");
    printf("║ 1. Read each question carefully        ║\n");
    printf("║ 2. Choose your answer (a/b/c/d)        ║\n");
    printf("║ 3. Valid answers only accepted         ║\n");
    printf("║ 4. Review results at the end           ║\n");
    printf("╚════════════════════════════════════════╝\n");
}
