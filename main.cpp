#include <iostream>
#include <string>
#include "login.hpp"
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "loading.hpp"

using namespace std;

class Character
{
private:
    string name = "";
    int atk = 0;
    int hp = 100;
    int def = 0;
    int crit = 0;
public:
    void setUp(string me);
    void setAbility(string nam, int at, int de, int cri);
    string getName();
    int getATK();
    int getHp();
    int getDef();
    int getCrit();
    void setHp(int h);
};

void challenge(Character &player, Character &rival, int &round);
bool endgame(const int &round, Character &player);
void Attack(bool p, Character &player, Character &rival, int &round);

int main()
{
    string name;
    bool newgame = true;
    char yn;
    name = login();
    if(name == "off"){
        return 0;
    }
    system("cls");
    while (newgame == true)
    {
        int random;
        int round = 1;
        int randbot[5] = {0};
        srand(time(0));
        Character player;
        Character griffon;
        Character dragon;
        Character warewolf;
        Character overlord;
        Character demongod;
        griffon.setAbility("Griffon", 55, 35, 0);
        dragon.setAbility("Dragon", 60, 20, 0);
        warewolf.setAbility("Warewolf", 50, 20, 0);
        overlord.setAbility("Overlord", 65, 10, 0);
        demongod.setAbility("Demon God", 50, 15, 0);
        player.setUp(name);
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
            else if (round >= 1 && round <= 5)
            {
                system("cls");
                cout << "\033[92m!! You win \n";
                cout << "**************************\n\n";
                cout << "Next challenge (y): ";
                cin >> yn;
                cout << "\033[0m";
                Loadingber(50);
            }
        }
        newgame = endgame(round, player);
    }
    return 0;
}

void Character::setUp(string me)
{
    name = me;
    cout << "Set up charracter.\n";
    cout << "*************************************\n";
    cout << "Name: " << name << endl;
    cout << "You have ability value 100 untis.\n";
    cout << "Enter ATK value: ";
    cin >> atk;
    cout << "Enter DEF value: ";
    cin >> def;
    crit = rand() % 30 + 1;
    if (atk + def > 100)
    {
        system("cls");
        cout << "\033[31mYour ability value is over 100.\033[0m\n";
        setUp(name);
    }
    else if (atk + def < 100)
    {
        system("cls");
        cout << "\033[31mYour ability value is less than 100.\033[0m\n";
        setUp(name);
    }
}
void Character::setAbility(string nam, int at, int de, int cri)
{
    name = nam;
    atk = at;
    def = de;
    crit = cri;
}
string Character::getName(){
    return name;
}
int Character::getATK(){
    return atk;
}
int Character::getHp(){
    return hp;
}
int Character::getDef(){
    return def;
}
int Character::getCrit(){
    return crit;
}
void Character::setHp(int h){
    hp += h;
    if(hp>100){
        hp = 100;
    }
}
void challenge(Character &player, Character &rival, int &round)
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
        cout << "\033[91m\t\t\t\t\t\t\t\t\t\t\t\t\t " << rival.getName() << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHP\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i < 100 / 8 + 1; i++)
        {
            cout << bar;
        }
        cout << rival.getHp();
        cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i < rival.getHp() / 8 + 1; i++)
        {
            cout << blood1;
        }
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tATK: " << rival.getATK() << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tDEF: " << rival.getDef() << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tCRIT: " << rival.getCrit() << endl
             << endl
             << endl;

        cout << "\033[94m\t\t\t\t  " << a << a << a << a << "\t\t\t\t\t\t\033[91m" << a << a << a << a << endl;
        cout << "\033[94m\t\t\t\t " << b << b << a << a << b << b << f << "\t\t\t\t      \033[91m" << f << b << b << a << a << b << b << endl;
        cout << "\033[94m\t\t\t\t " << a << " " << a << a << " " << a << d << "\t\t\t\t      \033[91m" << g << a << " " << a << a << " " << a << endl;
        cout << "\033[94m\t\t\t\t  " << b << a << a << b << "\t\t\t\t\t        \033[91m" << b << a << a << b << endl;
        cout << "\033[94m\t\t\t\t  " << a << "  " << a << "\t\t\t\t\t        \033[91m" << a << "  " << a << endl
             << endl;

        cout << "\033[94m  " << player.getName() << endl;
        cout << " HP\n";
        cout << " ";
        for (int i = 0; i < 100 / 8 + 1; i++)
        {
            cout << bar;
        }
        cout << player.getHp();
        cout << "\r ";
        for (int i = 0; i < player.getHp() / 8 + 1; i++)
        {
            cout << blood1;
        }
        cout << "\n ATK: " << player.getATK() << endl;
        cout << " DEF: " << player.getDef() << endl;
        cout << " CRIT: " << player.getCrit() << endl
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
            cout << "\033[94m" << player.getName() << " choose: " << playerchoose << endl;
            cout << "\033[91m" << rival.getName() << " choose: " << rivalchoose << "\033[0m\n";
        }

        do
        {
            cout << "\033[0mEnter rock, paper, scissors (r, p, s): ";
            cin >> rps;
        } while (rps != 'r' && rps != 'p' && rps != 's');
        Rps = rand() % 3 + 1;

        if ((Rps == 1 && rps == 'p') || (Rps == 2 && rps == 's') || (Rps == 3 && rps == 'r'))
        {
            sum = player.getATK() - rival.getDef();
            if ((rand() % 100) + 1 <= player.getCrit())
            {
                sum += resultcri;
            }
            if (sum > 0)
            {
                rival.setHp(-sum);
            }
        }
        else if ((Rps == 1 && rps == 's') || (Rps == 2 && rps == 'r') || (Rps == 3 && rps == 'p'))
        {
            sum = rival.getATK() - player.getDef();
            if ((rand() % 100) + 1 <= rival.getCrit())
            {
                sum += resultcri;
            }
            if (sum > 0)
            {
                player.setHp(-sum);
            }
        }
        aroundchoose += 1;
        if (rival.getHp() <= 0)
        {
            Attack(true, player, rival, round);
            round += 1;
            player.setHp(100);
            return;
        }
        else if (player.getHp() <= 0)
        {
            Attack(false, player, rival, round);
            round -= 10;
            return;
        }
    }
}
bool endgame(const int &round, Character &player)
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
            cout << "\033[0m";
            system("cls");
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
            cout << "\033[0m";
            system("cls");
            return true;
        }
        else
        {
            exit(0);
        }
    }
}
void Attack(bool p, Character &player, Character &rival, int &round)
{
    char blood1 = 219;
    char bar = 177;
    char a = 219, b = 220, c = 221, d = 188, f = 186, g = 200;
    system("cls");
    if (p == 1)
    {
        for (int i = 0; i <= 19; i++)
        {
            cout << "\033[92mRound " << round << endl;
            cout << "\033[91m\t\t\t\t\t\t\t\t\t\t\t\t\t " << rival.getName() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHP\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i < 100 / 8 + 1; i++)
            {
                cout << bar;
            }
            cout << rival.getHp();
            cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i < rival.getHp() / 8 + 1; i++)
            {
                cout << blood1;
            }
            cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tATK: " << rival.getATK() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tDEF: " << rival.getDef() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tCRIT: " << rival.getCrit() << endl
                 << endl
                 << endl;

            cout << "\033[91m"; // text change color
            cout << "\t\t\t\t\t\t\t\t\t\t" << a << a << a << a << endl;
            cout << "\t\t\t\t\t\t\t\t\t      " << f << b << b << a << a << b << b << endl;
            cout << "\t\t\t\t\t\t\t\t\t      " << g << a << " " << a << a << " " << a << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << b << a << a << b << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << a << "  " << a << endl
                 << endl;

            cout << "\033[F\033[F\033[F\033[F\033[F\033[F";

            cout << "\033[94m"; // text change color
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                  " << a << a << a << a << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                 " << b << b << a << a << b << b << f << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                 " << a << " " << a << a << " " << a << d << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                  " << b << a << a << b << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                  " << a << "  " << a << endl
                 << endl;

            cout << "\033[94m\n  " << player.getName() << endl;
            cout << " HP\n";
            cout << " ";
            for (int i = 0; i < 100 / 8 + 1; i++)
            {
                cout << bar;
            }
            cout << player.getHp();
            cout << "\r ";
            for (int i = 0; i < player.getHp() / 8 + 1; i++)
            {
                cout << blood1;
            }
            cout << "\n ATK: " << player.getATK() << endl;
            cout << " DEF: " << player.getDef() << endl;
            cout << " CRIT: " << player.getCrit() << endl
                 << endl;
            delayRealTime(200);
            if (i != 19)
            {
                system("cls");
            }
        }
    }
    else
    {
        for (int i = 20; i >= 0; i--)
        {
            cout << "\033[92mRound " << round << endl;
            cout << "\033[91m\t\t\t\t\t\t\t\t\t\t\t\t\t " << rival.getName() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHP\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i < 100 / 8 + 1; i++)
            {
                cout << bar;
            }
            cout << rival.getHp();
            cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i < rival.getHp() / 8 + 1; i++)
            {
                cout << blood1;
            }
            cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tATK: " << rival.getATK() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tDEF: " << rival.getDef() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tCRIT: " << rival.getCrit() << endl
                 << endl
                 << endl;

            cout << "\033[91m";
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                          " << a << a << a << a << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                        " << f << b << b << a << a << b << b << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                        " << g << a << " " << a << a << " " << a << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                          " << b << a << a << b << endl;
            for (int t = 0; t < i; t++)
            {
                cout << "  ";
            }
            cout << "                                          " << a << "  " << a << endl
                 << endl;

            cout << "\033[F\033[F\033[F\033[F\033[F\033[F";

            cout << "\033[94m"; // text change color
            cout << "\t\t\t\t  " << a << a << a << a << endl;
            cout << "\033[94m\t\t\t\t " << b << b << a << a << b << b << f << endl;
            cout << "\033[94m\t\t\t\t " << a << " " << a << a << " " << a << d << endl;
            cout << "\033[94m\t\t\t\t  " << b << a << a << b << endl;
            cout << "\033[94m\t\t\t\t  " << a << "  " << a << endl
                 << endl; // สีฟ้า

            cout << "\033[94m\n  " << player.getName() << endl;
            cout << " HP\n";
            cout << " ";
            for (int i = 0; i < 100 / 8 + 1; i++)
            {
                cout << bar;
            }
            cout << player.getHp();
            cout << "\r ";
            for (int i = 0; i < player.getHp() / 8 + 1; i++)
            {
                cout << blood1;
            }
            cout << "\n ATK: " << player.getATK() << endl;
            cout << " DEF: " << player.getDef() << endl;
            cout << " CRIT: " << player.getCrit() << endl
                 << endl;
            delayRealTime(200);
            if (i != 0)
            {
                system("cls");
            }
        }
    }
}