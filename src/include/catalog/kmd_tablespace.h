/*-------------------------------------------------------------------------
 *
 * kmd_tablespace.h
 *	  definition of the "tablespace" system catalog (kmd_tablespace)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_tablespace.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_TABLESPACE_H
#define PG_TABLESPACE_H

#include "catalog/genbki.h"
#include "catalog/kmd_tablespace_d.h"

/* ----------------
 *		kmd_tablespace definition.  cpp turns this into
 *		typedef struct FormData_kmd_tablespace
 * ----------------
 */
CATALOG(kmd_tablespace,1213,TableSpaceRelationId) BKI_SHARED_RELATION
{
	Oid			oid;			/* oid */
	NameData	spcname;		/* tablespace name */
	Oid			spcowner;		/* owner of tablespace */

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	aclitem		spcacl[1];		/* access permissions */
	text		spcoptions[1];	/* per-tablespace options */
#endif
} FormData_kmd_tablespace;

/* ----------------
 *		Form_kmd_tablespace corresponds to a pointer to a tuple with
 *		the format of kmd_tablespace relation.
 * ----------------
 */
typedef FormData_kmd_tablespace *Form_kmd_tablespace;

#endif							/* PG_TABLESPACE_H */
