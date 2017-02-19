#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool checkKey();
string getText();
int getTextLength(char* text);
int* setKeycode();
void encryptText(int length, int* keycode);
char caesar(char text1, int key1);

string key;
string input_text="";
int keycode_length;

int main(int argc, string argv[]){
    if (argc==2)
    {
        key = argv[1];
    }
    else
    {
        printf("Usage: ./caesar <key> \n");
        return 1;
    }
    if (!checkKey()){
       return 1; 
    }
    encryptText(getTextLength(getText()), setKeycode());
    printf("\n");
    return 0;
}

bool checkKey(){
    int length = strlen(key);
    for(int i = 0; i < length; i++)
    {
        if(!isalpha(key[i]))
        {
        printf("Error. You must input letters only.\n");
        return false;
        }
    }
    return true;
}

string getText(){
    printf("plaintext: ");
    input_text = GetString();
    return input_text;
}

int getTextLength(char* text){
    int length = strlen(text);
    return length;
}

int* setKeycode(){
    keycode_length = strlen(key);
    int* p= calloc(keycode_length, sizeof(int*));
    for(int i = 0; i < keycode_length;i++)
    {
        p[i] = toupper(key[i]) - 65;
    }
    return p;
}

void encryptText(int length, int* keycode){
    int key_count=0;
    printf("ciphertext: ");
    for(int i = 0; i < length; i++){
        if(!isalpha(input_text[i]))
        {
            printf("%c", input_text[i]);
            
        }
        else
        {
            printf("%c", caesar(input_text[i], keycode[key_count]));
            if(key_count < keycode_length-1)
            {
                key_count++;
            }
            else
            {
                key_count = 0;
            }
        }
    }
}

char caesar(char text1, int key1){
    if(islower(text1))
    {
        return ((((text1 - 97)+key1)%26)+97);
    }
    else
    {
        return ((((text1 - 65)+key1)%26)+65);
    }
}