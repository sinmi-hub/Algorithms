# ASCII Converter

## Description

ASCII Converter is a simple cipher program that encrypts an uppercase letter using a numerical key. This is mostly done using bash scripting

## Features

- Accepts an uppercase letter input
- Accepts a numerical key (0-9) input
- Encrypts the letter by shifting it to the right based on the key value
- Handles wrapping from 'Z' back to 'A'
- Provides error handling for invalid inputs

## How It Works

1. The program prompts the user for an uppercase letter.
2. It then asks for a key (a number between 0 and 9).
3. If both inputs are valid:
   - The program shifts the letter to the right by the key value.
   - It outputs the encrypted letter.
4. If either input is invalid, it displays an error message.

## ASCII Conversion

The program uses bash's built-in ASCII conversion capabilities:

- To get the ASCII value of a character:
  ```bash
  letter="A"
  value=$(printf "%d" "'$letter")
  ```

- To get the ASCII character from a value:
  ```bash
  value="65"
  char=$(printf "%b" "$(printf "\\%03o" "$value")")
  ```
