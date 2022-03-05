#include <iostream>
#include <fstream>

#include "elective_course.hpp"
#include "zuzi.hpp"

#define DEBUG_MODE false

using namespace std;

const size_t BUFFER_SIZE = 1024;

void load_cli(char cli[], const char *cliFilePath)
{
    // Same as != nullptr
    if (!cliFilePath)
    {
        return;
    }

    ifstream cliFile(cliFilePath);

    if (!cliFile.is_open())
    {
        cerr << "Could not open " << cliFilePath << "!\n";
        return;
    }

    size_t pos = 0;
    while (!cliFile.eof())
    {
        cli[pos] = cliFile.get();
        ++pos;
    }

    cli[pos - 1] = '\0';
}

void load_storage(Zuzi &zuzi, const char *storageFilePath)
{
    // Same as != nullptr
    if (!storageFilePath)
    {
        return;
    }

    ifstream storageFile(storageFilePath);

    if (!storageFile.is_open())
    {
        cerr << "Could not open " << storageFilePath << "!\n";
        return;
    }

    char buffer[BUFFER_SIZE]{};
    // Skip the CSV header
    storageFile.getline(buffer, BUFFER_SIZE);

    while (!storageFile.eof())
    {
        storageFile.getline(buffer, BUFFER_SIZE);

        ElectiveCourse course;
        parse_course(course, buffer);
        add_course(zuzi, course);
    }
}

void save_storage(const Zuzi &zuzi, const char *storageFilePath)
{
    ofstream storageFile(storageFilePath);

    // Same as != nullptr
    if (!storageFilePath)
    {
        return;
    }

    if (!storageFile.is_open())
    {
        cerr << "Could not open " << storageFilePath << "!\n";
        return;
    }

    // CSV header
    storageFile << "id,"
                << "name,"
                << "category,"
                << "assessment" << endl;

    for (int i = 0; i < zuzi.size; ++i)
    {
        ElectiveCourse course = zuzi.courses[i];

        storageFile << course.id << ','
                    << course.name << ','
                    << course.category << ','
                    << course.assessment;

        if (i != zuzi.size - 1)
        {
            storageFile << endl;
        }
    }
}

void app(const char *cliFilePath, const char *storageFilePath)
{
    Zuzi zuzi;

    char cli[BUFFER_SIZE]{};
    load_cli(cli, cliFilePath);

    bool running = true;
    while (running)
    {
        cout << cli << endl;

        int opt;
        cin >> opt;

        switch (opt)
        {
        case 1:
            load_storage(zuzi, storageFilePath);
            break;
        case 2:
            save_storage(zuzi, storageFilePath);
            break;
        case 5:
            running = false;
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    const int EXPECTED_ARGS = 3;

    if (argc != EXPECTED_ARGS)
    {
        cerr << "The first argument should be the cli path.\n";
        cerr << "The second argument should be the storage path.\n";
    }

#if DEBUG_MODE
    char arg1[] = "cli.txt";
    char arg2[] = "storage.csv";
#endif

    app(argv[1], argv[2]);

    return 0;
}