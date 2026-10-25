#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "timer.h" 

double fa(double x);
double fb(double x);
double fc(double x);

int main() {
    setlocale(LC_ALL, "RUS");
    int task_choice;

    printf("Выберите задание для запуска:\n");
    printf("1 - Задача 10.1 (Вычисление функций)\n");
    printf("2 - Система хронометража\n");
    printf("Ваш выбор: ");
    scanf("%d", &task_choice);

    if (task_choice == 1) {
        zad10_1(); 
    }
    else if (task_choice == 2) {
        char athlete_code;
        int start_sec, end_sec;
        int track_length;
        int current_best = 0;
        int age_group;

        printf("\n--- СИСТЕМА ХРОНОМЕТРАЖА ---\n");
        printf("Введите длину трассы (в метрах): ");
        scanf("%d", &track_length);

        while (1) {
            printf("\nВведите код спортсмена (или '!' для выхода): ");
            scanf(" %c", &athlete_code);

            if (athlete_code == '!') break;

            printf("Введите возрастную группу (1-дети, 2-взрослые, 3-ветераны): ");
            scanf("%d", &age_group);

            printf("Введите время старта (в секундах): ");
            scanf("%d", &start_sec);

            printf("Введите время финиша (в секундах): ");
            scanf("%d", &end_sec);

            printf("Спортсмен %c: ", athlete_code);
            process_stage(start_sec, end_sec, track_length, &current_best, age_group);
        }
        printf("\nСоревнования завершены!\n");
    }
    else {
        printf("Неверный выбор.\n");
    }

    return 0;
}
double fa(double x) {
    double y;
    if (x <= 3.0) {
        y = x * x - 3.0 * x + 9.0;
    }
    else {
        y = 1.0 / (x * x * x + 3.0);
    }
    return y;
}

double fb(double x) {
    return x * exp(sin(x * x));
}

double fc(double x) {
    return x * x + 3 * x - 1;
}
int zad10_1() {
    double x;
    int choice;
    printf("\n--- Задача 10.1 ---\n");
    printf("Введите значение x: ");
    scanf("%lf", &x);

    double val_a = fa(x);
    double val_b = fb(x);
    double val_c = fc(x);
    double mult = val_a * val_b * val_c;
    double diff_squares = (val_a * val_a) - (val_b * val_b) - (val_c * val_c);
    double double_sum = 2.0 * (val_a + val_b + val_c);

    printf("\n--- МЕНЮ ---\n");
    printf("1 - Значение функции F1(x)\n");
    printf("2 - Значение функции F2(x)\n");
    printf("3 - Значение функции F3(x)\n");
    printf("4 - Произведение F1(x) * F2(x) * F3(x)\n");
    printf("5 - Разность квадратов F1^2(x) - F2^2(x) - F3^2(x)\n");
    printf("6 - Удвоенная сумма 2 * (F1(x) + F2(x) + F3(x))\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
    case 1:
        printf("F1(x) = %lf\n", val_a);
        break;
    case 2:
        printf("F2(x) = %lf\n", val_b);
        break;
    case 3:
        printf("F3(x) = %lf\n", val_c);
        break;
    case 4:
        printf("Произведение: %lf\n", mult);
        break;
    case 5:
        printf("Разность квадратов: %lf\n", diff_squares);
        break;
    case 6:
        printf("Удвоенная сумма: %lf\n", double_sum);
        break;
    default:
        printf("Неверный выбор.\n");
    }
    return 0;
}