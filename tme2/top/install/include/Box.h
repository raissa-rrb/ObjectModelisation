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
        inline std::string          getName()                       { return name_; }
        inline long                 getX1()                         { return x1_;}
        inline long                 getX2()                         { return x2_;}
        inline long                 getY1()                         { return y1_;}
        inline long                 getY2()                         { return y2_;}
        inline long                 getWidth()                      { return (x2_ - x1_);}
        inline long                 getHeight()                     { return (y2_ - y1_);}
        inline bool                 isEmpty() const                 { return (x1_ > x2_); }
        inline static size_t        getCount()                        { return count;}
        bool                        intersect( const Box&) const;
        void                        print(std::ostream&);
        
        //Mutators
        void                        makeEmpty();
        Box&                        inflate(long dxy);
        Box&                        inflate(long dx, long dy);
        Box&                        inflate(long dx1, long dy1, long dx2, long dy2);
        Box                         getIntersection(const Box&) const;
        


    private : 
        std::string name_;
        long x1_, x2_, y1_, y2_;
        static size_t count;

};