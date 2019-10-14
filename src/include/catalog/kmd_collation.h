/*-------------------------------------------------------------------------
 *
 * kmd_collation.h
 *	  definition of the "collation" system catalog (kmd_collation)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_collation.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_COLLATION_H
#define PG_COLLATION_H

#include "catalog/genbki.h"
#include "catalog/kmd_collation_d.h"

/* ----------------
 *		kmd_collation definition.  cpp turns this into
 *		typedef struct FormData_kmd_collation
 * ----------------
 */
CATALOG(kmd_collation,3456,CollationRelationId)
{
	Oid			oid;			/* oid */
	NameData	collname;		/* collation name */
	Oid			collnamespace;	/* OID of namespace containing collation */
	Oid			collowner;		/* owner of collation */
	char		collprovider;	/* see constants below */
	bool		collisdeterministic BKI_DEFAULT(t);
	int32		collencoding;	/* encoding for this collation; -1 = "all" */
	NameData	collcollate;	/* LC_COLLATE setting */
	NameData	collctype;		/* LC_CTYPE setting */
#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	text		collversion;	/* provider-dependent version of collation
								 * data */
#endif
} FormData_kmd_collation;

/* ----------------
 *		Form_kmd_collation corresponds to a pointer to a row with
 *		the format of kmd_collation relation.
 * ----------------
 */
typedef FormData_kmd_collation *Form_kmd_collation;

#ifdef EXPOSE_TO_CLIENT_CODE

#define COLLPROVIDER_DEFAULT	'd'
#define COLLPROVIDER_ICU		'i'
#define COLLPROVIDER_LIBC		'c'

#endif							/* EXPOSE_TO_CLIENT_CODE */


extern Oid	CollationCreate(const char *collname, Oid collnamespace,
							Oid collowner,
							char collprovider,
							bool collisdeterministic,
							int32 collencoding,
							const char *collcollate, const char *collctype,
							const char *collversion,
							bool if_not_exists,
							bool quiet);
extern void RemoveCollationById(Oid collationOid);

#endif							/* PG_COLLATION_H */
