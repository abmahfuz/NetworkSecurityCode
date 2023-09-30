#include<bits/stdc++.h>
using namespace std;
int main()
{
    char text[100],ch;
    int i,key;
    cout << "Enter the cipher Text to decrypt:";
    cin.getline(text,100);
    cout << "Enter shift key:";
    cin >> key;
    for (i = 0; text[i] != '\0'; i++)
    {
        ch = text[i];
        if(text[i] == 32 || text[i] == ',')
            continue;
        else
        {
            if( ch >= 'a' && ch <= 'z')
            {
                ch = ch - key;
                if( ch < 'a')
                {
                    ch = ch + 'z' - 'a' + 1;
                }
                text[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                ch = ch - key;
                if( ch > 'a')
                {
                    ch = ch + 'Z' - 'A' + 1;
                }
                text[i] = ch;
            }
        }

    }
    string decryptedText;
    for( i = 0; text[i] != '\0'; i++)
    {
        if(text[i] != ' ' && text[i] != ',')
            decryptedText += text[i];
    }
    cout << "Decrypted Text is: "<< decryptedText;
}
