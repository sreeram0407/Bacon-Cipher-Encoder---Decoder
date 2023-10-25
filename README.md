# Bacon Cipher Encoder & Decoder

## Description
This C++ project, authored by Sreeram Kondapalli, is inspired by Francis Bacon’s Cipher. It enables encryption and decryption of text files, translating English characters into cipher patterns and vice versa. A command-line interface is provided for ease of operation, accompanied by robust error handling mechanisms.

## Features
- **Encryption (Baconization):** Converts English characters into corresponding Bacon codes.
- **Decryption (Englishization):** Converts Bacon codes back into English characters.
- **Command-Line Interface:** Facilitates cipher operations via command-line arguments.
- **Error Handling:** Manages invalid user inputs, such as incorrect file paths or usage syntax, gracefully.
- **File I/O:** Handles reading from and writing to files, ensuring data accuracy and user-friendliness.

## Usage

Execute the application from the command line, specifying the operation, input file, and output file.

### Syntax

```bash
<executable> <input file> <-bc|-e> <output file>
