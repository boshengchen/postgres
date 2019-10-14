/*-------------------------------------------------------------------------
 *
 * kmd_transform.h
 *	  definition of the "transform" system catalog (kmd_transform)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_transform.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_TRANSFORM_H
#define PG_TRANSFORM_H

#include "catalog/genbki.h"
#include "catalog/kmd_transform_d.h"

/* ----------------
 *		kmd_transform definition.  cpp turns this into
 *		typedef struct FormData_kmd_transform
 * ----------------
 */
CATALOG(kmd_transform,3576,TransformRelationId)
{
	Oid			oid;			/* oid */
	Oid			trftype;
	Oid			trflang;
	regproc		trffromsql;
	regproc		trftosql;
} FormData_kmd_transform;

/* ----------------
 *		Form_kmd_transform corresponds to a pointer to a tuple with
 *		the format of kmd_transform relation.
 * ----------------
 */
typedef FormData_kmd_transform *Form_kmd_transform;

#endif							/* PG_TRANSFORM_H */
