#include "ArticleCitations.h"
#include <fstream>
#include <print>
#include <stdexcept>

using namespace std;

ArticleCitations::ArticleCitations(const string &filename)
{
    // All we have to do is read the file.
    readFile(filename);
}

ArticleCitations::ArticleCitations(const ArticleCitations &src)
{
    copy(src);
}

ArticleCitations &ArticleCitations::operator=(const ArticleCitations &rhs)
{
    // Check for self-assignment.
    if (this == &rhs)
    {
        return *this;
    }
    // Free the old memory.
    delete[] m_citations;
    // Copy the data.
    copy(rhs);

    return *this;
}

void ArticleCitations::copy(const ArticleCitations &src)
{
    // Copy the article name, author, etc.
    m_article = src.m_article;
    // Copy the number of citations.
    m_numCitations = src.m_numCitations;
    // Allocate an array of the correct size.
    m_citations = new string[m_numCitations];
    // Copy each element of the array.
    for (int i{0}; i < m_numCitations; ++i)
    {
        m_citations[i] = src.m_citations[i];
    }
}

ArticleCitations::~ArticleCitations()
{
    delete[] m_citations;
}

void printStreamState(const istream &inputStream)
{
    if (inputStream.good())
    {
        println("stream state is good");
    }
    if (inputStream.bad())
    {
        println("stream state is bad");
    }
    if (inputStream.fail())
    {
        println("stream state is fail");
    }
    if (inputStream.eof())
    {
        println("stream state is eof");
    }
}

void ArticleCitations::readFile(const string &filename)
{
    // Open the file and check for failure.
    ifstream inputFile{filename};
    if (inputFile.fail())
    {
        throw invalid_argument{"Unable to open file"};
    }
    // Read the article author, title, etc. line.
    getline(inputFile, m_article);

    // Skip the whitespace before the citations start.
    inputFile >> ws;

    int count{0};
    // Save the current position so we can return to it.
    streampos citationsStart{inputFile.tellg()};
    // First count the number of citations.
    println("readFile(): counting number of citations");
    while (!inputFile.eof())
    {
        // Skip whitespace before the next entry.
        inputFile >> ws;
        printStreamState(inputFile);
        string temp;
        getline(inputFile, temp);
        printStreamState(inputFile);
        if (!temp.empty())
        {
            println("Citation {}: {}", count, temp);
            ++count;
        }
    }

    println("Found {} citations", count);
    println("readFile(): reading citations");
    if (count != 0)
    {
        // Allocate an array of strings to store the citations.
        m_citations    = new string[count];
        m_numCitations = count;
        // Seek back to the start of the citations.
        inputFile.seekg(citationsStart);
        // Read each citation and store it in the new array.
        for (count = 0; count < m_numCitations; ++count)
        {
            string temp;
            getline(inputFile, temp);
            printStreamState(inputFile);
            if (!temp.empty())
            {
                println("{}", temp);
                m_citations[count] = temp;
            }
        }
    }
    else
    {
        m_numCitations = -1;
    }

    println("readFile(): finished");
}

const string &ArticleCitations::getArticle() const
{
    return m_article;
}

int ArticleCitations::getNumCitations() const
{
    return m_numCitations;
}

const string &ArticleCitations::getCitation(int i) const
{
    return m_citations[i];
}
