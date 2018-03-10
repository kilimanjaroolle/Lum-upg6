// Institutionen för tillämpad fysik och elektronik
// Inlämningsdatum:    201803
// Kursnamn:           5EL142  Linux som utvecklingsmiljö 7.5 hp 25%
// Termin:             VT 2018
// Laborationens namn: Övning 6. Bibliotek
// Student:            PETER OLSSON 19610419-8210

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include "component.h"

typedef int bool;
#define true 1
#define false 0

int e_resistance(float orig_resistance, float *res_array)
{
  int antal = -1;
  int antal_resistanser = 12;
  int* resistanser_E12 = (int[12]){10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};
  bool har_ratt_intervall = true;
  while (har_ratt_intervall)
  {
    if (resistanser_E12[antal_resistanser - 12] <= orig_resistance && orig_resistance <= 10*resistanser_E12[antal_resistanser - 12])
    {
      har_ratt_intervall = false;
    }
    else
    {
      int* resistanser_E12_kopia = malloc((antal_resistanser + 12)*sizeof(int));
      for (int i=0; i < antal_resistanser; i++) 
      {
        resistanser_E12_kopia[i] = resistanser_E12[i];
      }
      for (int i=antal_resistanser; i < antal_resistanser + 12; i++) 
      {
        resistanser_E12_kopia[i] = 10*resistanser_E12[i - 12];
      }

      antal_resistanser = antal_resistanser + 12;
      resistanser_E12 = malloc(antal_resistanser*sizeof(int));
      for (int i=0; i < antal_resistanser; i++) 
      {
        resistanser_E12[i] = resistanser_E12_kopia[i];
      }
    }
  }
  if (get_one_exists_in_array(orig_resistance, resistanser_E12, antal_resistanser, res_array))
  {
    antal = 1;
  }
  else if (get_two_exists_in_array(orig_resistance, resistanser_E12, antal_resistanser, res_array))
  {
    antal = 2;
  }
  else if (get_three_exists_in_array(orig_resistance, resistanser_E12, antal_resistanser, res_array))
  {
    antal = 3;
  }
  else // if 10*resistanser_E12[antal_resistanser - 12] >= orig_resistance
  {
    antal = -1;
  }

  return antal;
}

bool get_one_exists_in_array(float orig_resistance, int resistanser_E12[], int antal_resistanser, float three_values[])
{
  for (int i=0; i < antal_resistanser; i++) 
  {
    int first_value = resistanser_E12[i];
    if (first_value == orig_resistance)
    {
      three_values[0] = first_value;
      three_values[1] = -1;
      three_values[2] = -1;
      return true;
    }
  }

  three_values[0] = -1;
  three_values[1] = -1;
  three_values[2] = -1;
  return false;
}

bool get_two_exists_in_array(float orig_resistance, int resistanser_E12[], int antal_resistanser, float three_values[])
{
  for (int i=0; i < antal_resistanser; i++) 
  {
    int first_value = resistanser_E12[i];
    for (int j=0; j < antal_resistanser; j++) 
    {
      int second_value = resistanser_E12[j];
      if (second_value != first_value)
      {
        if ((second_value + first_value) == orig_resistance)
        {
          three_values[0] = first_value;
          three_values[1] = second_value;
          three_values[2] = -1;
          return true;
        }
      }
    }
  }

  three_values[0] = -1;
  three_values[1] = -1;
  three_values[2] = -1;
  return false;
}

bool get_three_exists_in_array(float orig_resistance, int resistanser_E12[], int antal_resistanser, float three_values[])
{
  for (int i=0; i < antal_resistanser; i++) 
  {
    int first_value = resistanser_E12[i];
    for (int j=0; j < antal_resistanser; j++) 
    {
      int second_value = resistanser_E12[j];
      if (second_value != first_value)
      {
        for (int k=0; k < antal_resistanser; k++) 
        {
          int third_value = resistanser_E12[k];
          if (third_value != first_value && third_value != second_value)
          {
            if ((third_value + second_value + first_value) == orig_resistance)
            {
              three_values[0] = first_value;
              three_values[1] = second_value;
              three_values[2] = third_value;
              return true;
            }
          }
        }
      }
    }
  }

  three_values[0] = -1;
  three_values[1] = -1;
  three_values[2] = -1;
  return false;
}

