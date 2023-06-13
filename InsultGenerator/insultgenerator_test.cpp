#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <iterator>
#include "insultgenerator_test.h"
using namespace std;

FileException::FileException(const string& m) : msg(m) {}
string FileException::what() const { return msg; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : msg(m) {}
string NumInsultsOutOfBounds::what() const { return msg; }

void InsultGenerator::initialize() {
    string file_first;
    string file_second;
    string file_third;
    
    std::ifstream myfile("InsultsSource.txt");
    if (myfile.fail()) { // throw file exception
        throw FileException("File cannot be read.");
        return;
    }

    // split the columns and while it does not reach the end of the file:
    while (myfile >> file_first >> file_second >> file_third) {
      first.push_back(file_first);
      second.push_back(file_second);
      third.push_back(file_third);
    }
}

string InsultGenerator::talkToMe() const{
    int first_random = (rand() % 50);   // generate a random number
    int second_random = (rand() % 50);  // based on the column size
    int third_random = (rand() % 50);

    return "Thou " + first[first_random] + " " + second[second_random] + " " +
            third[third_random] + "!";
};

vector<string> InsultGenerator::generate(int inputNumber) const{
    vector<string> total;
    string temp;
    if (inputNumber <= 0 || inputNumber > 10000) {
      throw NumInsultsOutOfBounds("Number is out of bounds.");
    }

    while (total.size() != inputNumber) {
      InsultGenerator one;
      temp = one.talkToMe();
      if (find(total.begin(), total.end(), temp) == total.end()) {
        total.push_back(temp);
      }
    }
    return total;
  };

void InsultGenerator::generateAndSave(string fileName, int inputNumber) {
    vector<string> finalSave;
    if (inputNumber <= 0 || inputNumber > 10000) {
      throw NumInsultsOutOfBounds("Number is out of bounds.");
    }
    InsultGenerator one;
    one.initialize();
    finalSave = one.generate(inputNumber);
    sort(finalSave.begin(), finalSave.end());

    // save the insults to a file
    ofstream saveFile(fileName);
    ostream_iterator<string> saveIterator(saveFile, "\n");
    copy(finalSave.begin(), finalSave.end(), saveIterator);
  };