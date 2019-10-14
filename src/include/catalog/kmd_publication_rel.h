/*-------------------------------------------------------------------------
 *
 * kmd_publication_rel.h
 *	  definition of the system catalog for mappings between relations and
 *	  publications (kmd_publication_rel)
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_publication_rel.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_PUBLICATION_REL_H
#define PG_PUBLICATION_REL_H

#include "catalog/genbki.h"
#include "catalog/kmd_publication_rel_d.h"

/* ----------------
 *		kmd_publication_rel definition.  cpp turns this into
 *		typedef struct FormData_kmd_publication_rel
 * ----------------
 */
CATALOG(kmd_publication_rel,6106,PublicationRelRelationId)
{
	Oid			oid;			/* oid */
	Oid			prpubid;		/* Oid of the publication */
	Oid			prrelid;		/* Oid of the relation */
} FormData_kmd_publication_rel;

/* ----------------
 *		Form_kmd_publication_rel corresponds to a pointer to a tuple with
 *		the format of kmd_publication_rel relation.
 * ----------------
 */
typedef FormData_kmd_publication_rel *Form_kmd_publication_rel;

#endif							/* PG_PUBLICATION_REL_H */
