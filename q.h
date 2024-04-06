/*!
@file       the name of source file is q.h
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 8
@date       file created on 21/10/2023
@brief      provide a brief explanation about what this source file does:
            
            This file is contains 5 function declaraction be to called by main in qdriver.
            Functions:
            - int read_data(char const *file_name, struct Tsunami *arr, int max_cnt);                   // read data from file and store into struct Tsunami containing objects month, day, year, fatalities, wave_height, location[100] in this order and idenify the numer of date sets.
            - void print_info(struct Tsunami const *arr, int size, FILE *out_stm);                      // print data stored in the structure Tsunami containing objects month, day, year, fatalities, wave_height, location[100] in this order.
            - double get_max_height(struct Tsunami const *arr, int size);                               // identify the highest value of the varrible (wave_height) in the structure array Tsunami.
            - double get_average_height(struct Tsunami const *arr, int size);                           // find the average of the highest value of the varrible (wave_height) in the structure array Tsunami by adding all the wave_height and divide it by the total number data sets.
            - void print_height(struct Tsunami const *arr, int size,double height, FILE *out_stm);      // identify if the the value of the varrible (wave_height) in the structure array Tsunami is higher then the average height and print the wave_height and the location.

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

#ifndef Q_H
#define Q_H

// TODO: Include only those C standard library headers that declare/define names used in functions declared below
#include <stdio.h>  // for fprintf
#include <stdlib.h> // for exit
#include <string.h> // strncpy

// TODO: A function documentation block provides information that is crucial
// TODO: Now, declare the necessary function.
// TODO: Repeat function documentation block plus function declaration for remaining functions
struct Tsunami {
    int month, day, year, fatalities;
    double wave_height;
    char location[100];
};

int read_data(char const *file_name, struct Tsunami *arr, int max_cnt);                 // read data from file and store into struct Tsunami containing objects month, day, year, fatalities, wave_height, location[100] in this order and idenify the numer of date sets.
void print_info(struct Tsunami const *arr, int size, FILE *out_stm);                    // print data stored in the structure Tsunami containing objects month, day, year, fatalities, wave_height, location[100] in this order.
double get_max_height(struct Tsunami const *arr, int size);                             // identify the highest value of the varrible (wave_height) in the structure array Tsunami.
double get_average_height(struct Tsunami const *arr, int size);                         // find the average of the highest value of the varrible (wave_height) in the structure array Tsunami by adding all the wave_height and divide it by the total number data sets.
void print_height(struct Tsunami const *arr, int size,double height, FILE *out_stm);    // identify if the the value of the varrible (wave_height) in the structure array Tsunami is higher then the average height and print the wave_height and the location.

#endif
