#ifndef MY_DEFINE_H
#define MY_DEFINE_H
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"

int check_birth(char *str, int bir);
void print_info();
void registration(person **arr, int *num, int *MAX_NUM);
void showALL(person **arr, int *num);
void Delete(person **arr, int *num);
void Findbybirth(person **arr, int *num);
void SaveFromFile(person **arr, int *num);
void RegFromFile(person **arr, int *num, int *MAX_NUM);


#endif
