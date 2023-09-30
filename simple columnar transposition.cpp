#include<bits/stdc++.h>
using namespace std;

class RowTranspositionCipher {
    char** matrix;
    int noRows, noCols;

public:
    void setMatrix(string msg, string key) {
        int rmdr;
        noCols = key.length();
        if ((rmdr = msg.length() % noCols) == 0)
            noRows = msg.length() / noCols;
        else {
            rmdr = msg.length() % noCols;
            noRows = (msg.length() / noCols) + 1;
            for (int i = 1; i <= noCols - rmdr; i++)
                msg += "x";
        }

        matrix = new char*[noRows];
        for (int i = 0; i < noRows; i++) {
            matrix[i] = new char[noCols];
            for (int j = 0; j < noCols; j++) {
                matrix[i][j] = msg[i * noCols + j];
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    string encrypt(string msg, string key) {
        setMatrix(msg, key);
        string enc = "";
        int c = 0;
        for (int i = 0; i < noCols; i++) {
            for (int k = 0; k < noCols; k++) {
                if ((int)key[k] - 48 == i + 1) {
                    c = k;
                }
            }

            for (int j = 0; j < noRows; j++) {
                enc += matrix[j][c];
            }
        }
        cout << "Encrypted message: " << enc << endl;
        return enc;
    }

    void decrypt(string msg, string key) {
        string part, dec = "";
        int c = 0;
        for (int i = 0; i < noCols; i++) {
            part = msg.substr(i * noRows, noRows * (i + 1));

            for (int k = 0; k < noCols; k++) {
                if ((int)key[k] - 48 == i + 1) {
                    c = k;
                }
            }

            for (int j = 0; j < noRows; j++) {
                matrix[j][c] = part[j];
            }
        }

        for (int i = 0; i < noRows; i++) {
            for (int j = 0; j < noCols; j++) {
                dec += matrix[i][j];
            }
        }
        cout << "Decrypted message: " << dec << endl;
    }

    void intro() {
        cout << "\t ROW TRANSPOSITION CIPHER" << endl;
        cout << "Enter the message: ";
        string message;
        getline(cin, message);
        message.erase(remove_if(message.begin(), message.end(), ::isspace), message.end());
        transform(message.begin(), message.end(), message.begin(), ::tolower);

        cout << "Enter the key: ";
        string key;
        getline(cin, key);
        transform(key.begin(), key.end(), key.begin(), ::tolower);

        decrypt(encrypt(message, key), key);
    }
};

int main() {
    RowTranspositionCipher rtc;
    rtc.intro();
    return 0;
}
