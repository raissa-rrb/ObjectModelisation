// -*- explicit-buffer-name: "Node.cpp<M1-MOBJ/4-5>" -*-

#include  <limits>
#include  "Node.h"
#include  "Term.h"
#include  "Net.h"
#include  "Instance.h"
#include  "Cell.h"

namespace Netlist {

  using namespace std;


  const size_t  Node::noid = numeric_limits<size_t>::max();


  Node::Node ( Term* term, size_t id  )
    : id_      (id)
    , term_    (term)
    , position_()
  { }


  Node::~Node ()
  {
    if (getNet()) getNet()->remove( this );
  }


  inline Net* Node::getNet () const { return term_->getNet(); }

  void                Node::toXml              (std::ostream& o) const
  {

    o << indent << "<node term=\"" << term_->getName()   ;  
    if(term_->isInternal())
      term_->toXml(o) ; 
    o <<  "\" id=\"" << id_ 
    <<"\" x=\"" << position_.getX() << "\" y=\"" << position_.getY() << "\"/>" << std::endl;
  
  }

// Node::toXml() Ã  Ã©crire ici.


}  // Netlist namespace.
