﻿#include <cctype>
#include <locale>
#include <print>

using namespace std;

int main()
{
    println("É {}", isupper(L'É', locale{"fr-FR"}));
    println("é {}", isupper(L'é', locale{"fr-FR"}));
}
