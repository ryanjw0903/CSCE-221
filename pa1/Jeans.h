//
// Created by ryanj on 2/13/2020.
//

#ifndef PA1_JEANS_H
#define PA1_JEANS_H

#include <iostream>
using namespace std;
enum class Jeans_colors{red, blue, yellow, green};
enum class Jeans_sizes{small,medium,large};
class Jeans{
public:
    Jeans();
    Jeans(Jeans_colors c, Jeans_sizes s);
    Jeans_colors get_color() const;
    Jeans_sizes get_size() const;
    bool operator==(const Jeans& sb);
private:
    Jeans_colors color;
    Jeans_sizes  size;
};

ostream& operator<<(ostream& os, const Jeans& sb);


#endif //PA1_JEANS_H
