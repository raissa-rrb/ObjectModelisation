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
                owner_(owner), name_(name),direction_(direction), net_(nullptr), node_(this, Node::noid), type_(External)                      
    {
		// the term has to be added to the Cell's terms list
        owner->add(this);
    }

    /*in the case of an instance terminal, the instance's model's term has to be duplicated*/
    Term::Term    ( Instance* instance, const Term* modelTerm) : 
                    owner_(instance), name_(modelTerm->getName()), direction_(modelTerm->getDirection())
                    , net_(modelTerm->getNet()), node_(this, Node::noid), type_(Internal)
    {
        // the term has to be added to the instance's terms list
        instance->add(this);
    }

    Term::~Term   (){}

    std::string                         Term::toString        (Type type)
    {
        return (type == External) ? "External" : "Internal";
    }
    std::string                         Term::toString        (Term::Direction direction)  
    {
        switch (direction)
        {
        case 1:
            return "In";
                    
        case 2:
            return "Out";
            
        case 3:
            return "Inout";
                    
        case 4:
            return "Tristate";
        
        case 5 :
            return "Transc";
                    
        default :
            return "Unknown";
        
        }
    }
    Term::Direction                     Term::toDirection     (std::string){}

     
    Cell*                       Term::getOwnerCell    () const
    { return (type_ == External) ? static_cast<Cell*>(owner_) : static_cast<Instance*>(owner_)->getCell();}
     
    void                        Term::setNet          ( Net* net)              
    {
        if(!net && net_)
            net_ = NULL;
            else {
                net_ = net;
                                                                             
                net->add(&node_);
            }
    }
 
	void                        Term::setNet          ( const std::string& name)
    {
        setNet(getOwnerCell()->getNet(name));
               
    }

    void                        Term::setPosition     ( const Point& )      {}
    void                        Term::setPosition     ( int x, int y )      {}

    void                Term::toXml              (std::ostream& o) const 
    {
        if(isExternal()) 
        {
            o << indent <<  "<term name=\"" << name_ 
            << "\" direction=\"" << toString(direction_) << "\"/>" << std::endl;
        }
        else
        {
            o  << "\" instance=\"" << getInstance()->getName();
        } 
    }

}

