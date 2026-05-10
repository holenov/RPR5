#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <windows.h>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int el : row) {
            cout.width(5);
            cout << el;
        }
        cout << "\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows, cols;
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    cout << "\nВихідна матриця:\n";
    printMatrix(matrix);

    int maxAbs = abs(matrix[0][0]);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (abs(matrix[i][j]) > maxAbs)
                maxAbs = abs(matrix[i][j]);

    cout << "\n1. Максимальний за модулем елемент: " << maxAbs << "\n";

    vector<int> flat;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            flat.push_back(matrix[i][j]);

    int firstPos = -1, secondPos = -1;
    for (int i = 0; i < (int)flat.size(); i++) {
        if (flat[i] > 0) {
            if (firstPos == -1)
                firstPos = i;
            else {
                secondPos = i;
                break;
            }
        }
    }

    if (firstPos != -1 && secondPos != -1) {
        long long sum = 0;
        for (int i = firstPos + 1; i < secondPos; i++)
            sum += flat[i];
        cout << "2. Сума між першим і другим позитивними елементами: " << sum << "\n";
    }
    else {
        cout << "2. Менше двох позитивних елементів — сума не визначена.\n";
    }

    cout << "\n3. Матриця після переміщення нулів у кінець кожного рядка:\n";
    for (int i = 0; i < rows; i++) {
        stable_partition(matrix[i].begin(), matrix[i].end(),
            [](int x) { return x != 0; });
    }
    printMatrix(matrix);

    return 0;
}