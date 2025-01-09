Inverted Search
A command-line interface-based program for indexing and querying words from multiple text files.
The program creates a sorted index of words and enables efficient searching across files.

Features
Indexing: Parse and index words from multiple text files into a database file.
Querying: Search the database for specific words and retrieve file details.
Efficient Data Handling: Uses a linked list to store and manage indexed words.
Compiling the Program
Compile the program:
bash
Copy code
$ cd InvertedSearch
$ chmod +x *.c
$ gcc *.c -o inverted_search
Running the Program
Indexing Files
Place the text files to be indexed inside the InvertedSearch directory.
Run the following command to create the index:
bash
Copy code
$ ./inverted_search -i file1.txt file2.txt file3.txt
This creates a database file storing the indexed words and their file references.
Querying the Index
To search for specific words in the indexed files, use the following command:
bash
Copy code
$ ./inverted_search -q "word_to_search"
The program will output a list of files containing the specified word, along with match counts.
Example Usage
Index Files:

bash
Copy code
$ ./inverted_search -i file1.txt file2.txt  
Output:

Copy code
Index created successfully. Stored in index.db.
Query Word:

bash
Copy code
$ ./inverted_search -q "example"
Output:

sql
Copy code
Found in:  
file1.txt (3 matches)  
file2.txt (1 match)  

