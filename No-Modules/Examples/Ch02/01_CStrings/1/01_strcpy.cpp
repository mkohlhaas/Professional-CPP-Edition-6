#include <cstring>
#include <print>

using namespace std;

char *copyString(const char *str)
{
    char *result{new char[strlen(str) + 1]};
    strcpy(result, str);
    return result;
}

char *appendStrings(const char *str1, const char *str2, const char *str3)
{
    char *result{new char[strlen(str1) + strlen(str2) + strlen(str3) + 1]};
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    return result;
}

int main()
{
    const char *str1{"Hello"};
    char       *copy{copyString(str1)};
    println("{}", copy);
    delete[] copy;
    copy = nullptr;

    const char *str2{" World"};
    const char *str3{"!"};
    char       *result{appendStrings(str1, str2, str3)};
    println("{}", result);
    delete[] result;
    result = nullptr;
}
