# Inverted Search

A command-line interface-based program for indexing and querying words from multiple text files.  
The program creates a sorted index of words and enables efficient searching across files.

## Features
- **Indexing**: Parse and index words from multiple text files into a database file.
- **Querying**: Search the database for specific words and retrieve file details.
- **Efficient Data Handling**: Uses a linked list to store and manage indexed words.

## Compiling the Program
1. <b>Compile the program : </b>
  ```
 $ cd InvertedSearch
$ chmod +x *.c
$ gcc *.c -o inverted_search
  ```

## Running the Program

### Indexing Files
1. Place the text files to be indexed inside the `InvertedSearch` directory.
2. Run the following command to create the index:
   ```bash
   $ ./inverted_search -i file1.txt file2.txt file3.txt
