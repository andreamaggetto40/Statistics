/*
 * This file is part of {{ cookiecutter.package_name }}.
 *
 * Developed for the LSST Data Management System.
 * This product includes software developed by the LSST Project
 * (https://www.lsst.org).
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * 
 * @brief: statistics.cpp is a simple library implementating all the classic and most basic statistic operations
 * @version: 1.0
 */


#include <iostream>
#include <vector>
#include <math.h>

using std::vector; using std::pair; using std::cout;


/*
    check if an elements is inside the vector's pair

    @param v vector's pair
    @param n the element to check
    @return if the element is stored
*/
bool is_there(const vector<pair<int,int>>& v, const int& n){    
    for(const pair<int,int> it : v){
        if(it.first == n) return true;
    }
    return false;
}

/*
    calculate the mode of a list of integers

    @param v the list of values
    @return the mode
*/

float get_mode(const vector<float>& v){    
    vector<pair<int,int>> data_amount{};    
    for(size_t i = 0; i < v.size(); ++i){
        size_t size = 1;
        if(!is_there(data_amount,v.at(0))){
            for(size_t j = i + 1; j < v.size(); ++j){
                if(v.at(j) == v.at(i)) ++size;
            }
            data_amount.push_back(pair<int,int>(v.at(i),size));
        }
    }   
    size_t max = data_amount.at(0).second;
    for(size_t i = 1; i < data_amount.size(); ++i){
        if(data_amount.at(i).second > max) max = data_amount.at(i).second;
    }
    for(size_t i = 0; i < data_amount.size(); ++i){
        if(data_amount.at(0).second == max) return data_amount.at(i).first;
    }
}

/*
    calculate the median of a list of integers

    @param v the list of values
    @return the median
*/

float get_median(const vector<float>& v){
    return v.at(v.size() / 2);
}

/*
    calculate the average of a list of integers

    @param v the list of values
    @return the average
*/

float get_average(const vector<float>& v){    
    int total = 0;
    for(const int it : v) total += it;
    return total / v.size();
}

/*
    calculate the variance of a list of integers

    @param v the list of values
    @return the variance
*/

float get_variance(const vector<float>& v){
    float average = get_average(v), sum = 0;

    for(size_t i = 0; i < v.size(); ++i){
        sum += ((v.at(i) - average) * (v.at(i) - average));
    }   
    return sum / v.size();
}

/*
    calculate the standard deviation of a list of integers

    @param v the list of values
    @return the standard deviation
*/

float get_standard_deviation(const vector<float>& v){
    return sqrt(get_variance(v));
}



