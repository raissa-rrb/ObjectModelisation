#ifndef TERM_H
#define TERM_H

#include <string>
#include "Point.h"
#include "Node.h"

namespace Netlist {


    class Net;
    class Node;
    class Cell;
    class Instance;

    class Term{
        
    

        public:

        enum Type       { Internal=1, External=2};
        enum Direction  { In=1, Out=2, Inout=3, Tristate=4, Transc=5, Unknown=6};

        Term    ( Cell*, const std::string& name, Direction);
        Term    ( Instance*, const Term* modelTerm);
        ~Term   ();

        static std::string              toString        (Type);
        static std::string              toString        (Direction);
        static Direction                toDriection     (std::string);

        inline  bool                    isInternal      () const;
        inline  bool                    isExternal      () const;
        inline  const std::string&      getName         () const;        
        inline  Node*                   getNode         () ;
        inline  Net*                    getNet          () const;
        inline  Cell*                   getCell         () const;
                Cell*                   getOwnerCell    () const;
        inline  Instance*               getInstance     () const;
        inline  Direction               getDirection    () const;
        inline  Point                   getPosition     () const;
        inline  Type                    getType         () const;

                void                    setNet          ( Net* );
                void                    setNet          ( const std::string& );
        inline  void                    setDirection    ( Direction );
                void                    setPosition     ( const Point& );
                void                    setPosition     ( int x, int y );



        private:

                void*                   owner_;
                std::string             name_;
                Direction               direction_;
                Type                    type_;
                Net*                    net_;
                Node                    node_;

    };
}

#endif  //TERM_H