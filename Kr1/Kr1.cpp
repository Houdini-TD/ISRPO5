// Kr1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Triangle.h"
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    int choice;
    double deltaAngle;
    double bisectorLength;
    double result[2];
    int selectedTriangleIndex = 0; 
    vector<Triangle> triangles; 

    int numTriangles;
    std::cout << "Введите количество треугольников: ";
    std::cin >> numTriangles;

    for (int i = 0; i < numTriangles; i++) {
        double side1, side2, angle;
        cout << "Введите сторону 1 для треугольника " << (i + 1) << ": ";
        cin >> side1;
        cout << "Введите сторону 2 для треугольника " << (i + 1) << ": ";
        cin >> side2;
        cout << "Введите угол между сторонами для треугольника " << (i + 1) << ": ";
        cin >> angle;

        triangles.push_back(Triangle(side1, side2, angle));
    }

    //triangles.push_back(Triangle(6, 7, 20));
    //triangles.push_back(Triangle(8, 9, 30));
    //triangles.push_back(Triangle(10, 11, 45));

    while (true) {
        cout << "Выберите треугольник (0 - " << (triangles.size() - 1) << "): ";
        cin >> selectedTriangleIndex;

        if (selectedTriangleIndex < 0 || selectedTriangleIndex >= triangles.size()) {
            std::cout << "Неверный выбор треугольника. Попробуйте еще раз." << std::endl;
            continue;
        }

        cout << "Выберите действие:" << endl;
        cout << "1. Вывести информацию о треугольнике" << endl;
        cout << "2. Увеличить один из углов" << endl;
        cout << "3. Получить длину биссектрисы" << endl;
        cout << "4. Получить длины отрезков, разделенных биссектрисой" << endl;
        cout << "5. Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << triangles[selectedTriangleIndex].toString() << endl;
            break;
        case 2:
            int angleNumber;
            cout << "Выберите номер угла (0, 1 или 2): ";
            cin >> angleNumber;
            cout << "Введите на сколько градусов увеличить угол: ";
            cin >> deltaAngle;
            triangles[selectedTriangleIndex].increaseAngle(angleNumber, deltaAngle);
            break;
        case 3:
            cout << "Введите номер угла (0, 1 или 2): ";
            cin >> angleNumber;
            bisectorLength = triangles[selectedTriangleIndex].getBisectorLength(angleNumber);
            cout << "Длина биссектрисы: " << bisectorLength << " см" << endl;
            break;
        case 4:
            cout << "Введите номер угла (0, 1 или 2): ";
            cin >> angleNumber;
            triangles[selectedTriangleIndex].getLengthOfSegmentsDividedByBisectors(angleNumber, result);
            cout << "Длины отрезков, разделенных биссектрисой: " << result[0] << " см и " << result[1] << " см" << endl;
            break;
        case 5:
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
        if (choice == 5)
            break;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
