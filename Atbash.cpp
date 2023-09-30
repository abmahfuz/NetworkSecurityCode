
#include <iostream>

using namespace std;

void cipherEncryption(){
    string message;
    cout << "Enter Message: ";
    getline(cin, message);


    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string encryText = "";

     for(int i=0;i<message.length();i++) {
        if(message[i]==' ') {
            encryText += ' ';
            continue;
        }

         int x,y;


         x=message[i]-'A';


         y=(x+18)%26;

          char ch=alpa[y];

          encryText+=ch;
      }

      cout<<"Encrypted Text: "<<encryText<<endl;

}

void cipherDecryption(){
    string message;
    cout << "Enter Encrypted Message: ";
    getline(cin, message);

    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string dencryText = "";

     for(int i=0;i<message.length();i++) {
        if(message[i]==' ') {
            dencryText += ' ';
            continue;
        }

         int x,y;


         y=message[i]-'A';


         x=(y+8)%26;

          char ch=alpa[x];

          dencryText+=ch;
      }

      cout<<"Decrypted Text: "<<dencryText<<endl;

}

int main()
{
    int choice;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();

    if(choice == 1){
        cout << "Encryption" << endl;
        cipherEncryption();
    } else if (choice == 2){
        cout << "Decryption" << endl;
        cipherDecryption();
    } else {
        cout << "Wrong Choice" << endl;
    }
    return 0;
}
