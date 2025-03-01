﻿#include <format>
#include <iostream>
#include <print>
#include <string_view>

using namespace std;

enum class Language
{
    English,
    Dutch,
    German
};

string_view GetLocalizedFormat(Language language)
{
    switch (language)
    {
    case Language::English:
        return "Numbers: {0} and {1}.";
    case Language::Dutch:
        return "Getallen: {0} en {1}.";
    case Language::German:
        return "Zahlen: {0} und {1}.";
        break;
    }
    return "Numbers: {0} and {1}.";
}

int main()
{
    Language language{Language::English};

    int number1 = 1;
    int number2 = 2;
    vprint_unicode(cout, GetLocalizedFormat(language), make_format_args(number1, number2));
    println();

    language = Language::Dutch;
    vprint_unicode(cout, GetLocalizedFormat(language), make_format_args(number1, number2));
    println();

    language = Language::German;
    vprint_unicode(cout, GetLocalizedFormat(language), make_format_args(number1, number2));
    println();

    // The following call using print() does not compile.
    // print(GetLocalizedFormat(language), 1, 2);
}
