# Inverted Search

A command-line interface-based program for indexing and querying words from multiple text files.  
The program creates a sorted index of words and enables efficient searching across files.

## Features
- **Indexing**: Parse and index words from multiple text files into a database file.
- **Querying**: Search the database for specific words and retrieve file details.
- **Efficient Data Handling**: Uses a linked list to store and manage indexed words.

## Compiling the Program

### Compile the program:
```bash
$ cd InvertedSearch
$ chmod +x *.c
$ gcc *.c -o inverted_search
