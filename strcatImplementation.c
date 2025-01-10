#include <stdio.h>
#include<string.h>

int stringLength(char *string){
    int length=0;
    while(string[length]!='\0'){
        length++;
    }
    return length;
}

void strcatImplementation(char string1[],char string2[]){
    int lengthOfString1=stringLength(string1);
    int lengthOfString2=stringLength(string2);
    
    int index1=lengthOfString1;
    int index2=0;
    while(string2[index2]!='\0'){
        string1[index1++]=string2[index2++];
    }
    printf("Contatinated String is %s\n",string1);
}

int main() {
    char string1[100];
    char string2[100];
    
    printf("Enter the Original String\n");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0'; 
    
    printf("Enter the String for concatination\n");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0'; 
    
    strcatImplementation(string1,string2);
   

    return 0;
}

