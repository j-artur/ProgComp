#include <iostream>

using namespace std;

int main()
{
    char joint[30];
    char* team = joint;
    
    size_t playerSize = 0;

    cout << "Insert player/team: ";
    cin >> joint;

    for (size_t i = 0; i < 20; i++)
    {
        if (joint[i] == '/')
        {
            playerSize = i;
            team = &joint[i + 1];
        }
    }

    cout << "Player name has " << playerSize << " letters.\n";
    cout << "Their team is " << team << ".\n";

    delete team;

    return 0;
}
