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
            for (int j = i + 1; j < info.length(); j++) {
                if (info[i] == info[j]) {
                    count++;
                } else {
                    break;
                }
            }
            encrypted += info[i];
            encrypted += to_string(count);
            i += count;
        }
    }

    void decrypt(string encryptedText) {
        decrypted = "";
        int i = 0;
        while (i < encryptedText.length()) {
            char currentChar = encryptedText[i];
            i++;
            string countStr;
            while (i < encryptedText.length() && isdigit(encryptedText[i])) {
                countStr += encryptedText[i];
                i++;
            }
            int count = stoi(countStr);  
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
