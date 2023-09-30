#include<bits/stdc++.h>
using namespace std;
int main()
{
    char text[100], ch;
    int i, key;
    cout << "Enter the plain text to encrypt:";
    cin.getline(text,100);
    cout << "Enter shift key:";
    cin >> key;
    for( i = 0; text[i] != '\0'; i++)
    {
        ch = text[i];
        if(text[i] == 32 || text [i] == ',')
        {
            continue;
        }
        else
        {
            if( ch >= 'a' && ch <= 'z')
            {
                ch = ch + key;
                if( ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
                text[i] = ch;
            }
            else if ( ch >= 'A' && ch <= 'Z')
            {
                ch = ch + key;
                if( ch > 'Z')
                {
                    ch = ch - 'Z'+ 'A' - 1;
                }
                text[i] = ch;
            }
        }

   }
    string encryptedText;
    for( i = 0; text[i] != '\0'; i++)
        if(text[i] != ' ' && text[i] != ',') encryptedText += text[i];
    cout << "Encrypted Text is: " << encryptedText;
}
