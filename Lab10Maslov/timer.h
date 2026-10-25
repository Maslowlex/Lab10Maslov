#ifndef TIMER_H
#define TIMER_H

int get_duration(int start_sec, int end_sec);
int check_status(int duration_sec);
int get_full_minutes(int total_sec);
void print_time_mm_ss(int minutes, int seconds);
void process_stage(int start_sec, int end_sec, int track_length, int* current_best, int age_group);

double get_speed(int track_length, int duration_sec);
int is_dynamic_record(int duration_sec, int current_best);
int apply_age_coefficient(int duration_sec, int age_group);

#endif