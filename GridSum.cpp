// CSE 101 Winter 2016, PA 3
//
// Name: Nasa Iwai 
// Sources of Help: TODO
// Due: February 19th, 2016 at 11:59 PM

#ifndef __GRID_SUM_CPP__
#define __GRID_SUM_CPP__

#include "TwoD_Array.hpp"
#include "GridSum.hpp"

// Perform the precomputation step here
// Compute sum for (0, 0) to (n, m)
GridSum::GridSum (TwoD_Array<int>& grid) {
    // TODO
    int colSum = 0;
    pg = new TwoD_Array<int>(grid.getNumRows(), grid.getNumCols());
    pg->at(0, 0) = grid.at(0, 0);

    //first row of sum aray
    for(int col = 1; col < grid.getNumCols(); col++) {
        pg->at(0, col) = pg->at(0, col - 1) + grid.at(0, col);
    }

    //first colomn of sum array
    for(int row = 1; row < grid.getNumRows(); row++) {
        pg->at(row, 0) = pg->at(row - 1, 0) + grid.at(row, 0);            
    }    
    for(int col = 1; col < grid.getNumCols(); col++) {
        colSum = grid.at(0, col);
        for(int row = 1; row < grid.getNumRows(); row++) {
            pg->at(row, col) = pg->at(row, col - 1) + grid.at(row, col) + colSum;
            colSum += grid.at(row, col);
        }    
    }

}

// Perform the query step here
// To get sum for square ABCD, we will calculate as follows:
// ABCD = OD - OB - OC = OA
int GridSum::query (int x1, int y1, int x2, int y2) {
    // TODO

    int sumOA = 0;
    int sumOB = 0;
    int sumOC = 0;
    int sumOD = 0;
    if(x1 == 0 || y1 == 0)
        sumOA = 0;
    else
        sumOA = pg->at(x1-1, y1-1);
    if(y1 == 0)
        sumOB = 0;
    else    
        sumOB = pg->at(x2, y1-1);
    if(x1 == 0)
        sumOC = 0;
    else
        sumOC = pg->at(x1-1, y2);
    sumOD = pg->at(x2, y2);
    return sumOD - sumOB - sumOC + sumOA;

}

#endif
