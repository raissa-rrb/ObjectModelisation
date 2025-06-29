#include "Cell.h"
#include "Term.h"
#include "Point.h"
#include "Instance.h"

namespace Netlist {

    Instance::Instance ( Cell* owner, Cell* model, const std::string& name ) 
                        : owner_(owner), masterCell_(model), name_(name)             
    {
        //the instance has to be added to Cell's instances_ list
        owner->add(this);

        //duplicate the mastercell's terms_ list
        std::vector<Term*>::const_iterator iTerm = model->getTerms().begin();
        for(; iTerm < model->getTerms().end() ; iTerm++ )
        {
            Term * newTerm = new Term(this, (*iTerm) );
            add(newTerm);
        }
    }

    Instance::~Instance () {}

    const   std::string&        Instance::getName         () const 
    { return name_; }

    Cell*                       Instance::getMasterCell   () const 
    { return masterCell_; }

    Cell*                       Instance::getCell         () const 
    { return owner_;}

    const std::vector<Term*>&   Instance::getTerms        () const 
    { return terms_; }

    Term*                       Instance::getTerm         ( const std::string& name) const 
    {
        std::vector<Term*>::const_iterator iTerms = terms_.begin();
        for(; iTerms < terms_.end() ; iTerms ++)
        {
            
            if( (*iTerms)->getName() == name )
                return *iTerms;
        }
        return NULL;
    }
    
    Point                       Instance::getPosition     () const 
    {
        return position_;
    }

    /*  connect() associates the net to the terminal name 'name', if it exists */
    bool                        Instance::connect         ( const std::string& name, Net*  net) 
    {
        Term* term = getTerm(name);
        if(term) //if term exists
        {
            term->setNet(net);
            return true;
        }
        else 
            return false;
    }


    void                        Instance::add             ( Term* term) 
    {
        terms_.push_back(term);
    }

    void                        Instance::remove          ( Term* ) {}
    void                        Instance::setPosition     ( const Point& ) {}
    void                        Instance::setPosition     ( int x, int y ) {}

    void                Instance::toXml              (std::ostream& o) const 
    {
        o << indent <<  "<instance name=\"" << name_ 
        << "\" mastercell =\"" << getMasterCell()->getName() 
        << "\" x=\"" << getPosition().getX() << "\" y=\"" << getPosition().getY() << "\"/>" << std::endl; 
    
    }

}