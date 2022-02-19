//
//  main.cpp
//  CaeserCipher
//
//  Created by Daniel Mai Fisher on 2/12/22.
//  Copyright © 2022 Daniel Mai Fisher. All rights reserved.
//

#include <iostream>

int generateKey1(){
    // Generate a random key for each message which will be embeded later
    int key = 1 + rand() % 12;
    return key;
}

std::string encrypt1(int key, std::string message){
    std::string encrypted_message = "";
    encrypted_message += char(key);
    
    for (int i = 0; i<message.length(); i++) {
        char ch = message[i];
        //encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
        }
        //encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
        }
        
        encrypted_message += ch;
    }
    return encrypted_message;
}


std::string decrypt1(std::string message){
    std::string decrypted_message = "";
    char ch;
    //extract hidden key
    int hkey=int(message[0]);
    
    for(int i = 1; i<=message.length(); i++) {
        ch = message[i];
        
        //decrypt for lowercase letter
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - hkey;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            
        }
        //decrypt for uppercase letter
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - hkey;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            
        }
        
        decrypted_message += ch;
    }
    
    return decrypted_message;
}


int main(int argc, const char * argv[]) {
    std::string cont = "";
    do {
        int key1 = 0;
        std::string message = "";
        std::string encrypted_meesage = "";
        std::string decrypted_message = "";
        
        // Get user input
        std::cout<<"Enter sentance you want encrypted: ";
        std::getline(std::cin, message);
        
        // Generate Message
        key1 = generateKey1();
        encrypted_meesage = encrypt1(key1, message);
        decrypted_message = decrypt1(encrypted_meesage);
        
        // Display Message
        std::cout<<"Encrypted Message: "+ encrypted_meesage<<std::endl;
        std::cout<<"Decrypted Message: "+ decrypted_message<<std::endl;
        std::cout<<""<<std::endl;
        
        // Ask to continue
        std::cout<<"Would you like to continue (y/n)?: ";
        std::cin>>cont;
        std::cin.ignore();
        
        
    } while (cont == "y");
    
    return 0;
}


