Point::Point() {
    x = 0;
    y = 0;
}
Point::Point(double _x, double _y) {
    x = _x;
    y = _y;
}

Point::Point(const Point& p) {
    x = p.x;
    y = p.y;
}

Triangle::Triangle(const Point& p1, const Point& p2,  const Point& p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}
double Triangle::getPerimeter() const {
    double firstEdge, secondEgde, thirdEdge;
    firstEdge = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    secondEgde = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));   
    thirdEdge = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));

    return firstEdge + secondEgde + thirdEdge;
}
double Triangle::getArea() const {
    double firstEdge, secondEgde, thirdEdge, halfPerimeter;
    firstEdge = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));    
    secondEgde = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
    thirdEdge = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));

    halfPerimeter = (firstEdge + secondEgde + thirdEdge) / 2;

    return sqrt(halfPerimeter * (halfPerimeter - firstEdge) * (halfPerimeter - secondEgde) * (halfPerimeter - thirdEdge));
}
