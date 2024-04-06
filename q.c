/*!
@file       the name of source file is q.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 8
@date       file created on 21/10/2023
@brief      provide a brief explanation about what this source file does:
            
            This file is contains 5 function definetions to called by main in qdriver.
            Functions:
            - int read_data(char const *file_name, struct Tsunami *arr, int max_cnt);                   // read data from file and store into struct Tsunami containing objects month, day, year, fatalities, wave_height, location[100] in this order and idenify the numer of date sets.
            - void print_info(struct Tsunami const *arr, int size, FILE *out_stm);                      // print data stored in the structure Tsunami containing objects month, day, year, fatalities, wave_height, location[100] in this order.
            - double get_max_height(struct Tsunami const *arr, int size);                               // identify the highest value of the varrible (wave_height) in the structure array Tsunami.
            - double get_average_height(struct Tsunami const *arr, int size);                           // find the average of the highest value of the varrible (wave_height) in the structure array Tsunami by adding all the wave_height and divide it by the total number data sets.
            - void print_height(struct Tsunami const *arr, int size,double height, FILE *out_stm);      // identify if the the value of the varrible (wave_height) in the structure array Tsunami is higher then the average height and print the wave_height and the location.

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________*/


// TODO: Include all necessary C standard library headers 
#include "q.h"
// TODO: Definitions of functions declared in q.h go here ...

int read_data(char const *file_name, struct Tsunami *arr, int max_cnt){
    FILE *input_file = fopen(file_name, "r");                                                           // opening file file_name for read
    if (input_file == NULL){ fprintf(stderr, "Unable to open file\n"); exit(EXIT_FAILURE);}             // checking if file exist if print error statement and exit the programe

    //int month = 0, day = 0, year = 0, fatalities = 0, num_data = 0, i=0;
    //double wave_height = 0.00;
    //char location[100];

    int num_data = 0, i=0;

    while (i<max_cnt){
        //int result = fscanf(input_file, "%2d %2d %4d %6d %lf %[^\n]", &month, &day, &year, &fatalities, &wave_height, location);
        
        // scan data from file and store into objects of array structure Tsunami which are month, day, year, fatalities, wave_height, location[100] in this order
        int result = fscanf(input_file, "%2d %2d %4d %6d %lf %[^\n]", &arr[i].month, &arr[i].day, &arr[i].year, &arr[i].fatalities, &arr[i].wave_height, arr[i].location);

        if (result == 6){                                                                               // checking if 6 data is taken in by fscanf
            /*
            arr[i].month = month;
            arr[i].day = day;
            arr[i].year = year;
            arr[i].fatalities = fatalities;
            arr[i].wave_height = wave_height;
            strncpy(arr[i].location, location, sizeof(arr[i].location) - 1);
            */
            i++;num_data++;
        }
        else if(result == EOF){ break; }                                                                // leave loop when EOF is reached
    }

    fclose(input_file);                                                                                 // closing flie file_name
    return num_data;
}

void print_info(struct Tsunami const *arr, int size, FILE *out_stm){                                    // print data stored in the structure Tsunami containing objects month, day, year, fatalities, wave_height, location[100] in this order 
    for(int i=0; i<size ; i++){
        fprintf(out_stm,"%02d %02d %4d %6d %5.2lf %s\n", arr[i].month, arr[i].day, arr[i].year, arr[i].fatalities, arr[i].wave_height, arr[i].location);
    }
}

double get_max_height(struct Tsunami const *arr, int size){                                             // find the heighest value in array structure Tsunami.wave_height
    
    double max_height = 0.00;
    for(int i=0; i<size ; i++){  
        if(max_height < arr[i].wave_height){                                                            // assigning arr[i].wave_height to max_height if arr[i].wave_height is larger then
            max_height = arr[i].wave_height;  
        }  
    }
    return max_height;
}

double get_average_height(struct Tsunami const *arr, int size){                                         // find the average of the highest value of the varrible (wave_height) in the structure array Tsunami by adding all the wave_height and divide it by the total number data sets
    
    double sum = 0.00;
    for(int i=0; i<size ; i++){
        sum += arr[i].wave_height;                                                                      // adding all the wave_height
    }
    return sum/size;                                                                                     // dividing sum of all wave_height
}

void print_height(struct Tsunami const *arr, int size,double height, FILE *out_stm){                     // identify if the the value of the varrible (wave_height) in the structure array Tsunami is higher then the average height and print the wave_height and the location.
    
    
    for(int i=0; i<size ; i++){
        if(arr[i].wave_height >= height){                                                               // identify if the arr[i].wave_height higher then or equal to height then print wave_height and location
            fprintf(out_stm,"%4.2lf %s\n", arr[i].wave_height, arr[i].location);
        }
    }
}
