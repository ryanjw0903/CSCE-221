//
// Created by ryanj on 1/15/2020.
//
#include "Stress_ball.h"
#include <cstdlib>
Stress_ball :: Stress_ball() {
    color = Stress_ball_colors(rand()%4);
    size = Stress_ball_sizes(rand()%3);
}
Stress_ball_colors Stress_ball :: get_color() const{
    return color;
}
Stress_ball_sizes Stress_ball :: get_size() const{
    return size;
}
Stress_ball:: Stress_ball(Stress_ball_colors c, Stress_ball_sizes s){
    color = c;
    size = s;
}
bool Stress_ball :: operator==(const Stress_ball& sb){
    return this->color == sb.color && this->size == sb.size;
}
ostream& operator<<(ostream& os, const Stress_ball& sb){
    os << "(" ;
    switch(sb.get_color()){
        case Stress_ball_colors::red:
            os << "red"; break;
        case Stress_ball_colors::blue:
            os << "blue"; break;
        case Stress_ball_colors::yellow:
            os << "yellow"; break;
        case Stress_ball_colors::green:
            os << "green"; break;
    }
    os << ", ";
    switch(sb.get_size()){
        case Stress_ball_sizes::small:
            os << "small"; break;
        case Stress_ball_sizes::medium:
            os << "medium"; break;
        case Stress_ball_sizes::large:
            os << "large"; break;

    }
    os << ")";
    return os;
}