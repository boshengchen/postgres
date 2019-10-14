/*-------------------------------------------------------------------------
 *
 * kmd_attrdef.h
 *	  definition of the "attribute defaults" system catalog (kmd_attrdef)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_attrdef.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_ATTRDEF_H
#define PG_ATTRDEF_H

#include "catalog/genbki.h"
#include "catalog/kmd_attrdef_d.h"

/* ----------------
 *		kmd_attrdef definition.  cpp turns this into
 *		typedef struct FormData_kmd_attrdef
 * ----------------
 */
CATALOG(kmd_attrdef,2604,AttrDefaultRelationId)
{
	Oid			oid;			/* oid */

	Oid			adrelid;		/* OID of table containing attribute */
	int16		adnum;			/* attnum of attribute */

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	pg_node_tree adbin BKI_FORCE_NOT_NULL;	/* nodeToString representation of
											 * default */
#endif
} FormData_kmd_attrdef;

/* ----------------
 *		Form_kmd_attrdef corresponds to a pointer to a tuple with
 *		the format of kmd_attrdef relation.
 * ----------------
 */
typedef FormData_kmd_attrdef *Form_kmd_attrdef;

#endif							/* PG_ATTRDEF_H */
