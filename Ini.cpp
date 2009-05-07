/*-----------------------------------------------------------------------------

  Ini.cpp

  2009 Shamus Young


-------------------------------------------------------------------------------
  
  This takes various types of data and dumps them into a predefined ini file.

-----------------------------------------------------------------------------*/

#define FORMAT_VECTOR       "%f %f %f"
#define MAX_RESULT          256
#define FORMAT_FLOAT        "%1.2f"
#define INI_FILE            ".\\" APP ".ini"
#define SECTION             "Settings"

#include <cstdio>
#include <cstdlib>

#include "glTypes.h"
#include "Ini.h"
#include "Win.h"

static char                 result[MAX_RESULT];

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

int IniInt (const std::string & entry)
{

  int         result;

  //result = GetPrivateProfileInt (SECTION, entry, 0, INI_FILE);
  return result;

}

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

void IniIntSet (const std::string & entry, int val)
{

  char        buf[20];

  sprintf (buf, "%d", val);
  //WritePrivateProfileString (SECTION, entry, buf, INI_FILE);

}

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

float IniFloat (const std::string & entry)
{

  float     f;

  //GetPrivateProfileString (SECTION, entry, "", result, MAX_RESULT, INI_FILE);
  f = (float)atof (result);
  return f;

}

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

void IniFloatSet (const std::string & entry, float val)
{

  char        buf[20];
  
  sprintf (buf, FORMAT_FLOAT, val);
  //WritePrivateProfileString (SECTION, entry, buf, INI_FILE);

}


/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

std::string IniString (const std::string & entry)
{

  //GetPrivateProfileString (SECTION, entry, "", result, MAX_RESULT, INI_FILE);
  return result;

}

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

void IniStringSet (const std::string & entry, char* val)
{

  //WritePrivateProfileString (SECTION, entry, val, INI_FILE);

}


/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

void IniVectorSet (const std::string & entry, GLvector v)
{
  
  sprintf (result, FORMAT_VECTOR, v.x, v.y, v.z);
  //WritePrivateProfileString (SECTION, entry, result, INI_FILE);

}

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

GLvector IniVector (const std::string & entry)
{

  GLvector  v;

  v.x = v.y = v.z = 0.0f;
  //GetPrivateProfileString (SECTION, entry, "0 0 0", result, MAX_RESULT, INI_FILE);
  sscanf (result, FORMAT_VECTOR, &v.x, &v.y, &v.z);
  return v;

}
