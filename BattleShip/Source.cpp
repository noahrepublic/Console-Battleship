#include <iostream>
#include <array>
#include <random>

static bool lookForShips(int ray[4][4]) {
    int amountLeft = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (ray[i][j] > 0) {
                amountLeft++;
                std::cout << amountLeft << " \n";
            }
        }
    }
    return amountLeft;
}

template<typename T>
T random(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

static int generateShips(int ray[4][4], int totalShips) {
    int ships = 0;
    while (totalShips - ships != 0) {
		int x = random(0, 4);
		int y = random(0, 4);
        if (ray[x][y] == 0) {
            ray[x][y] = totalShips - ships;
			ships++;
        }
    }
	return ships;
}

int main() {
    bool hasWon = false;
    int turns = 0;
    int hits = 0;
    int ships = 4;
    int field[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
	generateShips(field, ships);
    while (hasWon == false) {
        bool shipsLeft = lookForShips(field);
        std::cout << shipsLeft << "\n";
        if (shipsLeft == 0) {
            hasWon = true;
            break;
        }
        std::cout << "Column: \n";
        int X;
        std::cin >> X;
        int Y;
        std::cout << "Row: \n";
        std::cin >> Y;
        Y--;
        X--;
        if (field[X][Y] != 0) {
            field[X][Y]--;
            std::cout << "Hit at column " << X + 1 << "! \n";
            hits++;
        }
        else {
            std::cout << "Miss at column " << X + 1 << "! \n";
        }
        turns++;
    }
    std::cout << "You win! It took you " << turns << " turns! \n";
}
