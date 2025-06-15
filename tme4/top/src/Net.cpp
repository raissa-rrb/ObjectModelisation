#include "Node.h"
#include "Cell.h"
#include "Term.h"

#include "Net.h"

namespace Netlist {

    Net::Net    ( Cell* owner, const std::string& name, Term::Type type):
                owner_(owner), name_(name), type_(type), nodes_()
    {}
    Net::~Net    (){}

    Cell*                       Net::getCell         () const{}
    const std::string&          Net::getName         () const{}
    unsigned int                Net::getId           () const{}
    Type                        Net::getType         () const{}
    const std::vector<Node*>&   Net::getNodes        () const{}
    size_t                      Net::getFreeNodeId   () const{}

    void                        Net::add             ( Node * ){}
    bool                        Net::remove          ( Node* ){}




}
