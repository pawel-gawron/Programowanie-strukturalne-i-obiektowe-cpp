// https://www.codingame.com/ide/puzzle/shadows-of-the-knight-episode-1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    int x1 = 0;
    int y1 = 0;
    int x2 = W - 1;
    int y2 = H - 1;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // the location of the next window Batman should jump to.
        if (bombDir.find("U") != string::npos) {
        y2 = Y0-1;
      } else if (bombDir.find("D") != string::npos) {
        y1 = Y0+1;
      }

      if (bombDir.find("L") != string::npos) {
        x2 = X0 - 1;
      }else if (bombDir.find("R") != string::npos) {
        x1 = X0 + 1;
      }
      X0 = x1 + (x2 - x1) / 2;
      Y0 = y1 + (y2 - y1) / 2;
      cout << X0 << " " << Y0 << endl;
    }
}
