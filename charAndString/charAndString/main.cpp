#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[]) {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string decrypted_message {};
    string decrypting_message {};
    
    getline(cin, decrypted_message);
    for(auto message: decrypted_message) {
        size_t index = alphabet.find(message);
        if(index != string::npos){
            decrypting_message.push_back(key.at(index));
        } else {
            decrypting_message.push_back(message);
        }
        
    };
    
    cout << decrypting_message << endl;
    
    decrypted_message.clear();
    for(auto message: decrypting_message) {
        size_t index = key.find(message);
        if(index != string::npos){
            decrypted_message += alphabet.at(index);
        } else {
            decrypted_message += message;
        }
    };
    
    cout << decrypted_message << endl;
    
    decrypted_message.at(0) = 'P';
    cout << decrypted_message << endl;

    
    return 0;
}


