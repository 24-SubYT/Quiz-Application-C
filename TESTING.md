# Testing and Quality Assurance

## Unit Test Cases

### TC-1: File Loading
- **Purpose:** Verify questions.txt loads correctly
- **Expected:** All questions loaded without errors
- **Status:** PASS

### TC-2: Input Validation
- Valid input (A, B, C, D): Accept
- Invalid input (E, numbers, special chars): Reject
- Empty input: Reject and prompt retry

### TC-3: Score Calculation
- All correct answers: 100%
- All wrong answers: 0%
- Partial correct (3/5): 60%

### TC-4: Performance Rating
- 80-100%: Excellent
- 60-79%: Good  
- Below 60%: Needs Improvement

## Integration Tests

1. Load questions file
2. Display question loop
3. Accept and validate user input
4. Calculate and display results

## Edge Cases

- Empty questions.txt
- Malformed question data
- Single question quiz
- Maximum 50 questions

## Compilation

```bash
gcc -Wall -Wextra -Werror quiz.c -o quiz
```

Must compile with ZERO warnings.
