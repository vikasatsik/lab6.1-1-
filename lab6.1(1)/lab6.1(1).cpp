// lab6.1(1).cpp 
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Сацик Вікторії
//17 варіант

#include <iostream>
#include <iomanip>

using namespace std;

void Filling(int* list, const int size, const int Low, const int High);
void Calculate(int* list, const int size, int& sum, int& count);
void Output(int* list, const int size);

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    srand((unsigned)time(NULL));
    srand(1);//для перевірки правильності способів
    const int n = 25;
    int r[n];

    int Min = 4;
    int Max = 73;

    int sum = 0;
    int count = 0;

    cout << "ітераційний спосіб" << endl;
    cout << endl;

    Filling(r, n, Min, Max);
    cout << "Before: "; Output(r, n);

    Calculate(r, n, sum, count);
    cout << "After:  "; Output(r, n);

    cout << endl;

    cout << "Sum: " << setw(4) << sum << endl
        << "Count: " << setw(2) << count << endl;
}

// Заповнення масиву випадковими значеннями
void Filling(int* list, const int size, const int Min, const int Max)
{
    for (int i = 0; i < size; i++)
        list[i] = rand() % (Max - Min + 1) + Min; // де Min - ліва межа, а Max - права
}

// обчислення кількості, суми та присвоєння елементам, що підходять по умові значення 0
void Calculate(int* list, const int size, int& sum, int& count) {
    for (int i = 0; i < size; i++)
    {
        if (!(list[i] % 6==0|| list[i] % 5== 0)) { // всі кратні 6 або з індексами: крім кратних 5.
            sum += list[i];
            list[i] = 0;
            count++;
        }
    }
}

// Вивід масиву
void Output(int* list, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(3) << list[i];
    cout << endl;
}