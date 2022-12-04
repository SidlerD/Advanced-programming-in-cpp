#pragma once
#include <iostream>

class FileLocker{
    std::string fname;

    void unlock();
    void lock();

public:
    FileLocker(std::string file);
    ~FileLocker();
};