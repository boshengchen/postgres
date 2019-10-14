/* -------------------------------------------------------------------------
 *
 * kmd_sequence.h
 *	  definition of the "sequence" system catalog (kmd_sequence)
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_sequence.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 * -------------------------------------------------------------------------
 */
#ifndef PG_SEQUENCE_H
#define PG_SEQUENCE_H

#include "catalog/genbki.h"
#include "catalog/kmd_sequence_d.h"

CATALOG(kmd_sequence,2224,SequenceRelationId)
{
	Oid			seqrelid;
	Oid			seqtypid;
	int64		seqstart;
	int64		seqincrement;
	int64		seqmax;
	int64		seqmin;
	int64		seqcache;
	bool		seqcycle;
} FormData_kmd_sequence;

/* ----------------
 *		Form_kmd_sequence corresponds to a pointer to a tuple with
 *		the format of kmd_sequence relation.
 * ----------------
 */
typedef FormData_kmd_sequence *Form_kmd_sequence;

#endif							/* PG_SEQUENCE_H */
