#include <iostream>
#include <string>
#include "login.hpp"
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class character
{
private:
public:
    string name = "torzaza";
    int atk = 0;
    int hp = 100;
    int def = 0;
    int crit = 0;
    void setup(string me)
    {
        name = me;
        cout << "Set up charracter.\n";
        cout << "Name: " << name << endl;
        cout << "You have ability value 100 untis.\n";
        cout << "Enter ATK value: ";
        cin >> atk;
        cout << "Enter DEF value: ";
        cin >> def;
        cout << "Enter Critiacl value(No more than 20): ";
        cin >> crit;
        if (atk + def + crit > 100)
        {
            system("cls");
            cout << "\033[31mYour ability value is over 100.\033[0m\n";
            setup(name);
        }
        if (crit > 20)
        {
            system("cls");
            cout << "\033[31mYour critical value is over 20.\033[0m\n";
            setup(name);
        }
        else if (atk + def + crit < 100)
        {
            system("cls");
            cout << "\033[31mYour ability value is less than 100.\033[0m\n";
            setup(name);
        }
    }
    void showdata()
    {
        cout << name << endl;
        cout << "atk: " << atk << endl;
        cout << "Hp: " << hp << endl;
        cout << "DEF: " << def << endl;
        cout << "Crit: " << crit << endl;
    }
    void ability(string nam, int at, int de, int cri)
    {
        name = nam;
        atk = at;
        def = de;
        crit = cri;
    }
};

void challenge(character &player, character &rival, int &round);
bool endgame(const int &round, character &player);

int main()
{
    string name = "Tor";
    bool newgame = true;
    while (newgame == true)
    {
        int random;
        int round = 1;
        int randbot[5] = {0};
        srand(time(0));
        character player;
        character griffon;
        character dragon;
        character warewolf;
        character overlord;
        character demongod;
        griffon.ability("Griffon", 55, 35, 10);
        dragon.ability("Dragon", 50, 50, 0);
        warewolf.ability("Warewolf", 40, 40, 20);
        overlord.ability("Overlord", 30, 65, 5);
        demongod.ability("Demon God", 60, 30, 20);
        player.setup(name);
        player.showdata();
        while (round <= 5 && round > 0)
        {
            do
            {
                random = rand() % 5 + 1;
            } while (randbot[random - 1] == random);
            randbot[random - 1] = random;
            switch (random)
            {
            case 1:
                challenge(player, griffon, round);
                break;
            case 2:
                challenge(player, dragon, round);
                break;
            case 3:
                challenge(player, warewolf, round);
                break;
            case 4:
                challenge(player, overlord, round);
                break;
            case 5:
                challenge(player, demongod, round);
                break;
            }
            if (round < 1)
            {
                endgame(round, player);
            }
        }
        newgame = endgame(round, player);
        cout << "tor";
    }
    return 0;
}

void challenge(character &player, character &rival, int &round)
{

    char blood1 = 219;
    char bar = 177;
    char a = 219, b = 220, c = 221, d = 188, f = 186, g = 200;
    char rps;
    string playerchoose, rivalchoose;
    int Rps, sum, aroundchoose = 0, resultcri = 50;
    while (true)
    {
        system("cls");
        cout << "\033[92mRound " << round << endl;
        cout << "\033[91m\t\t\t\t\t\t\t\t\t\t\t\t\t " << rival.name << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHP\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i < 100 / 8 + 1; i++)
        {
            cout << bar;
        }
        cout << rival.hp;
        cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i < rival.hp / 8 + 1; i++)
        {
            cout << blood1;
        }
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tATK: " << rival.atk << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tDEF: " << rival.def << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tCRIT: " << rival.crit << endl
             << endl
             << endl;

        cout << "\033[94m\t\t\t\t  " << a << a << a << a << "\t\t\t\t\t\t\033[91m" << a << a << a << a << endl;
        cout << "\033[94m\t\t\t\t " << b << b << a << a << b << b << f << "\t\t\t\t      \033[91m" << f << b << b << a << a << b << b << endl;
        cout << "\033[94m\t\t\t\t " << a << " " << a << a << " " << a << d << "\t\t\t\t      \033[91m" << g << a << " " << a << a << " " << a << endl;
        cout << "\033[94m\t\t\t\t  " << b << a << a << b << "\t\t\t\t\t        \033[91m" << b << a << a << b << endl;
        cout << "\033[94m\t\t\t\t  " << a << "  " << a << "\t\t\t\t\t        \033[91m" << a << "  " << a << endl
             << endl;

        cout << "\033[94m  " << player.name << endl;
        cout << " HP\n";
        cout << " ";
        for (int i = 0; i < 100 / 8 + 1; i++)
        {
            cout << bar;
        }
        cout << player.hp;
        cout << "\r ";
        for (int i = 0; i < player.hp / 8 + 1; i++)
        {
            cout << blood1;
        }
        cout << "\n ATK: " << player.atk << endl;
        cout << " DEF: " << player.def << endl;
        cout << " CRIT: " << player.crit << endl
             << endl;

        switch (rps)
        {
        case 'r':
            playerchoose = "rock";
            break;
        case 'p':
            playerchoose = "paper";
            break;
        case 's':
            playerchoose = "scissors";
            break;
        }
        switch (Rps)
        {
        case 1:
            rivalchoose = "rock";
            break;
        case 2:
            rivalchoose = "paper";
            break;
        case 3:
            rivalchoose = "scissors";
            break;
        }

        if (aroundchoose > 0)
        {
            cout << "\033[94m" << player.name << " choose: " << playerchoose << endl;
            cout << "\033[91m" << rival.name << " choose: " << rivalchoose << "\033[0m\n";
        }

        do
        {
            cout << "\033[0mEnter rock, paper, scissors (r, p, s): ";
            cin >> rps;
        } while (rps != 'r' && rps != 'p' && rps != 's');
        Rps = rand() % 3 + 1;

        if ((Rps == 1 && rps == 'p') || (Rps == 2 && rps == 's') || (Rps == 3 && rps == 'r'))
        {
            sum = player.atk - rival.def;
            if ((rand() % 100) + 1 <= player.crit)
            {
                sum += resultcri;
            }
            if (sum > 0)
            {

                rival.hp -= sum;
            }
        }
        else if ((Rps == 1 && rps == 's') || (Rps == 2 && rps == 'r') || (Rps == 3 && rps == 'p'))
        {
            sum = rival.atk - player.def;
            if ((rand() % 100) + 1 <= rival.crit)
            {
                sum += resultcri;
            }
            if (sum > 0)
            {
                player.hp -= sum;
            }
        }
        aroundchoose += 1;
        if (rival.hp <= 0)
        {
            round += 1;
            return;
        }
        else if (player.hp <= 0)
        {
            round -= 10;
            return;
        }
    }
}

bool endgame(const int &round, character &player)
{
    char yn;
    system("cls");
    if (round > 0)
    {
        cout << "\033[94mCongratulations, You Win.\n\n";
        cout << "***********************************************\n\n";
        cout << "\n\nDo you want to play the game again?\n";
        cout << "Yes,I want(Y/y): ";
        cin >> yn;
        if (yn == 'y' || yn == 'Y')
        {
            return true;
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        cout << "\033[91mCondolences, You Lost.\n\n";
        cout << "***********************************************\n";
        cout << "\n\nDo you want to play the game again?\n";
        cout << "Yes,I want(Y/y): ";
        cin >> yn;
        if (yn == 'y' || yn == 'Y')
        {
            return true;
        }
        else
        {
            exit(0);
        }
    }
}