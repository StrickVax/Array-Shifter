#include <iostream>

using namespace std;

void boardChecker(int[][3]);
void boardMover(int [][3]);

int main()
{
    int token;
    int xAxis1[3][3] = {{0, 0, 2}, {0, 0, 2}, {0, 0, 0}};
    int yAxis1[3][3] = {{0, 0, 0}, {0, 4, 0}, {0, 4, 0}};

    do
    {
        boardChecker(xAxis1);
        boardChecker(yAxis1);

        cout << "\n1. Move\n2. Check\n3. Quit\n";
        cin >> token;

        if (token == 1)
        {
            boardMover(xAxis1);
            boardMover(yAxis1);
        }

    } while (token != 3);

    return 0;
}

void boardChecker(int xAxis1[][3])
{
    cout << "\nThe current position of the board is: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << xAxis1[i][j];
        cout << endl;
    }
}

void boardMover(int xAx[][3])
{
    int moveTo;
    int tempArray[3][3];

    cout << "\n\nMove to the\nLEFT (1)\nRIGHT (2)\nUP (3)\nDOWN (4)\n";
    cin >> moveTo;

    if (0 < moveTo < 5)
    {
        if (moveTo == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tempArray[i][0] = xAx[i][0];
                xAx[i][0] = xAx[i][1];
                xAx[i][1] = xAx[i][2];
                xAx[i][2] = tempArray[i][0];
            }
        }
        if (moveTo == 2) 
        {
            for (int i = 0; i < 3; i++)
            {
                tempArray[i][2] = xAx[i][2];
                xAx[i][2] = xAx[i][1];
                xAx[i][1] = xAx[i][0];
                xAx[i][0] = tempArray[i][2];
            }
        }
        if (moveTo == 3) 
        {
            for (int i = 0; i < 3; i++)
            {
                tempArray[0][i] = xAx[0][i];
                xAx[0][i] = xAx[1][i];
                xAx[1][i] = xAx[2][i];
                xAx[2][i] = tempArray[0][i];
                
            }
        }
        if (moveTo == 4) 
    {
        for (int i = 0; i < 3; i++)
        {
            tempArray[2][i] = xAx[2][i];
            xAx[2][i] = xAx[1][i];
            xAx[1][i] = xAx[0][i];
            xAx[0][i] = tempArray[2][i];
        }
    }
    } 
}