#include "Net.h"
#include "Point.h"
#include "Node.h"
#include "Cell.h"
#include "Instance.h"
#include "Term.h"

/*Important points

- a node is associated to one term only
- a node's id is its index in nodes_, if it's associated to no term at all
then its id is Node::noid
- when a Net is created, it's nodes_ table is empty
- so when a term is created, it's node_ attribut is set to node::noid
which means it's not associated to a net yet

*/

namespace Netlist {


        
        Term::Term    ( Cell* owner, const std::string& name, Term::Direction direction):
                        owner_(owner), name_(name),direction_(direction), net_(nullptr), node_(nullptr)
                        
        {
                
        }
        Term::Term    ( Instance* instance, const Term* modelTerm){}
        Term::~Term   (){}

        std::string                         Term::toString        (Type){}
        std::string                         Term::toString        (Term::Direction)  {}
        Term::Direction                     Term::toDriection     (std::string){}

        inline  bool                        Term::isInternal      () const{}
        inline  bool                        Term::isExternal      () const{}
        inline  const std::string&          Term::getName         () const{}        
        inline  Node*                       Term::getNode         () {}
        inline  Net*                        Term::getNet          () const{}
        inline  Cell*                       Term::getCell         () const{}
                Cell*                       Term::getOwnerCell    () const{}
        inline  Instance*                   Term::getInstance     () const{}
        inline  Term::Direction             Term::getDirection    () const{}
        inline  Point                       Term::getPosition     () const{}
        inline  Term::Type                  Term::getType         () const{}

                void                        Term::setNet          ( Net* )              {}
                void                        Term::setNet          ( const std::string& ){}
        inline  void                        Term::setDirection    ( Direction )         {}
                void                        Term::setPosition     ( const Point& )      {}
                void                        Term::setPosition     ( int x, int y )      {}

}

