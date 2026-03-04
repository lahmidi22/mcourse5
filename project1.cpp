#include<iostream>
#include<string> 
#include<cmath>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice Computer2Choice;
    enWinner Winner;
    string WinnerName = "";
};
struct stGameResults
{
    short GameRound = 0;
    short Player1WinTimes = 0;
    short Computer2WinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";

};
int RandomNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}
enGameChoice ReadPlayer1Choice()
{
    short choice = 0;
    do
    {
        cout << "your choice [1]:Stone , [2]:Paper, [3]:Scissors? : ";
        cin >> choice;
    } while (choice <= 0 || choice > 3);

    return (enGameChoice)choice;
}
enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{

    if (RoundInfo.Player1Choice == RoundInfo.Computer2Choice)
    {
        system("color 6F");
        return enWinner::Draw;
    }
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.Computer2Choice == enGameChoice::Paper)
        {

            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.Computer2Choice == enGameChoice::Scissors)
        {

            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.Computer2Choice == enGameChoice::Stone)
        {

            return enWinner::Computer;
        }
        break;
    }
    return enWinner::Player1;
}
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
    {
        return enWinner::Player1;
    }
    else if (ComputerWinTimes > Player1WinTimes)
    {
        return enWinner::Computer;
    }
    else
    {
        return enWinner::Draw;
    }
}
string WinnerName(enWinner Winner)
{
    string arrWinnrNAme[3]{ "Player1","Computer","Draw" };
    return arrWinnrNAme[Winner - 1];
}string ChoiceName(enGameChoice Choice)
{
    string arrChoicName[3]{ "Stone","Paper","Scissors" };
    return arrChoicName[Choice - 1];
}
void SetWinScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");
        break;
    }
}
void PrintRoundResult(stRoundInfo RoundInfo)
{
    cout << "\n________________Round[" << RoundInfo.RoundNumber << "]__________\n\n";
    cout << "Player1 Choice :" << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice:" << ChoiceName(RoundInfo.Computer2Choice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]" << endl;
    cout << "_________________________________________\n" << endl;
    SetWinScreenColor(RoundInfo.Winner);

}
stGameResults FillGameResult(short GameRound, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResult;
    GameResult.GameRound = GameRound;
    GameResult.Player1WinTimes = Player1WinTimes;
    GameResult.Computer2WinTimes = ComputerWinTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes, DrawTimes);
    GameResult.WinnerName = WinnerName(GameResult.GameWinner);
    return GameResult;

}
stGameResults PlayGame(short HowManyRound)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRound; GameRound++)
    {
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.Computer2Choice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        // Increase Win/Draw counters

        if (RoundInfo.Winner == enWinner::Player1)
        {
            Player1WinTimes++;

        }
        else if (RoundInfo.Winner == enWinner::Computer)
        {
            ComputerWinTimes++;
        }
        else
        {
            DrawTimes++;
        }

        PrintRoundResult(RoundInfo);
    }

    return FillGameResult(HowManyRound, Player1WinTimes, ComputerWinTimes, DrawTimes);
}
string Tabs(short HowManyTabs)
{
    string t = "";
    for (int i = 1; i <= HowManyTabs; i++)
    {
        t += "\t";
        cout << t;
    }
    return t;
}
void ShowGameEverScreen()
{
    cout << Tabs(2) << "_________________________________________\n";
    cout << Tabs(2) << "        +++ G a m e   O v e r +++\n    ";
    cout << Tabs(2) << "_________________________________________\n";
}
void ShowFinalGameResult(stGameResults GameResult)
{

    cout << Tabs(2) << "---------------[ Game Results ]------------\n\n";
    cout << Tabs(2) << " Game Rounds         : " << GameResult.GameRound << endl;
    cout << Tabs(2) << " Player1 won times   : " << GameResult.Player1WinTimes << endl;
    cout << Tabs(2) << " Computer won times  : " << GameResult.Computer2WinTimes << endl;
    cout << Tabs(2) << " Draw times          : " << GameResult.DrawTimes << endl;
    cout << Tabs(2) << "-------------------------------------------\n\n";


}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
short HowManyRound()
{
    short HowManyRound = 0;

    do
    {
        cout << "\nHow many  round 1 to 10? ";
        cin >> HowManyRound;
    } while (HowManyRound <= 0 || HowManyRound > 10);
    return HowManyRound;
}
void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResult = PlayGame(HowManyRound());
        ShowGameEverScreen();
        ShowFinalGameResult(GameResult);
        cout << endl << Tabs(3) << " Do you want to play again Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}

