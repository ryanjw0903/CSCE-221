//
// Created by ryanj on 2/13/2020.
//

#include "Jeans.h"
#include <cstdlib>
Jeans:: Jeans() {
    color = Jeans_colors(rand()%4);
    size = Jeans_sizes(rand()%3);
}
Jeans_colors Jeans :: get_color() const{
    return color;
}
Jeans_sizes Jeans :: get_size() const{
    return size;
}
Jeans:: Jeans(Jeans_colors c, Jeans_sizes s){
    color = c;
    size = s;
}
bool Jeans :: operator==(const Jeans& sb){
    return this->color == sb.color && this->size == sb.size;
}
ostream& operator<<(ostream& os, const Jeans& sb){
    os << "(" ;
    switch(sb.get_color()){
        case Jeans_colors::red:
            os << "red"; break;
        case Jeans_colors::blue:
            os << "blue"; break;
        case Jeans_colors::yellow:
            os << "yellow"; break;
        case Jeans_colors::green:
            os << "green"; break;
    }
    os << ", ";
    switch(sb.get_size()){
        case Jeans_sizes::small:
            os << "small"; break;
        case Jeans_sizes::medium:
            os << "medium"; break;
        case Jeans_sizes::large:
            os << "large"; break;

    }
    os << ")";
    return os;
}