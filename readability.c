#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //GET STRING OF TEXT FROM USER
    string s = get_string("Text: ");

    //LOOP TO COUNT LETTERS, SENTENCES, WORDS
    int length = strlen(s); //length of all characters (spaces, letters, etc.)
    int letters = 0; //letter counter
    int words = 1; //word counter. starts at one because there is no space after last wod
    int sentences = 0; //sentence counter

    
    for (int i = 0; i < length; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letters += 1;
        }
        else if (s[i] == 32)
        {
            words += 1; 
        } 
        else if (s[i] == 33 || s[i] == 46 || s[i] == 63)
        {
            sentences += 1;
        }
    }
    // printf("averages: words=%i; letters=%i; sentences=%i\n", words, letters, sentences);
    
    //CALCULATE AVERAGE PER 100 WORDS
    double avgWords;
    double avgLetters;
    double avgSentences;
    
    avgWords = 100.00 / words;
    avgLetters = avgWords * letters; 
    avgSentences = avgWords * sentences;
    // printf("averages: avg words=%.2f; avg letters=%.2f; avg sentences=%.2f\n", avgWords, avgLetters, avgSentences);
    
    //COLEMAN-LIAU INDEX
    double index = 0.0588 * avgLetters - 0.296 * avgSentences - 15.8;
    
    if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %.0f\n", index); 
    }
}
