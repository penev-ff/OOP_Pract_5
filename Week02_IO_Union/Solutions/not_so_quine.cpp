#include <fstream>
#include <iostream>

using namespace std;

const size_t BUFFER_SIZE = 1024;

int main()
{
    const char *path = "not_so_quine.cpp";

    // ifstream sourceFile;
    // sourceFile.open(path);
    
    // Equivalent
    ifstream sourceFile(path);

    if (!sourceFile.is_open())
    {
        // No need of flush / endl
        // cerr is auto flushed
        cerr << "Could not open " << path;
        return 1;
    }

    char buffer[BUFFER_SIZE]{};

    while (sourceFile >> buffer)
    {
        cout << buffer;
    }

    // Alternatives
    //
    // sourceFile.clear();
    // sourceFile.seekg(0, std::ios::beg);

    // while (sourceFile.getline(buffer, BUFFER_SIZE))
    // {
    //     cout << buffer;
    // }

    // char ch;
    // while (sourceFile.get(ch))
    // {
    //     cout << ch;
    // }

    return 0;
}