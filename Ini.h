#include <string>

int       IniInt (const std::string & entry);
void      IniIntSet (const std::string & entry, int val);
float     IniFloat (const std::string & entry);
void      IniFloatSet (const std::string & entry, float val);
std::string IniString (const std::string & entry);
void      IniStringSet (const std::string & entry, const std::string & val);
void      IniVectorSet (const std::string & entry, GLvector v);
GLvector  IniVector (const std::string & entry);
