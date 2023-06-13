#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <time.h>
using namespace std;

class FileException {
public:
    FileException(const string&);
    string what() const;
private:
    string msg;
};

class NumInsultsOutOfBounds {
public:
    NumInsultsOutOfBounds(const string&);
    string what() const;
private:
    string msg;
};

class InsultGenerator {
public:
    void initialize();
    string talkToMe() const;
    vector<string> generate(int) const;
    void generateAndSave(string, int);
private:
    vector<string> first;
    vector<string> second;
    vector<string> third;
};