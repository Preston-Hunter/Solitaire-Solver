//
// Created by Preston Hunter on 10/9/2022.
//

#ifndef SOLITAIRE_SOLVER_HELPERFUNCTIONS_H
#define SOLITAIRE_SOLVER_HELPERFUNCTIONS_H

#endif //SOLITAIRE_SOLVER_HELPERFUNCTIONS_H
#include "Card.h"
#include "vector"
using std::vector;

bool cardVectorsEqual(const vector<Card>& v1,  vector<Card>& v2){
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); i++){
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}
