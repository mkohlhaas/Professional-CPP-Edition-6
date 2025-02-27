#include <cstdio>
#include <iostream>
#include <memory>
#include <print>

using namespace std;

namespace Datei
{
void close(FILE *filePtr)
{
    println("closing file...");

    if (filePtr == nullptr)
    {
        return;
    }
    fclose(filePtr);

    println("...file closed");
}
} // namespace Datei

int main()
{
    FILE            *f{fopen("data.txt", "w")};
    shared_ptr<FILE> filePtr{f, Datei::close};

    if (filePtr == nullptr)
    {
        println(cerr, "error opening file");
    }
    else
    {
        println("file opened");
        // use filePtr ...
        // ...
    }
}
