#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Display {

};

class DisplayMainMenu {
    private:
        const vector<string> options{"Start new game"}; // list of options
        const string border = "----------------------------"; // the border to be printed before and after the menu
        const string indent = "        "; // the indent to print before each line, excluding the border lines
        void print() const;
        friend class Display;
    public:
        vector<string> getOptions() const;
};