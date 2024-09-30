#include "space_age.h"

float age(planet_t planet, int64_t seconds){
    float e_seconds = seconds / 31557600; 
    switch(planet){
        case 0: return e_seconds / 0.2408467;
                break;
        case 1: return e_seconds /  0.61519726;
                break;
        case 2: return e_seconds;
                break;
        case 3: return e_seconds / 1.8808158;
                break;
        case 4: return e_seconds / 11.862615;
                break;
        case 5: return e_seconds /29.447498;
                break;
        case 6: return e_seconds / 84.016846;
                break;
        case 7: return e_seconds / 164.79132;
                break;
        default: break;
    }
    return -1;
}
