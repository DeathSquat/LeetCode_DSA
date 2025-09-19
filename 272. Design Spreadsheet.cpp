#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    // store cell values in a map: (row, col) -> value
    unordered_map<string, int> table;

    Spreadsheet(int rows) {
        // no need to prefill, default is 0
    }
    
    void setCell(string cell, int value) {
        table[cell] = value;
    }
    
    void resetCell(string cell) {
        table[cell] = 0;
    }
    
    int getValue(string formula) {
        // formula is always of form =X+Y
        // strip '='
        formula = formula.substr(1);
        
        // split by '+'
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        
        return parseValue(left) + parseValue(right);
    }

private:
    int parseValue(const string& token) {
        // check if token is a number or cell reference
        if (isdigit(token[0])) {
            return stoi(token);
        } else {
            // token is like A1, B2, etc.
            if (table.find(token) != table.end()) {
                return table[token];
            } else {
                return 0;
            }
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
