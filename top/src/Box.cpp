#include <Box.h>

Box::Box():x1_(1), y1_(1), x2_(0), y2_(0), name_("noname")
{}

Box::Box( const std::string name, long x1, long y1, long x2, long y2)
        : x1_(x1), y1_(y1), x2_(x2), y2_(y2), name_(name)
{}

Box::Box(const Box& other): x1_(other.x1_), y1_(other.y1_)
                            ,x2_(other.x2_), y2_(other.y2_)
                            , name_(other.name_+"_c")
{}

Box::~Box()
{}

std::string Box::getName()
{
    return name_;
}

long Box::getX1()
{
    return x1_;
}

long Box::getX2()
{
    return x2_;
}

long Box::getY1()
{
    return y1_;
}

long Box::getY2()
{
    return y2_;
}

long Box::getWidth()
{
    return (x2_ - x1_);
}

long Box::getHeight()
{
    return (y2_ - y1_);
}

bool Box::isEmpty() const
{
    return (x1_ > x2_);
}

bool Box::intersect(const Box& other) const
{
    if(isEmpty() or other.isEmpty())
        return false;
    if( (x1_ > other.x2_) or (x2_ < other.x1_)
    or  (y2_ < other.y1_) or (y1_> other.y2_) )
        return false;
    return true;
}

void Box::print(std::ostream& o)
{
    o  << "Box: " << name_ << "x1 : " << x1_ << "y1 : " << y1_
    << "x2: " << x2_ << "y2 : " << y2_ << std::endl; 
}

void Box::makeEmpty()
{
    x1_ = 1;
    y1_ = 1;
    x2_ = 0;
    y2_ = 1;
}

Box& Box::inflate(long dxy)
{
    x1_ -= dxy;
    y1_ -= dxy; 
    x2_ += dxy; 
    y2_ += dxy;
    return *this;
}

Box& Box::inflate(long dx, long dy)
{
    x1_ -= dx;
    y1_ -= dy; 
    x2_ += dx; 
    y2_ += dy;
    return *this;
}

Box& Box::inflate(long dx1, long dy1, long dx2, long dy2)
{
    x1_ -= dx1;
    y1_ -= dy1; 
    x2_ += dx2; 
    y2_ += dy2;
    return *this;
}

Box Box::getIntersection(const Box& other) const
{
    if (! intersect(other) )
        return Box();

    std::string newName = name_ + "." + other.name_;
    return Box(newName, std::max(x1_, other.x1_) , std::max(y1_, other.y1_)
                        , std::min(x2_, other.x2_), std::min(y2_, other.y2_));

}
