# Phone Number Word Generator

This project takes a 7-digit phone number as input and generates all possible word combinations using the classic phone keypad mapping. It checks these combinations against an English dictionary to identify valid words and outputs them to a file.

## Features
- Generates word combinations from phone numbers.
- Filters valid words based on a dictionary.
- Outputs results to a text file.

## How It Works
1. **Input:** The user provides a 7-digit phone number (digits 2-9 only).
2. **Word Generation:** The program generates all possible combinations of letters for the given number.
3. **Validation:** These combinations are checked against a dictionary of English words.
4. **Output:** Valid words are saved in `output.txt`.

## Files
- `GenerateWordMethod.c`: The main source code for the project.
- `GenerateWordMethod.exe`: The compiled executable file (for Windows users).
- `words_alpha.txt`: A dictionary file containing English words.

## How to Run
1. Ensure words_alpha.txt is in the same directory as the executable or compiled binary.
2. Run the executable:
  ./GenerateWordMethod.exe
