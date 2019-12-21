#include "matrix.h"

// Creates an initial matrix
Matrix::Matrix() {
  std::vector< std::vector<float> > initial_grid(
      10, std::vector<float>(5,0.5));
  grid = initial_grid;
  rows = initial_grid.size();
  cols = initial_grid[0].size();

}

Matrix::Matrix(std::vector< std::vector<float> > initial_grid) {
  grid = initial_grid;
  rows = initial_grid.size();
  cols = initial_grid[0].size();
}

//create set functions

void Matrix::setGrid(std::vector< std::vector<float> > new_grid) {
    grid = new_grid;
    rows = new_grid.size();
    cols = new_grid[0].size();
}

//create get functions

std::vector< std::vector<float> > Matrix::getGrid() {
  return grid;
}

std::vector<float>::size_type Matrix::getRows() {
  return rows;
}

std::vector<float>::size_type Matrix::getCols() {
  return cols;
}

//create matrix functions
Matrix Matrix::matrix_transpose() {
  std::vector< std::vector<float> > new_grid;
  std::vector<float> row;

  for (int i=0; i<cols; i++) {
    row.clear();

    for (int j=0; j<cols; j++) {
        row.push_back(grid[j][i]);
    }
    new_grid.push_back(row);
  }
  return Matrix(new_grid);
}

Matrix Matrix::matrix_addition(Matrix other) {
  // check that both matrices are the same size
  if((rows != other.getRows()) || (cols != other.getCols())) {
    throw std::invalid_argument("matrices are not the same size");
  }
  std::vector< std::vector<float> >othergrid = other.getGrid();
  std::vector< std::vector<float> > result;
  std::vector<float> new_row;

  for (int i=0; i<rows; i++) {
    new_row.clear();
    for (int j=0; j<cols; j++) {
      new_row.push_back(grid[j][i] + othergrid[j][i]);
    }
    result.push_back(new_row);
  }
  return Matrix(result);
}

void Matrix::print_matrix() {
  //print and empty line
  std::cout << std::endl;

  for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
      std::cout<<grid[j][i]<<" ";
    }
    std::cout<<std::endl;
  }

}
