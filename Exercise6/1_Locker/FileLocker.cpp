#include "FileLocker.h"
#include <iostream>

FileLocker::FileLocker(std::string file): fname(file) {
    lock();
}
FileLocker::~FileLocker(){ unlock(); }

void FileLocker::lock(){
    std::cout << fname << " is now LOCKED\n";
}

void FileLocker::unlock(){
    std::cout << fname << " is now UNLOCKED\n";
}