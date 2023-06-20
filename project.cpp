#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string encode(string plain_text, int shift)
{
  string cipher_text = "";
  for (int i = 0; i < plain_text.length(); i++) {
    char c = plain_text[i];
    if (isalpha(c)) {
      char shift_char = char(((toupper(c) - 'A' + shift) % 26) + 'A');
      if (islower(c)) {
	shift_char = tolower(shift_char);
      }
      cipher_text += shift_char;
    } else {
      cipher_text += c;
    }
  }
  return cipher_text;
}

string decode(string cipher_text, int shift)
{
  string plain_text = "";
  for (int i = 0; i < cipher_text.length(); i++) {
    char c = cipher_text[i];
    if (isalpha(c)) {
      char shift_char = char(((toupper(c) - 'Z' - shift) % 26) + 'Z');
      if (islower(c)) {
	shift_char = tolower(shift_char);
      }
      plain_text += shift_char;
    } else {
      plain_text += c;
    }
  }
  return plain_text;
}

int  menu(int var)
{
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
  cout <<"Here are your options: \n" 
       <<"Enter 1 : to encrypt a message \n"  
       <<"Enter 2 : to decode by one shift \n" 
       <<"Enter 3 : to decode by all shifts \n"
       <<"Enter 4 : to learn about the Caesar Cipher \n"
       <<"Enter 5 : to quit the program \n";
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
  cin >> var;
  return var;
}

int main() 
{
  int var, input2;
  string plain_text, cipher_text;
  int shift;
  cout << "Welcome to our encryption and decryption program.\n"
       << "This program will allow you to encrypt or decrypt any message with the Caesar Cipher. You will have the choice to decode by all shifts or by a select shift." << endl;
  int input = menu(var);
 while(input != 5)
    {
      if(input == 1)
	{
	  input2 = 1;
	  while(input2 == 1)
	    {
	      cout << "Please enter the message you want to encrypt(no spaces): \n";
	      cin >> plain_text;
	      cout << "Please enter the shift you want(any integer from 1-25): \n";
	      cin >> shift;
	      string cipher_text = encode(plain_text, shift);
	      cout << "Encoded Message: " << cipher_text << endl;
	      cout << "Enter (1) to encode another message or (2) to display menu again" << endl;
	      cin >> input2;
	    }
	}
      else if(input == 2)
	{
	  input2 = 1;
	  while(input2 == 1)
	    {
	      cout << "Please enter the message you want to decypt: \n";
	      cin >> cipher_text;
	      cout << "Please enter the shift you want to decode by(any integer from 1-25): \n";
	      cin >> shift;
	      string decoded_text = decode(cipher_text, shift);
	      cout << "Decoded Message: " << decoded_text << endl;
	      cout << "Enter (1) to decode another message or (2) to display menu again" << endl;
              cin >> input2;
	    }
	}
      else if(input == 3)
        {
	  input2 = 1;
	  while(input2 == 1)
	    {
	      cout << "Please enter the message you want to decypt: \n";
	      cin >> cipher_text;
	      for(shift = 1; shift <= 26; shift++)
		{
		  string decoded_text = decode(cipher_text, shift);
		  cout << "Shift: " << shift <<", Decoded Message: " << decoded_text << endl;
		}
	      cout << "Enter (2) to display menu again" << endl;
	      cin >> input2;
	    }
	}
      else if(input == 4)
	{
	  input2 = 1;
	  while(input2 == 1)
	    {
	      cout << "The Caesar Cipher" << endl;
	      cout << "The Caesar cipher is a simple encryption technique that has been used for many centuries to protect sensitive information.\n" 
	       << "It involves shifting the letters of the plaintext by a certain number of positions in the alphabet.\n"
	       << "For example encypting the word 'and' by a shift of 1 would result in the encrypted text: boe. A shift of 2 would result in the encrypted text: cpf.\n"
	       << "Despite its simplicity, the Caesar cipher can still be a useful tool for encoding messages in situations where a basic level of security is required.\n"; 
	      cout << "Enter (2) to display menu again" << endl;
	      cin >> input2;
	    }
	}
      input = menu(var);
    }
 cout << "Thanks for using our program!\n";
  return 0;
}
