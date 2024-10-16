# Caesar Cipher

This script implements a Caesar cipher for encrypting and decrypting messages.
The Caesar cipher shifts each letter in the message by a specified key value.

This script only processes uppercase letters and spaces.

## Regexs for validating input
- re_cap_letter: Matches uppercase letters and spaces
- re_key: Matches numeric values

## Functions: 
- prompt() 
    - Displays a prompt message and waits for user input.
    - Parameters: $1 {message}

- validate_msg()
    - Validates that message contains only uppercase letters and spaces.
    - Parameters: $1 {message}.

- validate_key()
    - Validates that the key is a number between 0 and 25.
    - Parameters: $1 {key}

- caesar_cipher()
    - Combines message and key validation into one logic. It also uses `process()` to encrypt or decrypt as needed
    - Parameters: $1 {operation ('e' for encryption, 'd' for decryption).}

- process()
    - Processes the message by shifting each letter according to the key, depending on the operation
    - Parameters: 
        - $1 {operation ('e' or 'd')}
        - $2 {message}
        - $3 {key}.
