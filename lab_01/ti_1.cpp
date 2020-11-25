#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class InformationAnalys
{
private:
    string filePath;
    int amountLetters = 0;
    int letterCount[26] = { 0 };
    double letterProbability[26] = { 0 };
    double letterAmountInformation[26] = { 0 };
    double letterEntropy[26] = { 0 };
    double sourceEntropy = 0;
    double averageAmountInformation = 0;
    double sumLetterAmountInformation = 0;
    int alphabet = 0;
    double sumletterProbability = 0;
    double avarageLetterProbability = 0;

public:
    InformationAnalys(string filePath)
    {
        this->filePath = filePath;
    }

    void GetData()
    {
        char letter;
        ifstream file(filePath);
        if (file.is_open())
        {
            while (file >> letter)
            {
                if (letter >= 'a' && letter <= 'z' ||
                    letter >= 'A' && letter <= 'Z')
                {
                    if (letter >= 'a')
                    {
                        letterCount[letter - 'a']++;
                    }
                    else
                    {
                        letterCount[letter - 'A']++;
                    }
                    amountLetters++;
                }
            }
        }
        file.close();
    }

    void LetterProbability()
    {
        for (int i = 0; i < 26; i++)
        {
            if (letterCount[i])
            {
                sumletterProbability += letterProbability[i] = (double)letterCount[i] / amountLetters;
                alphabet++;
            }
        }
    }

    void AvarageLetterProbability()
    {
        avarageLetterProbability = sumletterProbability / alphabet;
    }

    void LetterAmountInformation()
    {
        for (int i = 0; i < 26; i++)
        {
            if (letterProbability[i])
            {
                sumLetterAmountInformation += (letterAmountInformation[i] = -log2(letterProbability[i]));
            }
        }
    }

    void LetterEntropy()
    {
        for (int i = 0; i < 26; i++)
        {
            if (letterAmountInformation[i])
            {
                letterEntropy[i] = letterAmountInformation[i] * letterProbability[i];
            }
        }
    }

    void SourceEntropy()
    {
        for (int i = 0; i < 26; i++)
        {
            if (letterAmountInformation[i])
            {
                sourceEntropy += letterEntropy[i];
            }
        }
    }

    void AverageAmountInformation()
    {
        averageAmountInformation = sumLetterAmountInformation / alphabet;
    }

    void Calculate()
    {
        LetterProbability();
        AvarageLetterProbability();
        LetterAmountInformation();
        LetterEntropy();
        SourceEntropy();
        AverageAmountInformation();
    }

    void Print()
    {
        printf("Amount of letters is %d\n\n", amountLetters);
        for (int i = 0; i < 26; ++i)
        {
            if (letterAmountInformation[i])
            {
                printf("p(%c) = %.4lf\t\tI(%c) = %5.2lf bit\t\t", (char)(i + 'a'), letterProbability[i],
                    (char)(i + 'a'), letterAmountInformation[i]);
                printf("H(%c) = %.2lf bit/character\n", (char)(i + 'a'), letterEntropy[i]);
            }
        }
        printf("\nInformation amount is %.4lf bit\n", sumLetterAmountInformation);
        printf("\nAverage probability is %.4lf\n", avarageLetterProbability);
        printf("\nEntropy is %.4lf bit/character\n", sourceEntropy);
    }
};

int main(int argc, char* argv[])
{
    string fileName(argv[1]);
    InformationAnalys* i = new InformationAnalys(fileName);
    i->GetData();
    i->Calculate();
    i->Print();

    delete i;
    return 0;
}