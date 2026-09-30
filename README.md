# Bacon Cipher Encoder & Decoder

A C++ command-line program that converts text files to and from Bacon’s cipher. Letters are represented by five-character patterns of `a` and `b`.

## Build and run

From the repository root, compile with a C++ compiler:

```bash
g++ -std=c++11 main.cpp -o bacon_cipher
```

Encode a text file, then decode the result:

```bash
./bacon_cipher input.txt -bc encoded.txt
./bacon_cipher encoded.txt -e decoded.txt
```

The argument order is `<input file> <-bc|-e> <output file>`. Supply all three arguments and use different input and output paths.

## Encoding format

- `A`–`Z` and `a`–`z` share the same codes; decoded letters are uppercase.
- Encoded characters are separated by `|`; spaces use `/`.
- Unsupported characters encode as `!!!!!` and decode as `#`.

This is an educational implementation of a historical cipher. Input is processed with fixed-size line buffers.

## Files

- [main.cpp](main.cpp): command-line parsing, file processing, and cipher mappings.

**Author:** Sreeram Kondapalli
