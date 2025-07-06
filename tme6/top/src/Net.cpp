#include "Node.h"
#include "Cell.h"
#include "Term.h"

#include "Net.h"

namespace Netlist {

    Net::Net    ( Cell* owner, const std::string& name, Term::Type type):
                owner_(owner), name_(name), type_(type), nodes_()
    {
        //the net has to be added to Cell's nets_ list
        owner->add(this);
    }
    Net::~Net    (){}

    Cell*                       Net::getCell         () const
    { return owner_; }

    const std::string&          Net::getName         () const
    { return name_; }

    unsigned int                Net::getId           () const
    { return id_; }

    Term::Type                  Net::getType         () const
    { return type_; }

    const std::vector<Node*>&   Net::getNodes        () const
    { return nodes_; }

    size_t                      Net::getFreeNodeId   () const
    {
        //parses nodes_ and returns the first free index else the list's size
        for(int i = 0; i < nodes_.size(); i++)
        {
            if(nodes_[i] == NULL)
                return i;
        }
        return nodes_.size();
    }

    /* reminder:
        A node's id is its index in net's nodes_ vector
        It's index equals Node::noid until it's associated to a net

        It has been decided that it's Net::add(Node) that manages pointers updates and nodes' indexes

        Before being put into nodes_, a node can either have an index that indicates the emplacement it wants to have
        or no id which means it'll be put into the first free case
    */
    void                        Net::add             ( Node * node )
    {
        //check if the node has an id3
        size_t nodeId = node->getId();

        if( nodeId != Node::noid)
        {   
            //check if the wanted id is free
            if(nodes_[nodeId] == NULL)
            {
                nodes_[nodeId] = node;
            }
        } 
        else {
            /* either the node has noId or the wanted index is taken
            in that case the node is put into the firstfreeinex or the end
            */   
            size_t newNodeId = getFreeNodeId();
            node->setId(newNodeId);

            if(newNodeId < nodes_.size())
                nodes_[newNodeId] = node;
            else 
                nodes_.push_back(node);

        }

    }

    bool                        Net::remove          ( Node* ){}

    void                Net::toXml              (std::ostream& o ) const 
    {
        o << indent << "<net name=\"" << name_ 
        << "\" type=\"" << Term::toString(type_) << "\"/>" << std::endl; 

        ++indent;
        //std::cout << nodes_.size() << std::endl;
        for (Node* n : nodes_)
            n->toXml(o);
        --indent;
        o << indent << "</net>" << std::endl;
        
    
    }




}
