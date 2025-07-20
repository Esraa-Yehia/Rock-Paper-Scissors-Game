using namespace std;
#include <iostream>
#include <string>

enum enGame { Stone = 1, Paper = 2, Scissors = 3 };
enum enTabs { Space = 1, DividerLine = 2, HalfSpace = 3, HalfDividerLine = 4 };
struct stScore
{
    short PlayerScore;
    short ComputerScore;
    short DrawScore;


};

string Tabs(enTabs enTabs)
{
    switch (enTabs)
    {
    case (enTabs::Space):
        return "\t\t\t\t";

    case (enTabs::DividerLine):
        return"-----------------------------------------------------------------";

    case(enTabs::HalfSpace):
        return "\t\t\t";

    case(enTabs::HalfDividerLine):
        return "---------------------------";

    default:
        return "Invalid input";
    }

}

short ReadPlayerChoice(string message)
{
    short num;
    do
    {
        cout << message;
        cin >> num;

    } while (num < 1 || num > 3);

    return num;

}

int RandomNum(int from, int to)
{
    int RandomNum = rand() % (to - from + 1) + from;
    return RandomNum;
}

short ComputerChoice()
{

    short ComputerChoice;
    ComputerChoice = RandomNum(1, 3);

    return ComputerChoice;


}

short NumOfRounds()
{
    short NumOfRounds;
    do
    {
        cout << "Please enter number of rounds 1 to 10 ?\n";

        cin >> NumOfRounds;

    } while (NumOfRounds < 1 || NumOfRounds > 10);



    return NumOfRounds;

}

string WinnerOfRound(int PlayerChoice, int ComputerChoice)
{

    if (ComputerChoice == PlayerChoice)
    {
        return "No Winner";

    }
    else if (ComputerChoice == enGame::Paper)
    {

        if (PlayerChoice == enGame::Scissors)
            return "Player";
        else if (PlayerChoice == enGame::Stone)
            return "Computer";

    }
    else if (ComputerChoice == enGame::Scissors)
    {

        if (PlayerChoice == enGame::Paper)
            return "Computer";

        else if (PlayerChoice == enGame::Stone)
            return "Player";

    }
    else if (ComputerChoice == enGame::Stone)
    {

        if (PlayerChoice == enGame::Paper)
            return "Player";
        else if (PlayerChoice == enGame::Scissors)
            return "Computer";

    }

    return "Unknown Result";



}

string ChoiceWord(int num)
{
    switch (num)
    {
    case (enGame::Paper):
        return "Paper";

    case(enGame::Scissors):
        return "Scissors";

    case (enGame::Stone):
        return "Stone";

    default:
        return "not found";

    }

}

void PrintGameOver(int NumOfRounds, stScore& Score)
{
    cout << Tabs(enTabs::Space) << Tabs(enTabs::DividerLine) << "\n\n";
    cout << Tabs(enTabs::Space) << Tabs(enTabs::HalfSpace) << "+++ G A M E  O V E R +++" << "\n\n";
    cout << Tabs(enTabs::Space) << Tabs(enTabs::DividerLine) << "\n\n";
    cout << Tabs(enTabs::Space) << Tabs(enTabs::HalfDividerLine) << "[ Game Result ]" << Tabs(enTabs::HalfDividerLine) << "\n";
    cout << Tabs(enTabs::Space) << "Game Rounds          : " << NumOfRounds << endl;
    cout << Tabs(enTabs::Space) << "Player won times     : " << Score.PlayerScore << endl;
    cout << Tabs(enTabs::Space) << "Computer won times   : " << Score.ComputerScore << endl;
    cout << Tabs(enTabs::Space) << "Draw times           : " << Score.DrawScore << endl;


    if (Score.PlayerScore > Score.ComputerScore)
        cout << Tabs(enTabs::Space) << "Final Winner         : " << "Player" << endl;
    else if (Score.ComputerScore > Score.PlayerScore)
        cout << Tabs(enTabs::Space) << "Final Winner         : " << "Computer" << endl;
    else
        cout << Tabs(enTabs::Space) << "Final Winner         : " << "No Winner" << endl;


}

void UpdateScore(string RoundResult, stScore& Score)
{
    if (RoundResult == "Player")
        Score.PlayerScore++;
    else if (RoundResult == "Computer")
        Score.ComputerScore++;
    else
        Score.DrawScore++;

}

void StartGame()
{
    char PlayAgain;

    do
    {
        system("color 0F");                     // مسح الشاشة قبل كل لعبة جديدة
        system("cls");

        short Num_OfRounds = NumOfRounds();

        stScore Score{ 0 , 0 , 0 };

        for (int i = 1; i <= Num_OfRounds; i++)
        {
            cout << "\nRound [" << i << "] begins : \n";
            short Computer_Choice = ComputerChoice();
            short PlayerChoice = ReadPlayerChoice("\nYour Choice : [1] : Stone , [2]: Paper , [3] : Scissors ?  ");
            string RoundResult = WinnerOfRound(PlayerChoice, Computer_Choice);

            if (RoundResult == "Player")
                system("color 2F");                 //خلفية خضراء
            else if (RoundResult == "Computer")
                system("color 4F");                //خلفية حمراء 
            else
                system("color 6F");                //خلفية صفراء



            cout << "\n\n------------------------Round [" << i << "]----------------------\n";

            cout << "Player   Choice : " << ChoiceWord(PlayerChoice);
            cout << "\nComputer Choice :" << ChoiceWord(Computer_Choice);
            cout << "\nRound Winner    :" << RoundResult;
            cout << "\n\n---------------------------------------------------------\n";

            UpdateScore(RoundResult, Score);

        }

        PrintGameOver(Num_OfRounds, Score);


        cout << "\n\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;


    } while (PlayAgain == 'y' || PlayAgain == 'Y');






}


int main()
{
    srand((unsigned)time(NULL));

    StartGame();

}