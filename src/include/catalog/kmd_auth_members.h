/*-------------------------------------------------------------------------
 *
 * kmd_auth_members.h
 *	  definition of the "authorization identifier members" system catalog
 *	  (kmd_auth_members).
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_auth_members.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_AUTH_MEMBERS_H
#define PG_AUTH_MEMBERS_H

#include "catalog/genbki.h"
#include "catalog/kmd_auth_members_d.h"

/* ----------------
 *		kmd_auth_members definition.  cpp turns this into
 *		typedef struct FormData_kmd_auth_members
 * ----------------
 */
CATALOG(kmd_auth_members,1261,AuthMemRelationId) BKI_SHARED_RELATION BKI_ROWTYPE_OID(2843,AuthMemRelation_Rowtype_Id) BKI_SCHEMA_MACRO
{
	Oid			roleid;			/* ID of a role */
	Oid			member;			/* ID of a member of that role */
	Oid			grantor;		/* who granted the membership */
	bool		admin_option;	/* granted with admin option? */
} FormData_kmd_auth_members;

/* ----------------
 *		Form_kmd_auth_members corresponds to a pointer to a tuple with
 *		the format of kmd_auth_members relation.
 * ----------------
 */
typedef FormData_kmd_auth_members *Form_kmd_auth_members;

#endif							/* PG_AUTH_MEMBERS_H */
