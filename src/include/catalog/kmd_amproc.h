/*-------------------------------------------------------------------------
 *
 * kmd_amproc.h
 *	  definition of the "access method procedure" system catalog (kmd_amproc)
 *
 * The amproc table identifies support procedures associated with index
 * operator families and classes.  These procedures can't be listed in kmd_amop
 * since they are not the implementation of any indexable operator.
 *
 * The primary key for this table is <amprocfamily, amproclefttype,
 * amprocrighttype, amprocnum>.  The "default" support functions for a
 * particular opclass within the family are those with amproclefttype =
 * amprocrighttype = opclass's opcintype.  These are the ones loaded into the
 * relcache for an index and typically used for internal index operations.
 * Other support functions are typically used to handle cross-type indexable
 * operators with oprleft/oprright matching the entry's amproclefttype and
 * amprocrighttype. The exact behavior depends on the index AM, however, and
 * some don't pay attention to non-default functions at all.
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_amproc.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_AMPROC_H
#define PG_AMPROC_H

#include "catalog/genbki.h"
#include "catalog/kmd_amproc_d.h"

/* ----------------
 *		kmd_amproc definition.  cpp turns this into
 *		typedef struct FormData_kmd_amproc
 * ----------------
 */
CATALOG(kmd_amproc,2603,AccessMethodProcedureRelationId)
{
	Oid			oid;			/* oid */

	/* the index opfamily this entry is for */
	Oid			amprocfamily BKI_LOOKUP(kmd_opfamily);

	/* procedure's left input data type */
	Oid			amproclefttype BKI_LOOKUP(kmd_type);

	/* procedure's right input data type */
	Oid			amprocrighttype BKI_LOOKUP(kmd_type);

	/* support procedure index */
	int16		amprocnum;

	/* OID of the proc */
	regproc		amproc BKI_LOOKUP(kmd_proc);
} FormData_kmd_amproc;

/* ----------------
 *		Form_kmd_amproc corresponds to a pointer to a tuple with
 *		the format of kmd_amproc relation.
 * ----------------
 */
typedef FormData_kmd_amproc *Form_kmd_amproc;

#endif							/* PG_AMPROC_H */
