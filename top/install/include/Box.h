#include <string>
#include <iostream>

class Box{
    public: 
        //Ctor
                        Box();
                        Box(const std::string, long x1, long y1, long x2, long y2);
                        Box(const Box&);
        //Dtor
                        ~Box();
        //Accessors
        std::string getName();
        long        getX1();
        long        getX2();
        long        getY1();
        long        getY2();
        long        getWidth();
        long        getHeight();
        bool        isEmpty() const;
        bool        intersect( const Box&) const;
        void        print(std::ostream&);
        
 //       std::ostream& operator<<(std::ostream& o, const Box& b){
 //           o  << "Box: " << name_ << "x1 : " << x1_ << "y1 : " << y1_
 //   << "x2: " << x2_ << "y2 : " << y2_ << endl; 
 //           return o;
 //       }
        
        //Mutators
        void        makeEmpty();
        Box&        inflate(long dxy);
        Box&        inflate(long dx, long dy);
        Box&        inflate(long dx1, long dy1, long dx2, long dy2);
        Box         getIntersection(const Box&) const;
        


    private : 
        std::string name_;
        long x1_, x2_, y1_, y2_;

};