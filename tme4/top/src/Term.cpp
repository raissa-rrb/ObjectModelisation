#include "Net.h"
#include "Point.h"
#include "Node.h"
#include "Cell.h"
#include "Instance.h"
#include "Term.h"

namespace Netlist {
    
    Term::Term    ( Cell*, const std::string& name, Term::Direction){}
    Term::Term    ( Instance*, const Term* modelTerm){}
    Term::~Term   (){}

    std::string              Term::toString        (Type){}
    std::string              Term::toString        (Term::Direction)  {}
    Term::Direction                Term::toDriection     (std::string){}

    inline  bool                    Term::isInternal      () const{}
    inline  bool                    Term::isExternal      () const{}
    inline  const std::string&      Term::getName         () const{}        
    inline  Node*                   Term::getNode         () {}
    inline  Net*                    Term::getNet          () const{}
    inline  Cell*                   Term::getCell         () const{}
            Cell*                   Term::getOwnerCell    () const{}
    inline  Instance*               Term::getInstance     () const{}
    inline  Term::Direction               Term::getDirection    () const{}
    inline  Point                   Term::getPosition     () const{}
    inline  Term::Type                    Term::getType         () const{}

            void                    Term::setNet          ( Net* )              {}
            void                    Term::setNet          ( const std::string& ){}
    inline  void                    Term::setDirection    ( Direction )         {}
            void                    Term::setPosition     ( const Point& )      {}
            void                    Term::setPosition     ( int x, int y )      {}

}

