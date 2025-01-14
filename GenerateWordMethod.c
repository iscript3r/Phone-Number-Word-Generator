#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DICTIONARY_SIZE 420000
void WordGenerator(int PhoneNumber[] , char* Dictionary[], FILE *OutputFile ) ;
char** ReadDictionary() ;


char** ReadDictionary() {
    FILE *Dictionary = fopen("words_alpha.txt", "r");
    int i = 0 ;
    int wordCount = 0 ; 
    char line[8];
    if (Dictionary) {
    while (fgets(line, sizeof(line), Dictionary) != NULL) {
        wordCount++;
    } 
        fseek(Dictionary, 0, SEEK_SET);
        char **dict = (char**)malloc(wordCount * sizeof(char*)) ; 

        if (!dict) {
        perror("Memory Allocation Error");
        fclose(Dictionary);
        return NULL;
    }
        for ( i = 0 ; i < wordCount ; i++) {
            dict[i] = (char*)malloc(8 * sizeof(char*)) ;
            if (!dict[i]) {
            perror("Memory Allocation Error");
            fclose(Dictionary);
            return NULL;
        } 
            if(fgets(dict[i] , 8 , Dictionary ) == NULL){
                fclose(Dictionary);
                printf("Error") ; 
                return NULL;
            }
            dict[i][strcspn(dict[i], "\n")] = '\0';
        }
                fclose(Dictionary);
                return dict ; 
}else {
         perror("Error Openning File")  ;
         return NULL ; 
        }
}




void WordGenerator(int PhoneNumber[] , char* Dictionary[] , FILE *OutputFile ) {  
    //This is all the letters that corresponde to their numbers (except the number 0 , 1) . 
char Letters[10][4] =  {
{'\0' , '\0' , '\0'  , '\0' } , // I made the number 0,1 be dealt with in the main since its not permissible to use it . 
{'\0' , '\0' , '\0'  , '\0' } , 
{'A' , 'B' , 'C'  , '\0' } , 
{'D' , 'E' , 'F'  , '\0' } , 
{'G' , 'H' , 'I'  , '\0' } , 
{'J' , 'K' , 'L'  , '\0' } , 
{'M' , 'N' , 'O'  , '\0' } , 
{'P' , 'R' , 'S'  , '\0' } , // The letter Q is not included .
{'T' , 'U' , 'V'  , '\0' } , 
{'W' , 'X' , 'Y'  , '\0' } , // The letter Z is not included .
} ; 
char word[8] ; // we make a Char* for the word we will generate later .
word[7] = '\0'; // We assign the 8th letter to terminator . 

int Index1 ,Index2 ,Index3 ,Index4 ,Index5 , Index6 , Index7   ; 
 // we specify 7 indexes that goes through the 3 columns at the (Phonenumber[Loop Number] Row ) .  


//Now we have to get every possible combination (it will generate exactly 3 ^ 7 = 2,187 words ) and  will check if the word is in the dictonary or not .

//Note : We could've used *Recursion* to solve this problem, but instead i choose *for-loop* (Although its quite longer) it can be read and understood easily if someone wanted to read the source code .   

for(Index1 = 0 ; Index1 < 3 ; Index1 ++ ) {
word[0] = Letters[PhoneNumber[0]][Index1] ;    //The Selected user input will be the row then we will generate all the three columns . 

            for(Index2 = 0 ; Index2 < 3 ; Index2 ++ ) {
            word[1] = Letters[PhoneNumber[1]][Index2] ;    

                        for(Index3 = 0 ; Index3 < 3 ; Index3 ++ ) {
                        word[2] = Letters[PhoneNumber[2]][Index3] ;   

                                    for(Index4 = 0 ; Index4 < 3 ; Index4 ++ ) {
                                    word[3] = Letters[PhoneNumber[3]][Index4] ;  

                                                for(Index5 = 0 ; Index5 < 3 ; Index5 ++ ) {
                                                word[4] = Letters[PhoneNumber[4]][Index5] ;  

                                                            for(Index6 = 0 ; Index6 < 3 ; Index6 ++ ) {
                                                            word[5] = Letters[PhoneNumber[5]][Index6] ;    

                                                                        for(Index7 = 0 ; Index7 < 3 ; Index7 ++ ) {
                                                                        word[6] = Letters[PhoneNumber[6]][Index7] ;   
                                                                        int i = 0 ;
                                                                        for ( i = 0; word[i]; i++) {
                                                                        word[i] = tolower(word[i]);
                                                                            }

                                                                            for(i= 0 ; i < DICTIONARY_SIZE ; i++) {
                                                                                if(strcmp(word , Dictionary[i]  )== 0){
                                                                                    fprintf(OutputFile , "%s\n" , word); 
                                                                                    break; 
                                                                                }
                                                                            }
                                                                         
                                                                        }

                                                            }
                                                }
                                    }
                        }
            }
}
}



int main() { 
    int PhoneNumber[7];
    int i = 0 ;
    int input = 0 ;
    printf("Welcome the word generator program! \n");
    printf("Please make sure that you have the english dictionary as dictionary.txt in the same folder .  \n");
    printf("Please make sure to enter only 7 digits from 2-9 (0 and 1 are not permissible)  \n");
    while (i != 7)
    {
        printf("\nPlease Enter the %d'th Digit : " , i  ) ;
        scanf("%d" , &input) ; 
        if(input >= 2 && input <=9) {
            PhoneNumber[i] = input ; 
            i++ ; 

        }else{
            printf("\nPlease Enter Digits only between 2-9"  );
        }
    }
    char **dict = ReadDictionary() ;
    FILE *OutputFile = fopen("output.txt", "w");

    if (dict && OutputFile) {
        WordGenerator(PhoneNumber, dict, OutputFile);
        fclose(OutputFile);
        printf("Words generated and written to 'output.txt'\n");
    } else {
        perror("Error when opening file .");
    }
    
}