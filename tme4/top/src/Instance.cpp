#include "Cell.h"
#include "Term.h"
#include "Point.h"
#include "Instance.h"

namespace Netlist {

    Instance::Instance ( Cell* owneer, Cell* model, const std::string& ) {}
    Instance::~Instance () {}

    const   std::string&        Instance::getName         () const {}
    Cell*                       Instance::getMasterCell   () const {}
    Cell*                       Instance::getCell         () const {}
    const std::vector<Term*>&   Instance::getTerms        () const {}
    Term*                       Instance::getTerm         ( const std::string& ) const {}
    Point                       Instance::getPosition     () const {}

    bool                        Instance::connect         ( const std::string& name, Net*) {}
    void                        Instance::add             ( Term* ) {}
    void                        Instance::remove          ( Term* ) {}
    void                        Instance::setPosition     ( const Point& ) {}
    void                        Instance::setPosition     ( int x, int y ) {}

}