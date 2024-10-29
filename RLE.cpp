#include <iostream>
#include <string>
using namespace std;

class RLE {
private:
    string info;
    string encrypted;
    string decrypted;
public:
    RLE() {}

    RLE(string input) {
        info = input;
    }

    void encrypt() {
        encrypted = "";
        int i = 0;
        while (i < info.length()) {
            int count = 1;
            while (i + 1 < info.length() && info[i] == info[i + 1]) {
                count++;
                i++;
            }
            encrypted += info[i];
            char asciiCount[3];
            int len = 0;

            while (count > 0) {
                asciiCount[len++] = (count % 10) + '0';
                count /= 10;
            }

            for (int k = 0; k < len / 2; k++) {
                swap(asciiCount[k], asciiCount[len - 1 - k]);
            }

            asciiCount[len] = '\0';
            encrypted += asciiCount;
            i++;
        }
    }

    void decrypt(string encryptedText) {
        decrypted = "";
        int i = 0;
        while (i < encryptedText.length()) {
            char currentChar = encryptedText[i];
            i++;
            int count = 0;
            while (i < encryptedText.length() && isdigit(encryptedText[i])) {
                count = count * 10 + (encryptedText[i] - '0');
                i++;
            }
            for (int j = 0; j < count; j++) {
                decrypted += currentChar;
            }
        }
    }

    void displayEncrypted() {
        cout << "Encrypted text is: " << encrypted << endl;
    }

    void displayDecrypted() {
        cout << "Decrypted text is: " << decrypted << endl;
    }
};

int main() {
    string input, encryptedInput;
    cout << "Enter a string to encrypt: ";
    cin >> input;
    RLE rle(input);
    rle.encrypt();
    rle.displayEncrypted();

    cout << "Enter an encrypted string to decrypt: ";
    cin >> encryptedInput;

    RLE decryptor;
    decryptor.decrypt(encryptedInput);
    decryptor.displayDecrypted();

    return 0;
}
