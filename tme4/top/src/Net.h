#ifndef NET_H
#define NET_H

#include <string>
#include <vector>
#include "Term.h"


namespace Netlist {

    class Cell;
    class Node;

    class Net {
    public:

     Net    ( Cell*, const std::string&, Term::Type );
    ~Net    ();

    Cell*                       getCell         () const;
    const std::string&          getName         () const;
    unsigned int                getId           () const;
    Term::Type                        getType         () const;
    const std::vector<Node*>&   getNodes        () const;
    size_t                      getFreeNodeId   () const;

    void                        add             ( Node * );
    bool                        remove          ( Node* );

    private:

    Cell*                       owner_;
    std::string                 name_;
    unsigned int                id_;
    Term::Type                  type_;
    std::vector<Node*>          nodes_;
    };
}

#endif  //NET_H