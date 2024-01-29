#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

istringstream iss;
ifstream in_stream;
ofstream out_stream;
char input_file[15];
int rows, columns;

void get_input_stream(ifstream& in_stream);
void invert(int** array);
void avrg_row(int** array);
void avrg_column(int** array);
void avrg_image(int** array);
void std_image(int** array);

int main() {

    get_input_stream(in_stream);

    // ----------------------------------------Read through the file and get the third line ----------------------------------------
    // Third line tells us the size of the m x n matrix, let m be the # of rows, n be the # of columns
    string line;
    int count;
    count = 0;
    while(count < 3) {
        getline(in_stream, line);
        count += 1;
    }
    istringstream iss(line);
    iss >> rows >> columns;
    

    // ----------------------------------------Create a dynamic array with rows, then iterate through to add columns to each row----------------------------------------
    int** array; 
    array = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        array[i] = new int[columns];
    }


    //----------------------------------------Function that inverts the image represented by the 2D array and writes it to 21006431_invert.ppm---------------------------------------- 
    invert(array);

    //----------------------------------------Functions that display statistics on the original image----------------------------------------
    avrg_row(array);
    avrg_column(array);
    avrg_image(array);
    std_image(array);

    cout << "Inverted image created as 21006431_invert.ppm " << endl;
    cout << "Stats file created as 21006431_stats.txt " << endl;
    //----------------------------------------Delete array afterwards----------------------------------------
    for(int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

//Ask user for input file name and open it
void get_input_stream(ifstream& in_s) {
    cout << "Please input the input file name: \n"; // Step (3)-A Get the file name
    cin >> input_file;

    in_s.open(input_file); // Step (3)-B - Connect to the input file and test
    if(in_s.fail( ))
    {
       cout << "Input file opening failed. \n";
       exit(1);  // if we couldn't open the file to read from we exit
    }
}

//Invert the image and write it to new 21006431_invert.ppm alongside with the first four lines staying the same
void invert(int** array) {
    string new_line;
    int num;
    int row;
    int column;
    int i;
    int count;
    count = rows + 4;
    i = 0;
    row = -4;
    in_stream.close();
    in_stream.open(input_file);
    out_stream.open("21006431_invert.ppm");

    while(i < count) {
        getline(in_stream, new_line);
        if (i < 4) {
            out_stream << new_line << "\n";
        } else {
            cout << new_line << endl;
            iss.clear();
            istringstream iss(new_line);
        
            while (iss.good()) {
                iss >> num;
                array[row][column] = num;
                column += 1;
            }
        }
        i += 1;
        row += 1;
        column = 0;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            out_stream << abs(255 - array[i][j]) << " ";
        }
        out_stream << "\n";
    }
    out_stream.close();
}

//Find average of each row and write the result into the  file
void avrg_row(int** array){
    out_stream.close();
    out_stream.open("21006431_stats.txt", std::ios_base::app);
    double row_sum;
    row_sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            row_sum += array[i][j];
        }
        out_stream << "Avg Row (" << i+1 << ") : " << row_sum/columns << "\n";
        row_sum = 0;
    }
}

//Find average of each column and write the result into the 21006431_stats file
void avrg_column(int** array){
    out_stream.close();
    out_stream.open("21006431_stats.txt", std::ios_base::app);
    double column_sum;
    column_sum = 0;

    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            column_sum += array[i][j];
        }
        out_stream << "Avg Col (" << j+1 << ") : " << column_sum/rows << "\n";
        column_sum = 0;
    }
}

//Find average of the image and write the result into the 21006431_stats file
void avrg_image(int** array){
    out_stream.close();
    out_stream.open("21006431_stats.txt", std::ios_base::app);
    double sum;
    sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += array[i][j];
        }
    }
    out_stream << "Avg Pixel: " << sum/(rows*columns) << endl;
}

//Compute standard deviation and write 6 values into the 21006431_stats file
void std_image(int** array) {
    out_stream.close();
    out_stream.open("21006431_stats.txt", std::ios_base::app);
    double sum, average, std_sum, std;
    sum = 0;
    average = 0;
    std_sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += array[i][j];
        }
    }
    average = sum/(rows*columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std_sum += (array[i][j] - average) * (array[i][j] - average);
        }
    }
    std = sqrt(std_sum/((rows*columns)-1));
    cout << "STD = " << std << endl;
    out_stream << left << setw(15) << setfill(' ') << "Average + 1 STD: ";
    out_stream << left << setw(15) << setfill(' ') << average + std;
    out_stream << left << setw(15) << setfill(' ') << "Average - 1 STD: ";
    out_stream << left << setw(15) << setfill(' ') << average - std << "\n";
    out_stream << left << setw(15) << setfill(' ') << "Average + 2 STD: ";
    out_stream << left << setw(15) << setfill(' ') << average + (2*std);
    out_stream << left << setw(15) << setfill(' ') << "Average - 2 STD: ";
    out_stream << left << setw(15) << setfill(' ') << average - (2*std) << "\n";
    out_stream << left << setw(15) << setfill(' ') << "Average + 3 STD: ";
    out_stream << left << setw(15) << setfill(' ') << average + (3*std);
    out_stream << left << setw(15) << setfill(' ') << "Average - 3 STD: ";
    out_stream << left << setw(15) << setfill(' ') << average - (3*std) << "\n";
}