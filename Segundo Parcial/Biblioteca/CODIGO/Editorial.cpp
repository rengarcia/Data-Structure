/***********************************************************************
 * Module:  Editorial.cpp
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Implementation of the class Editorial
 ***********************************************************************/

#include "Editorial.h"

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::Editorial()
// Purpose:    Implementation of Editorial::Editorial()
// Return:     
////////////////////////////////////////////////////////////////////////

Editorial::Editorial()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::~Editorial()
// Purpose:    Implementation of Editorial::~Editorial()
// Return:     
////////////////////////////////////////////////////////////////////////

Editorial::~Editorial()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::getIdEditorial()
// Purpose:    Implementation of Editorial::getIdEditorial()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Editorial::getIdEditorial(void)
{
   return idEditorial;
}

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::setIdEditorial(int newIdEditorial)
// Purpose:    Implementation of Editorial::setIdEditorial()
// Parameters:
// - newIdEditorial
// Return:     void
////////////////////////////////////////////////////////////////////////

void Editorial::setIdEditorial(int newIdEditorial)
{
   idEditorial = newIdEditorial;
}

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::getNombreEditorial()
// Purpose:    Implementation of Editorial::getNombreEditorial()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Editorial::getNombreEditorial(void)
{
   return nombreEditorial;
}

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::setNombreEditorial(std::string newNombreEditorial)
// Purpose:    Implementation of Editorial::setNombreEditorial()
// Parameters:
// - newNombreEditorial
// Return:     void
////////////////////////////////////////////////////////////////////////

void Editorial::setNombreEditorial(std::string newNombreEditorial)
{
   nombreEditorial = newNombreEditorial;
}

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::getContactoEditorial()
// Purpose:    Implementation of Editorial::getContactoEditorial()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Editorial::getContactoEditorial(void)
{
   return contactoEditorial;
}

////////////////////////////////////////////////////////////////////////
// Name:       Editorial::setContactoEditorial(std::string newContactoEditorial)
// Purpose:    Implementation of Editorial::setContactoEditorial()
// Parameters:
// - newContactoEditorial
// Return:     void
////////////////////////////////////////////////////////////////////////

void Editorial::setContactoEditorial(std::string newContactoEditorial)
{
   contactoEditorial = newContactoEditorial;
}