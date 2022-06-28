# Red book
OOP project by Antonio Georgiev (group 3), Bozhidar Kyorov (group 6), Tsvetelina Tsvetanova (group 3).

This is an application that is used to collect and represent data about the threatened species. There is a base class called Organism, three derived classes (the three kingdoms) - Flora, Fauna, Fungi, and a heterogeneous container - Red Book.

# Documentation
**Organism - base class**<br/>
attributes:
* species name - string
* lifespan - double
* habitats - vector containing strings (habitats' names)
* conservation level - integer from 0 to 6
* levels - static const array of strings from 0 to 6 that contains the name of each level
* lastLevelChange - time_t variable

methods:
* constructor with and without parameters
* virtual default destructor
* pure virtual clone function
* setters and getters
* print

**Fauna - derived class**<br/>
attributes:
* isPredator - bool variable

**Flora - derived class**<br/>
Doesn't have any extra attributes yet

**Fungi - derived class**<br/>
attributes:
* isPoisonous - bool variable

**Red book - heterogeneous container**<br/>
attributes:
* list - array of pointers to Organism objects
* size
* capacity

methods:
* big four
* copy
* free
* resize
* print (all and by type/conservation level)
* add
* delete
* getSpeciesIndex - returns the index in the array of a given species or -1 if it doesn't exist
* setConservationLevelByIndex<br/>
More methods can be added<br/>

Custom Vector and String classes are implemented.
