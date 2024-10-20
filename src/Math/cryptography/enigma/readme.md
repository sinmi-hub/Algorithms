# Enigma File Encryption Tool

A cmd tool that provides secure file encryption and decryption using OpenSSL's AES-256-CBC encryption standard. This allows users to create, read, encrypt, and decrypt text files with password protection.

## Features

- Create text files with messages
- Read file contents
- Encrypt files using OpenSSL (AES-256-CBC)
- Decrypt encrypted files with password verification
- Password-based encryption using PBKDF2
- Simple command-line interface

## Requirements

- Bash shell environment
- OpenSSL installed on your system
- Basic command line knowledge

## Installation

1. Ensure OpenSSL is installed on your system:
```bash
openssl version
```

2. Clone or download the Enigma script
3. Make the script executable: (LMAO - At your own peril)
```bash
chmod +x enigma.sh
```

## Usage

Run the script:
```bash
./enigma.sh
```

### Menu Options

The tool provides four main operations:

1. **Create a file** - Create a new text file with a message
2. **Read a file** - Display the contents of an existing file
3. **Encrypt a file** - Encrypt a file using OpenSSL with password protection
4. **Decrypt a file** - Decrypt an encrypted file using the correct password

### File Naming Convention

- Regular files can have any name with letters and dots (e.g., `message.txt`)
- Encrypted files automatically get the `.enc` extension (e.g., `message.txt.enc`)

## Security Features

- Uses AES-256-CBC encryption algorithm
- Uses PBKDF2 (Password-Based Key Derivation Function 2)
- Salt is used with password 
- Secure password input

## Technical Details && Dependencies

Encryption and decryption use the following OpenSSL commands:

### Encryption
```bash
openssl enc -aes-256-cbc -e -pbkdf2 -salt -in "$file_name" -out "$output_file" -pass pass:"$password"
```

### Decryption
```bash
openssl enc -aes-256-cbc -d -pbkdf2 -salt -in "$file_name" -out "$output_file" -pass pass:"$password"
```

## Notes

- Files are automatically deleted after encryption/decryption
- Original file is replaced with encrypted/decrypted version
- Invalid passwords during decryption will result in a "Fail" message
- Only uppercase letters and spaces are allowed in messages
