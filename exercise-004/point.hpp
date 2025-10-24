#ifndef Point_HPP
#define Point_HPP

class Point
{
public:
    Point();
    Point(int x, int y);

    void move (int dx, int dy);

    void print() const;

    double distance_to(const Point &other) const;

private:
int m_y;
int m_x;

};

#endif // Point_HPP