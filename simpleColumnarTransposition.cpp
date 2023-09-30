#include<bits/stdc++.h>
using namespace std;
string key;
map<int,int> keymap;
void setPermutationOrder()
{
    for ( int i = 0; i < key.length(); i++)
    {
        keymap[key[i]] = i;
    }
}
string encryptMessage(string text)
{
    int row,col, j;
    string cipher = "";
    col = key.length();
    row = text.length()/col;
    if(text.length() % col)
    {
        row += 1;

    }
    char matrix[row][col];
    for( int i = 0,k=0; i < row; i++)
    {
        for( int j = 0; j < col;)
        {
            if(text[k] == '\0')
            {
                matrix[i][j] = '_';
                j++;
            }
            if(isalpha(text[k] || text[k] == ' '))
            {
                matrix[i][j] = text[k];
                j++;
            }
            k++;
        }
    }
    for( map<int,int>:: iterator ii = keymap.begin(); ii != keymap.end(); ++ii)
    {
        j = ii-> second;
        for( int i = 0; i < row; i++)
        {
            if(isalpha(matrix[i][j] || matrix[i][j] == ' '|| matrix[i][j] == '_'))
            {
                cipher += matrix[i][j];
            }
        }
    }
    return cipher;
}
string decryptMessage(string text)
{
    int col = key.length();
    int row = cipher.length()/col;
    char cipherMat[row][col];
    for(int j = 0,k=0;j<col; j++)
        for(int i = 0; i< row; i++)
            cipherMat[i][j] = cipher[k++];
    int index = 0;
    for(map<int,int>:: iterator ii = keymap.begin(); ii != keymap.end(); ++ii)
        ii -> second = index++;
    char decCipher [row][col];
    map<int,int>

}
int main(void)
{
   string text, key;
   cout << "Enter text to encrypt:";
   getline(cin,text);
   cout << "Enter keyword:";
   getline(cin,key);
   setPermutationOrder();
   string cipher = encryptMessage(text);
   cout << "Encrypted Text:" << cipher << endl;
   cout << "Decrypted Text:" << decryptMessage(cipher)<< endl;
   return 0;
}
