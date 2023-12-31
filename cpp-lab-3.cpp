//
// Created by virag on 01.10.2023.
//
#include <iostream>
#include <cmath>

using namespace std;

long int min_raz = 1000000000; //ставим максимальное минимальное (чтоб нашлась хоть какая-то разница)
int n; // объявляем количество чашек
long int a[32] = { 0 }; // объявляем массив граммовок чашек (по условия 32 - максимальное количество чашек)

int t_one(long int p_m, long int p_p, int j) {
    if (j == n)  // когда перебрали все возможные варианты, то проверяем меньше ли они, чем существующая разница
    {
        if (abs(p_m - p_p) < min_raz)
            min_raz = abs(p_m - p_p);  // если да, то делаем замену существующей разницы на новую
    }
    else  {   // прибавляем j-ую порцию либо к маше (16 строка), либо к пете (17 строка)
        t_one (p_m + a[j], p_p, j + 1);
        t_one (p_m, p_p + a[j], j + 1);
    }
    return 0;
}

int main () {
    cin >> n;  // вводим сколько чашек у нас есть в действительности
    for (int i = 0; i < n; i++)
        cin >> a[i];  // вводим граммовки этих чашек, остальное - нули
    t_one(0, 0, 0); // изначально "на столах" ребят по ноль граммов каши
    cout << min_raz;
    return 0;
}