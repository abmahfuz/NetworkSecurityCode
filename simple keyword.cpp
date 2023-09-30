/*#include <iostream>
#include <string>

using namespace std;

// Function to encrypt plaintext using a given substitution key
string encrypt(string plaintext, string substitution_key) {
    string ciphertext = "";

    for (char c : plaintext) {
        if (isalpha(c)) { // Only substitute letters
            char sub_char = substitution_key[toupper(c)-'A']; // Find corresponding letter in key
            if (islower(c)) sub_char = tolower(sub_char); // Preserve original case of input character

            ciphertext += sub_char;
        } else {
            ciphertext += c; // Non-letter characters are added as is
        }
    }

    return ciphertext;
}

int main() {
  string plain_text=" A THREE HOUR TOUR";
  string keyword="GILLIGAN";

  cout << "Plain Text: " << plain_text << endl;

  // Generate substitution key from given keyword (removing duplicates and spaces)
  string sub_key="";

   for(char& ch : keyword){
       if(isalpha(ch)){
           int pos=sub_key.find(toupper(ch));

           if(pos==string::npos)
               sub_key+=toupper(ch);
       }
   }

   for(char ch='A';ch<='Z';++ch){
       int pos=sub_key.find(ch);

       if(pos==string::npos)
          sub_key+=ch;
   }


  cout<<"Sub Key: "<<sub_key<<endl;

  // Encrypt plaintext using substitution key
  string cipher_text=encrypt(plain_text,sub_key);

  cout<<"Cipher Text: "<<cipher_text<<endl;
}*/
#include <iostream>
using namespace std;

int main() {
    char text[1000], ch;
    int i, key;
    cout << "Enter the Plain Text to encrypt: ";
    cin.getline(text, 1000);
    cout << "Enter Shift key: ";
    cin >> key;
    cin.ignore(); // Ignore the newline character left in the buffer after reading the key

    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = ch + key;
                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }
                text[i] = ch;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                text[i] = ch;
            }

    }
    cout << "Encrypted text is: " << text;

    return 0;
}
