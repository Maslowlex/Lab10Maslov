#include <stdio.h>
#include "timer.h"

int get_duration(int start_sec, int end_sec) {
    return end_sec - start_sec;
}

int check_status(int duration_sec) {
    if (duration_sec < 30) return -1; 
    if (duration_sec < 45) return 1;  
    return 0;                         
}

int get_full_minutes(int total_sec) {
    return total_sec / 60;
}

void print_time_mm_ss(int minutes, int seconds) {
    printf("%02d:%02d", minutes, seconds);
}

double get_speed(int track_length, int duration_sec) {
    if (duration_sec == 0) return 0.0;
    return ((double)track_length / duration_sec) * 3.6;
}

int is_dynamic_record(int duration_sec, int current_best) {
    if (current_best == 0 || duration_sec < current_best) {
        return 1;
    }
    return 0;
}
int apply_age_coefficient(int duration_sec, int age_group) {
    if (age_group == 1) return duration_sec - 15; 
    if (age_group == 3) return duration_sec - 10; 
    return duration_sec;                          
}
void process_stage(int start_sec, int end_sec, int track_length, int* current_best, int age_group) {
    int raw_duration = get_duration(start_sec, end_sec);
    int adjusted_duration = apply_age_coefficient(raw_duration, age_group);
    int status = check_status(adjusted_duration);

    int mins = get_full_minutes(adjusted_duration);
    int secs = adjusted_duration % 60;

    print_time_mm_ss(mins, secs);

    if (status == -1) {
        printf(" [Дисквалификация]");
    }
    else {
        if (is_dynamic_record(adjusted_duration, *current_best)) {
            printf(" [Новый рекорд дня!]");
            *current_best = adjusted_duration;
        }
        else if (status == 1) {
            printf(" [Рекорд!]");
        }
        else {
            printf(" [Норма]");
        }
    }
    double speed = get_speed(track_length, adjusted_duration);
    printf(" | Скорость: %.1f км/ч\n", speed);
}