//
// Created by Preston Hunter on 10/9/2022.
//
#include "Card.h"
#include "vector"
#include "iostream"

using std::vector;

bool cardVectorsEqual(const vector<Card>& v1,  const vector<Card>& v2){
    if (v1.size() != v2.size())
        return false;

    for (int i = 0; i < v1.size(); i++){
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}