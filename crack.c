#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings


// Given a target plaintext word, use it to try to find
// a matching hash in the hashFile.
// Get this function working first!
char * tryWord(char * plaintext, char * hashFilename)
{
    // Hash the plaintext
	char *pointer = md5(plaintext, strlen(plaintext));
    // Open the hash file
	FILE *h = fopen(hashFilename, "r");
    // Loop through the hash file, one line at a time.
	char hash[HASH_LEN];
	while (fgets(hash, HASH_LEN, h)){
		char *nl = strchr(hash, '\n');
        if(nl) *nl = '\0';
    // Attempt to match the hash from the file to the
    // hash of the plaintext.
    // If there is a match, you'll return the hash.
    // If not, return NULL.
		if (strcmp(pointer, hash) == 0){
            fclose(h);
            return pointer;
        }
    // Before returning, do any needed cleanup:
    //   Close files?
    //   Free memory?
	}
	fclose(h);
    free(pointer);
    // Modify this line so it returns the hash
    // that was found, or NULL if not found.
    return 0;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

	FILE *dictionary = fopen(argv[2], "r");
	int cracked = 0;
    // These two lines exist for testing. When you have
    // tryWord working, it should display the hash for "hello",
    // which is 5d41402abc4b2a76b9719d911017c592.
    // Then you can remove these two lines and complete the rest
    // of the main function below.
	char word[PASS_LEN];
	while(fgets(word, PASS_LEN, dictionary)){
		char *nl = strchr(word, '\n');
		if(nl) *nl = '\0';
		char *found = tryWord(word, argv[1]);
		
		
		
		
		
		if(found){
			printf("%s %s\n", found, word);
			cracked++;
			free(found);
		}

	}
    // Open the dictionary file for reading.
    

    // For each dictionary word, pass it to tryWord, which
    // will attempt to match it against the hashes in the hash_file.
    
    // If we got a match, display the hash and the word. For example:
    //   5d41402abc4b2a76b9719d911017c592 hello
    
    // Close the dictionary file.
	printf("%d hashes cracked\n", cracked);
	fclose(dictionary);
    // Display the number of hashes that were cracked.
    
    // Free up any malloc'd memory?
}

