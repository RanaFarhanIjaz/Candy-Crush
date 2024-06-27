//#include<iostream>
//using namespace std;
//int main() {
//    char arr[5][5] = { {'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O',' ','X','X'},{'X','X','X','X','X'},{'X','X','X','X','X'} };
//    int p1 = 12;
//    int p2 = 12;
//    while (p1 != 0 || p2 != 0) // MAjor loop 
//    {
//        cout << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << " " << arr[0][3] << " " << arr[0][4] << " " << endl;
//        cout << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << " " << arr[1][3] << " " << arr[1][4] << " " << endl;
//        cout << arr[2][0] << " " << arr[2][1] << " " << arr[2][2] << " " << arr[2][3] << " " << arr[2][4] << " " << endl;
//        cout << arr[3][0] << " " << arr[3][1] << " " << arr[3][2] << " " << arr[3][3] << " " << arr[3][4] << " " << endl;
//        cout << arr[4][0] << " " << arr[4][1] << " " << arr[4][2] << " " << arr[4][3] << " " << arr[4][4] << " " << endl;
//        int i = 0, j = 0, k = 0, l = 0;
//        cout << "Player 1 slect a piece ";
//        cin >> i >> j;                      // coordinates of selection
//        while (i < 0 || j < 0 || i>4 || j>4)
//        {
//            cout << "Invalid positions "; cin >> i >> j;
//        }
//        while (arr[i][j] == 'X' || arr[i][j] == ' ') {
//            cout << "Invalid enter again " << endl; cin >> i >> j;    // If opposite piece access
//        }
//        cout << "Enter postion you want to move "; // positions ke coordinates
//        cin >> k >> l;
//        while (k < 0 || l < 0 || k>4 || l>4)
//        {
//            cout << "Invalid positions "; cin >> k >> l;
//        }
//        while (arr[k][l] == 'O' || arr[k][l] == 'X') {
//            cout << "Piece exits enter again"; cin >> k >> l;           // occupied positions 
//        }
//        if ((i + j) % 2 != 0) {
//            while (i != k && j != l) {
//                cout << "Cannot move diagonally , enter again "; cin >> k >> l;       // stops invalid diagonal movements
//            }
//        }
//        while (i == k && l == j) {                                   //  USER IS NOT MOVING FROM HIS PLACE
//            cout << " You are not moving. Renter "; cin >> k >> l;
//        }
//        while (k - i > 2 || k - i < -2 || l - j>2 || l - j < -2)   // restricting him not to move more than 2 spaces
//        {
//            cout << "Cannot move, enter coordiantes again " << endl; cin >> k >> l;
//        }
//        if (i != k && j == l) // HORIZONTAL MOVEMENTS
//        {
//            if (k - i == 1 || k - i == -1) // checking for single movement
//            {
//                int temp = arr[i][j];
//                arr[i][j] = arr[k][l];
//                arr[k][l] = temp;
//
//            }
//            else if (k - i == 2) // Bead kill but also check for psotive x direction and negative x direction
//            {
//                while (arr[i + 1][j] == 'O' || arr[i + 1][j] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i + 1][j] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i + 1][j] = ' ';
//                    p2--;
//                }
//            }
//            else if (k - i == -2)
//            {
//                while (arr[i - 1][j] == 'O' || arr[i - 1][j] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i - 1][j] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i - 1][j] = ' ';
//                    p2--;
//                }
//            }
//        }
//        else if (i == k && j != l)  // Vertical Movements 
//        {
//
//            if (l - j == 1 || l - j == -1) // checking for single movement
//            {
//                int temp = arr[i][j];
//                arr[i][j] = arr[k][l];
//                arr[k][l] = temp;
//
//            }
//            else if (l - j == 2) // Bead kill but also check for psotive x direction and negative x direction
//            {
//                while (arr[i][j + 1] == 'O' || arr[i][j + 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i][j + 1] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i][j + 1] = ' ';
//                    p2--;
//                }
//            }
//            else if (l - j == -2)
//            {
//                while (arr[i][j - 1] == 'O' || arr[i][j - 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i][j - 1] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i][j - 1] = ' ';
//                    p2--;
//                }
//            }
//        }
//        else if (i != k && j != l)       // Diagonal movements
//        {
//            if ((k - i == 1 || k - i == -1) && (l - j == 1 || l - j == -1)) // checking for single movement
//            {
//                int temp = arr[i][j];
//                arr[i][j] = arr[k][l];
//                arr[k][l] = temp;
//
//            }
//            else if (k - i == 2 && l - j == 2) // Bead kill but also check for psotive x direction and negative x direction
//            {
//                while (arr[i + 1][j + 1] == 'O' || arr[i + 1][j + 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i + 1][j + 1] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i + 1][j + 1] = ' ';
//                    p2--;
//                }
//            }
//            else if (k - i == -2 && l - j == -2)
//            {
//                while (arr[i - 1][j - 1] == 'O' || arr[i - 1][j - 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i - 1][j - 1] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i - 1][j - 1] = ' ';
//                    p2--;
//                }
//            }
//            else if (k - i == 2 && l - j == -2)
//            {
//
//                while (arr[i + 1][j - 1] == 'O' || arr[i + 1][j - 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i + 1][j - 1] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i + 1][j - 1] = ' ';
//                    p2--;
//                }
//            }
//            else if (k - i == -2 && l - j == 2)
//            {
//                while (arr[i - 1][j + 1] == 'O' || arr[i - 1][j + 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i - 1][j + 1] == 'X')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i - 1][j + 1] = ' ';
//                    p2--;
//                }
//            }
//        }
//
//        // PLAYER 2 KA CODE---------------------------------------------------------------------------------------------
//
//        cout << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << " " << arr[0][3] << " " << arr[0][4] << " " << endl;
//        cout << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << " " << arr[1][3] << " " << arr[1][4] << " " << endl;
//        cout << arr[2][0] << " " << arr[2][1] << " " << arr[2][2] << " " << arr[2][3] << " " << arr[2][4] << " " << endl;
//        cout << arr[3][0] << " " << arr[3][1] << " " << arr[3][2] << " " << arr[3][3] << " " << arr[3][4] << " " << endl;
//        cout << arr[4][0] << " " << arr[4][1] << " " << arr[4][2] << " " << arr[4][3] << " " << arr[4][4] << " " << endl;
//        i = 0, j = 0, k = 0, l = 0;
//        cout << "Player 1 slect a piece ";
//        cin >> i >> j;  // coordinates of selection
//        while (i < 0 || j < 0 || i>4 || j>4)
//        {
//            cout << "Invalid positions "; cin >> i >> j;
//        }
//        while (arr[i][j] == 'O' || arr[i][j] == ' ') {
//            cout << "Invalid enter again " << endl; cin >> i >> j;    // If opposite piece access
//        }
//        cout << "Enter postion you want to move ";
//        cin >> k >> l;
//        while (k < 0 || l < 0 || k>4 || l>4)
//        {
//            cout << "Invalid positions "; cin >> l >> k;
//        }
//        while (arr[k][l] == 'O' || arr[k][l] == 'X') {
//            cout << "Piece exits enter again"; cin >> k >> l;           // occupied positions 
//        }
//        if ((i + j) % 2 != 0) {
//            while (i != k && j != l) {
//                cout << "Cannot move diagonally , enter again "; cin >> k >> l;       // stops invalid diagonal movements
//            }
//        }
//        while (i == k && l == j) {                                   //  USER IS NOT MOVING FROM HIS PLACE
//            cout << " You are not moving. Renter "; cin >> k >> l;
//        }
//        while (k - i > 2 || k - i < -2 || l - j>2 || l - j < -2)   // restricting him not to move more than 2 spaces
//        {
//            cout << "Cannot move, enter coordiantes again " << endl; cin >> k >> l;
//        }
//        if (i != k && j == l) // HORIZONTAL MOVEMENTS
//        {
//            if (k - i == 1 || k - i == -1) // checking for single movement
//            {
//                int temp = arr[i][j];
//                arr[i][j] = arr[k][l];
//                arr[k][l] = temp;
//
//            }
//            else if (k - i == 2) // Bead kill but also check for psotive x direction and negative x direction
//            {
//                while (arr[i + 1][j] == 'X' || arr[i + 1][j] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i + 1][j] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i + 1][j] = ' ';
//                    p1--;
//                }
//            }
//            else if (k - i == -2)
//            {
//                while (arr[i - 1][j] == 'X' || arr[i - 1][j] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i - 1][j] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i - 1][j] = ' ';
//                    p1--;
//                }
//            }
//        }
//        else if (i == k && j != l)  // Vertical Movements 
//        {
//
//            if (l - j == 1 || l - j == -1) // checking for single movement
//            {
//                int temp = arr[i][j];
//                arr[i][j] = arr[k][l];
//                arr[k][l] = temp;
//
//            }
//            else if (l - j == 2) // Bead kill but also check for psotive x direction and negative x direction
//            {
//                while (arr[i][j + 1] == 'X' || arr[i][j + 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i][j + 1] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i][j + 1] = ' ';
//                    p1--;
//                }
//            }
//            else if (l - j == -2)
//            {
//                while (arr[i][j - 1] == 'X' || arr[i][j - 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i][j - 1] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i][j - 1] = ' ';
//                    p1--;
//                }
//            }
//        }
//        else if (i != k && j != l)       // Diagonal movements
//        {
//            if ((k - i == 1 || k - i == -1) && (l - j == 1 || l - j == -1)) // checking for single movement
//            {
//                int temp = arr[i][j];
//                arr[i][j] = arr[k][l];
//                arr[k][l] = temp;
//
//            }
//            else if (k - i == 2 && l - j == 2) // Bead kill but also check for psotive x direction and negative x direction
//            {
//                while (arr[i + 1][j + 1] == 'X' || arr[i + 1][j + 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i + 1][j + 1] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i + 1][j + 1] = ' ';
//                    p1--;
//                }
//            }
//            else if (k - i == -2 && l - j == -2)
//            {
//                while (arr[i - 1][j - 1] == 'X' || arr[i - 1][j - 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i - 1][j - 1] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i - 1][j - 1] = ' ';
//                    p1--;
//                }
//            }
//            else if (k - i == 2 && l - j == -2)
//            {
//
//                while (arr[i + 1][j - 1] == 'X' || arr[i + 1][j - 1] == ' ')
//                {
//                    cout << "Cannot jump ";
//                    cin >> k >> l;
//                }
//                if (arr[i + 1][j - 1] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i + 1][j - 1] = ' ';
//                    p1--;
//                }
//            }
//            else if (k - i == -2 && l - j == 2)
//            {
//                while (arr[i - 1][j + 1] == 'X' || arr[i - 1][j + 1] == ' ')
//                {
//                    cout << "Cannot jump "; cin >> k >> l;
//                }
//                if (arr[i - 1][j + 1] == 'O')   //Killing the opponenet bead
//                {
//                    int temp = arr[i][j];
//                    arr[i][j] = arr[k][l];
//                    arr[k][l] = temp;
//                    arr[i - 1][j + 1] = ' ';
//                    p1--;
//                }
//            }
//        }
//
//
//
//
//    }
//}