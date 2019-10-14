/*-------------------------------------------------------------------------
 *
 * kmd_largeobject.h
 *	  definition of the "large object" system catalog (kmd_largeobject)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_largeobject.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_LARGEOBJECT_H
#define PG_LARGEOBJECT_H

#include "catalog/genbki.h"
#include "catalog/kmd_largeobject_d.h"

/* ----------------
 *		kmd_largeobject definition.  cpp turns this into
 *		typedef struct FormData_kmd_largeobject
 * ----------------
 */
CATALOG(kmd_largeobject,2613,LargeObjectRelationId)
{
	Oid			loid;			/* Identifier of large object */
	int32		pageno;			/* Page number (starting from 0) */

	/* data has variable length, but we allow direct access; see inv_api.c */
	bytea		data BKI_FORCE_NOT_NULL;	/* Data for page (may be
											 * zero-length) */
} FormData_kmd_largeobject;

/* ----------------
 *		Form_kmd_largeobject corresponds to a pointer to a tuple with
 *		the format of kmd_largeobject relation.
 * ----------------
 */
typedef FormData_kmd_largeobject *Form_kmd_largeobject;

extern Oid	LargeObjectCreate(Oid loid);
extern void LargeObjectDrop(Oid loid);
extern bool LargeObjectExists(Oid loid);

#endif							/* PG_LARGEOBJECT_H */
