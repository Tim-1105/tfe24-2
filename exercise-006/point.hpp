#ifndef Point_HPP
#define Point_HPP
#include <type_traits>
#include <cmath>
#include <fmt/core.h>

template <typename T> 
class Point {
static_assert(std::is_arithmetic<T>::value, "Point <T> must be instantiated with an arithmetic type");

    public:
    T m_x;
    T m_y;

    Point() = default;
    Point(T x, T y) : m_x(x), m_y(y) {}

    void move (T dx, T dy) {
        m_x += dx;
        m_y += dy;
    }

    using distance_type = double;
    auto distance_to(const Point& other) const -> distance_type {
    auto dx = static_cast<distance_type>(m_x) - static_cast<distance_type>(other.m_x);
    auto dy = static_cast<distance_type>(m_y) - static_cast<distance_type>(other.m_y);
    return std::hypot(dx, dy); // Hypnotenuse Function (sqrt(dx*dx + dy*dy))
    }

    bool operator==(const Point& other) const {
        return (m_x == other.m_x) && (m_y == other.m_y);}

    bool operator!=(const Point& other) const {
        return !(*this == other);}

};

template <typename T>
struct fmt::formatter<Point<T>> : fmt::formatter<std::string_view> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(const Point<T>& p, FormatContext& ctx) const {
        return fmt::format_to(ctx.out(), "({}, {})", p.m_x, p.m_y);
    }
};

#endif // Point_HPP