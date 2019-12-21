#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix
{
  private: //variables that cant be acccess directly through the class
    std::vector< std::vector<float> > grid;
    std::vector<float>::size_type rows;
    std::vector<float>::size_type cols;

  public: //variables that can be acces directly through the class
    //constructor functions
    //here we instantiate what kind of objet our class can receive
    Matrix();
    Matrix(std::vector< std::vector<float> >);

    //set functions
    void setGrid(std::vector < std::vector<float> >);

    //get functions
    std::vector< std::vector<float> > getGrid();
    std::vector<float>::size_type getRows();
    std::vector<float>::size_type getCols();

    // matrix functions
    Matrix matrix_transpose();
    Matrix matrix_addition(Matrix);

    //print matrix function
    void print_matrix();
};

#endif /* MATRIX_H */
