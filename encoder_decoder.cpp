#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{

cout << "\nWelcome to ENGR1200U Cryptographic Techniques Program\n\n";
cout << "Please enter your selection:\n\n";
cout << "\t1. Encript\n";
cout << "\t2. Decrypt\n";

int selection;
cin >> selection;

ifstream inputfile;
ofstream outputfile;

if (selection == 1)
{
 string encrypt_file;
 cout << "Please enter the file you would like to encrypt: ";
 cin >> encrypt_file;
 
 inputfile.open(encrypt_file.c_str());
 outputfile.open("decrypt_file.out");
 while (!inputfile.eof())
 {
  char letters = inputfile.get();
  //inputfile >> letters;
 
  if (letters >= 65 && letters <= 90)
  {
   letters = (letters - 'A' + 5) % 26 + 'A';
   outputfile << letters;
  } 
  else if (letters == 10)
  {
  outputfile << letters;
  }
  else if (letters == 32)
  {
  outputfile << letters;
  }
  else if(!(letters >= 65 && letters <= 90))
  {
  outputfile << letters;
  }
 }
 
}
inputfile.close();
outputfile.close();
return 0;
}
