/*-------------------------------------------------------------------------
 *
 * kmd_range.h
 *	  definition of the "range type" system catalog (kmd_range)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_range.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_RANGE_H
#define PG_RANGE_H

#include "catalog/genbki.h"
#include "catalog/kmd_range_d.h"

/* ----------------
 *		kmd_range definition.  cpp turns this into
 *		typedef struct FormData_kmd_range
 * ----------------
 */
CATALOG(kmd_range,3541,RangeRelationId)
{
	/* OID of owning range type */
	Oid			rngtypid BKI_LOOKUP(kmd_type);

	/* OID of range's element type (subtype) */
	Oid			rngsubtype BKI_LOOKUP(kmd_type);

	/* collation for this range type, or 0 */
	Oid			rngcollation BKI_DEFAULT(0);

	/* subtype's btree opclass */
	Oid			rngsubopc BKI_LOOKUP(kmd_opclass);

	/* canonicalize range, or 0 */
	regproc		rngcanonical BKI_LOOKUP(kmd_proc);

	/* subtype difference as a float8, or 0 */
	regproc		rngsubdiff BKI_LOOKUP(kmd_proc);
} FormData_kmd_range;

/* ----------------
 *		Form_kmd_range corresponds to a pointer to a tuple with
 *		the format of kmd_range relation.
 * ----------------
 */
typedef FormData_kmd_range *Form_kmd_range;

/*
 * prototypes for functions in kmd_range.c
 */

extern void RangeCreate(Oid rangeTypeOid, Oid rangeSubType, Oid rangeCollation,
						Oid rangeSubOpclass, RegProcedure rangeCanonical,
						RegProcedure rangeSubDiff);
extern void RangeDelete(Oid rangeTypeOid);

#endif							/* PG_RANGE_H */
