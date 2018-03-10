// Institutionen för tillämpad fysik och elektronik
// Inlämningsdatum:    201803
// Kursnamn:           5EL142  Linux som utvecklingsmiljö 7.5 hp 25%
// Termin:             VT 2018
// Laborationens namn: Övning 6. Bibliotek
// Student:            PETER OLSSON 19610419-8210

#ifndef _MY_E_RESISTANCE_H
#define _MY_E_RESISTANCE_H

typedef int bool;
#define true 1
#define false 0

int e_resistance(float orig_resistance, float *res_array );
bool get_one_exists_in_array(float orig_resistance, int resistanser_E12[], int antal_resistanser, float three_values[]);
bool get_two_exists_in_array(float orig_resistance, int resistanser_E12[], int antal_resistanser, float three_values[]);
bool get_three_exists_in_array(float orig_resistance, int resistanser_E12[], int antal_resistanser, float three_values[]);

#endif
