#include <iostream>
#include <vector>


struct cell{
    char value;
    int x;
    int y;
    bool used = false;
};
int direction = 1;
int sum = 0;
int K = 0;
std::vector<std::vector<cell>> labyrinth(2 * K + 1, std::vector<cell>(2 * K + 1));
int ret;
cell start;
cell current_cell;
cell next_cell;

void action_one(int price) {
    std::cout << "1" << '\n';
    sum += price;
    if (direction == 1) {
        ++current_cell.x;
        ++next_cell.x;
    } else if(direction == 2) {
        --current_cell.y;
        --next_cell.y;
    } else if(direction == 3){
        --current_cell.x;
        --next_cell.x;
    } else {
        ++current_cell.y;
        ++next_cell.y;
    }
    current_cell.used = true;
}

void action_two(int dir, int price) {
    std::cout << "2" << dir << '\n';
    if (dir) {
        ++direction;
    } else {
        --direction;
    }
    if (direction == 0) {
        direction = 4;
    }
    if (direction == 5) {
        direction = 1;
    }
    if (direction == 1) {
        next_cell.x = current_cell.x + 1;
        next_cell.y = current_cell.y;
    } else if (direction == 2) {
        next_cell.x = current_cell.x;
        next_cell.y = current_cell.y - 1;
    } else if (direction == 3) {
        next_cell.x = current_cell.x - 1;
        next_cell.y = current_cell.y;
    } else {
        next_cell.x = current_cell.x;
        next_cell.y = current_cell.y + 1;
    }
    sum += price;
}

void action_three(int price) {
    std::cout << "3" << '\n';
    for (int i = 0; i < 2 * K + 1; i++) {
        for (int j = 0; j < 2 * K + 1; j++) {
            std::cin >> labyrinth[i][j].value;
        }
    }
}

int main() {
    int x, y, x1, y1, A, B, C, K_;
    std::cin >> current_cell.x >> current_cell.y >> next_cell.x >> next_cell.y >> A >> B >> C >> K_;
    start.x = current_cell.x;
    start.y = current_cell.y;
    int count = 0;
    K = K_;
    if (next_cell.x == current_cell.x + 1) {
        direction = 1;
    } else if (next_cell.y == current_cell.y + 1) {
        direction = 4;
    } else if (next_cell.y == current_cell.y - 1) {
        direction = 2;
    } else {
        direction = 3;
    }

    while (true) {
        if (K != 0) {
            action_three(C);
        }
        while (next_cell.used != true) {
            while(labyrinth[next_cell.x][next_cell.y].value == '_') {
                action_one(A);
            }
            action_two(1, B);
        }
        if (current_cell.x == start.x && current_cell.y == start.y) {
            ++count;
        }
        if (count == 2) {
            std::cout << "4" << sum << '\n';
            break;
        }
    }
}
