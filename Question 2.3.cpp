/*This program prompts the user whether to encrpyt or decrypt a file.
Once the use chooses what they want to do, the files encrypt_file and
decrypt_file contain the encrypted/decrypted characters.*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
	// prompts the user to either encrypt or decrypt
cout << "\nWelcome to ENGR1200U Cryptographic Techniques Program\n\n";
cout << "Please enter your selection:\n\n";
cout << "\t1. Encript\n";
cout << "\t2. Decrypt\n";

int selection;
cin >> selection;

// opens the files to be encypted and where the decrypted data will go
ifstream inputfile;
ofstream outputfile;

//if the user wants to encript
if (selection == 1)
{
 //promps the user what file they want to encript and what file they
// want their encrypted file to go to
 string encrypt_file;
 cout << "Please enter the file you would like to encrypt: ";
 cin >> encrypt_file;
 
 string decrypt_file;
 cout << "\nPlease enter the name of the file you would like your encrypted text to be held in: ";
 cin >> decrypt_file;
 
 //open the files
 inputfile.open(encrypt_file.c_str());
 outputfile.open(decrypt_file.c_str());
 
 //while the file being encrypted is not at the end
 while (!inputfile.eof())
 {
  // get each character and perform different tasks to get desired result
  char letters = inputfile.get();
  if (isalpha(letters))
  {
   letters = (letters - 'A' + 5) % 26 + 'A';
   outputfile << letters;
  } 
  else if (ispunct(letters))
  {
	 outputfile << letters;
  }
  else if(letters == 10)
  {
	  outputfile << letters;
  }
  else if(letters = 32)
  {
	  outputfile << letters;
  }
 }
}
// If the user would like to decrypt a file
if (selection == 2)
{
	//prompts the user to enter what file they want to decrypt and
	//what file they want their decryped data to go in
	string decrypt_file, encrypt_file;
	cout << "Please enter the file you would like to decrypt: ";
	cin >> decrypt_file;
 
	cout << "\nPlease enter the file you would like your decrypted text to be held in: ";
	cin >> encrypt_file;

 inputfile.open(decrypt_file.c_str());
 outputfile.open(encrypt_file.c_str());
 while (!inputfile.eof())
 {
	 //takes each letter from the file and converts it to get desired
	 //output
	char letters = inputfile.get();
	if (letters >= 69 && letters <= 90)
	{
	letters = (letters - 'A') % 26 + 'A' - 5;
	outputfile << letters;
	} 
	else if(letters == 'B')
	{
		outputfile << 'W';
	}
	else if(letters == 'D')
	{
		outputfile << 'Y';
	}
	else if (ispunct(letters))
	{
		outputfile << letters;
	}
	else if (letters == 32)
	{
		outputfile << letters;
	}
	else if (letters == 10)
	{
		outputfile << letters;;
	}

}
}

// close the files and end the program
inputfile.close();
outputfile.close();
system("pause");
return 0;
}
