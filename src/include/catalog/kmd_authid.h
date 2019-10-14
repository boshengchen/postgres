/*-------------------------------------------------------------------------
 *
 * kmd_authid.h
 *	  definition of the "authorization identifier" system catalog (kmd_authid)
 *
 *	  kmd_shadow and kmd_group are now publicly accessible views on kmd_authid.
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_authid.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_AUTHID_H
#define PG_AUTHID_H

#include "catalog/genbki.h"
#include "catalog/kmd_authid_d.h"

/* ----------------
 *		kmd_authid definition.  cpp turns this into
 *		typedef struct FormData_kmd_authid
 * ----------------
 */
CATALOG(kmd_authid,1260,AuthIdRelationId) BKI_SHARED_RELATION BKI_ROWTYPE_OID(2842,AuthIdRelation_Rowtype_Id) BKI_SCHEMA_MACRO
{
	Oid			oid;			/* oid */
	NameData	rolname;		/* name of role */
	bool		rolsuper;		/* read this field via superuser() only! */
	bool		rolinherit;		/* inherit privileges from other roles? */
	bool		rolcreaterole;	/* allowed to create more roles? */
	bool		rolcreatedb;	/* allowed to create databases? */
	bool		rolcanlogin;	/* allowed to log in as session user? */
	bool		rolreplication; /* role used for streaming replication */
	bool		rolbypassrls;	/* bypasses row level security? */
	int32		rolconnlimit;	/* max connections allowed (-1=no limit) */

	/* remaining fields may be null; use heap_getattr to read them! */
#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	text		rolpassword;	/* password, if any */
	timestamptz rolvaliduntil;	/* password expiration time, if any */
#endif
} FormData_kmd_authid;

/* ----------------
 *		Form_kmd_authid corresponds to a pointer to a tuple with
 *		the format of kmd_authid relation.
 * ----------------
 */
typedef FormData_kmd_authid *Form_kmd_authid;

#endif							/* PG_AUTHID_H */
