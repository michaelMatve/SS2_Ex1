#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

namespace ariel{
        std::string mat(int weight, int length, char firest_simbol, char second_simbol){
        
        if(length%2 == 0)
        {
            throw std::invalid_argument("bad input can get only odd");
        }
       
        if(weight%2 == 0)
        {
            throw std::invalid_argument("bad input can get only odd");
        }
        
        if(firest_simbol == ' ' || firest_simbol == '\n' || firest_simbol == '\t' || firest_simbol == '\r')
        {
            throw std::invalid_argument("bad input for simbol A");
        }
        
        if(second_simbol == ' ' || second_simbol == '\n' || second_simbol == '\t' || second_simbol == '\r')
        {
            throw std::invalid_argument("bad input for simbol B");
        }
        char matrix[length][weight];
        char simbol = firest_simbol;
        for(int count=0; (count<length+1/2) && (count<weight+1/2); count++)
        {
            if(count%2 == 0)
            {
                simbol = firest_simbol;
            }
            else
            {
                simbol = second_simbol;
            }
            
            for(int coulm=count; coulm<weight-count ; coulm++)
            {
                matrix[count][coulm] = simbol;
            }

            for(int coulm=count; coulm<weight-count ; coulm++)
            {
                matrix[length-1-count][coulm] = simbol;
            }

            for(int row=count; row<length-count ; row++)
            {
                matrix[row][count] = simbol;
            }

            for(int row=count; row<length-count ; row++)
            {
                matrix[row][weight-1-count] = simbol;
            }
        }
        std::string st = "";
        for(int row=0 ; row < length ; row++)
        {
            for(int coulm = 0 ; coulm < weight; coulm++)
            {
                st = st +matrix[row][coulm];
            }
            st = st + "\n";
        }
        return st;
    }
}