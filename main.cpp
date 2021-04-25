#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Queue<int> Q1;
    int k,d;
    int i = 0;
    Q1.printQueue("пустая");
    cout << "Введите первый элемент" << endl;
    cin >> k;
    Q1.Push(k);
    Q1.printQueue("добавили 1 элемент");
    cout << "Введите еще несколько элементов" << endl;
    while (i < 5) {
        cin >> k;
        Q1.Push(k);
        i++;
    }
    Q1.printQueue("добавили еще элменетов");

    d = Q1.GetItem();
    cout << "первый элеменет из очереди: " << d << endl;

    Q1.printQueue("оригинал");

    Queue<int> Q2 = Q1;
    Q2.printQueue("копия");

    Queue<int> Q3;
    Q3 = Q1 = Q2;
    Q1.Push(12);
    Q1.printQueue("добавили еще элменет в первую очередь");
    Q2.Push(13);
    Q2.printQueue("добавили еще элменет во вторую очередь");
    Q1.printQueue("первая");
    Q2.printQueue("вторая");
    Q3.printQueue("третья");

    Q2.clear();
    cout << "Очистили вторую очередь, и проверим, очистилась ли она" << endl;
    if (Q2.IsEmpty())
        Q2.printQueue("вторая пустая");
    else
        Q2.printQueue("вторая не пустая");

    cout << "Проверим сколькок элементов в 3 очереди" << endl;
    cout << "Кол-во элементов в очереди " << Q3.GetN() << endl;
}
