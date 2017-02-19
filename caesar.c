#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

string getText();
int getLength(char* text);
void encryptText(int length, char* text);

int key;
string txt="";

int main(int argc, string argv[]){
    if (argc==2)
    {
        key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar <key>");
        return 1;
    }

    encryptText(getLength(getText()),txt);
    printf("\n");
    return 0;
}

string getText(){
    printf("plaintext: ");
    txt = GetString();
    return txt;
}

int getLength(char* text){
    int length = strlen(text);
    return length;
}

void encryptText(int length, char* text){
    printf("ciphertext: ");
    for(int i = 0; i < length; i++){
          if(isalpha(text[i]))
        {
            if(islower(text[i]))
            {
                printf("%c", ((((text[i] - 97)+key)%26)+97));
            }
            else
            {
                printf("%c", ((((text[i] - 65)+key)%26)+65));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}