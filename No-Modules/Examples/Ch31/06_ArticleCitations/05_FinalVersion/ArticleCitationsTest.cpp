#include "ArticleCitations.h"
#include <iostream>
#include <print>

using namespace std;

void processCitations(ArticleCitations cit)
{
    println("{}", cit.getArticle());
    for (int i{0}; i < cit.getNumCitations(); ++i)
    {
        println("{}", cit.getCitation(i));
    }
}

int main()
{
    while (true)
    {
        print("Enter a file name (\"STOP\" to stop): ");
        string filename;
        cin >> filename;
        if (filename == "STOP")
        {
            break;
        }

        ArticleCitations cit{filename};
        processCitations(cit);
    }
}
