#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace Simon;

void loadFile(std::string filename, Matrix& data)
{
    ifstream file;
    file.open(filename);

    std::string line;
    std::vector<std::string> lines;

    if (file)
    {
        while (getline (file, line))
        {
            lines.push_back(line);
            data.load(lines);
        }
    }
    else
    {
        cout << "Failed to open " << filename << endl;
    }

    file.close();
}

int main() {
    //cout << "Enter the file name for the first year quarterly sales." << endl;
    //string file_1_name;
    //cin >> file_1_name;

    string file_1_name("/Users/simon/ClionProjects/lab_1_2/x.txt");

    Matrix data1;
    loadFile(file_1_name, data1);

    //cout << "Enter the file name for the second year quarterly sales." << endl;
    //string file_2_name;
    //cin >> file_2_name;

    string file_2_name("/Users/simon/ClionProjects/lab_1_2/y.txt");
    Matrix data2;
    loadFile(file_2_name, data2);

    cout << "Quarterly Sales Totals" << endl;
    Matrix sum = data1 + data2;
    cout << sum << endl;

    cout << "Quarterly Sales Increase" << endl;
    Matrix difference = data1 - data2;
    cout << difference << endl;

    return 0;
}