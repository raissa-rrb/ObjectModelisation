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
        static Direction                toDirection     (std::string);

        inline  bool                    isInternal      () const { return type_ == Internal; }
        inline  bool                    isExternal      () const { return type_ == External; }
        inline  const std::string&      getName         () const { return name_; }      
        inline  Node*                   getNode         ()       { return &node_; }
        inline  Net*                    getNet          () const { return net_; }
        inline  Cell*                   getCell         () const { return (type_ == External) ? static_cast<Cell*>(owner_) : NULL;}
                Cell*                   getOwnerCell    () const;
        inline  Instance*               getInstance     () const { return static_cast<Instance*>(owner_); }
        inline  Direction               getDirection    () const { return direction_; }
        inline  Point                   getPosition     () const {}
        inline  Type                    getType         () const { return type_; }

                void                    setNet          ( Net* );
                void                    setNet          ( const std::string& );
        inline  void                    setDirection    ( Direction d) { direction_ = d; }
                void                    setPosition     ( const Point& );
                void                    setPosition     ( int x, int y );

                void                toXml              (std::ostream&) const;

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